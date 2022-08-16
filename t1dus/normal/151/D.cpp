/*input
8 13 9
*/		
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

int n,m,k;
int p[2005],sz[2005];

int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unio(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;
	p[x] = y; 
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	FOR(i,1,n+1) p[i] = i;

	FOR(i,1,n+1){
		FOR(j,1,k+1){
			int u = i+k+1-2*j;
			if(u < 1 or u > n or i-j+1 < 1 or i+k-j > n) continue;
			// cout << i << " " << u << endl;
			unio(i,u);
		}
	}	
	int ans = 1;
	FOR(i,1,n+1){
		if(find(i)==i) ans = (ans*m)%MOD;
	}
	cout << ans;
}