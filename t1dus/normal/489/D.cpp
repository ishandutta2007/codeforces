#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
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

vi adj[3005];
bool mat[3005][3005];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	REP(i,m){
	    int x,y;
	    cin >> x >> y;
	    x --;
	    y --;
	    adj[x].pb(y);
	    mat[x][y] = 1;
	}
	ll ans = 0;
	REP(i,n){
	    REP(j,n){
	        if (i == j) continue;
	        //a = i,c = j, now we need to cnt the number of possibilities for b and d 
	        ll cnt = 0;
	        REP(k,adj[i].size()){
	            int u = adj[i][k];
	            if (u != i and u != j and mat[u][j]) cnt ++;
	        }
	        ans += ((cnt)*(cnt-1))/2;
	    }
	}
	cout << ans << endl;
	
}