#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,a[505][505],dist[505][505];

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	bool vis[n];
	REP(i,n) REP(j,n){
		vis[i] = false;
		cin >> a[i][j];
		dist[i][j]=a[i][j];
	}
	int x[n],ans[n];
	REP(i,n) cin >> x[i];
	REPD(i,n-1){
		int cur = 0;
		vis[x[i]-1] = true;
		REP(u,n){
			REP(v,n){
				remin(dist[u][v],dist[u][x[i]-1]+dist[x[i]-1][v]);
				// cout << dist[u][v] << " "
				if(vis[u] and vis[v]) cur += dist[u][v];
			}
			// cout << "\n";
		}	
		ans[i] = cur;
	}
	REP(i,n) cout << ans[i] << " ";
}