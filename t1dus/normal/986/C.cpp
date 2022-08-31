/*input
5 5
5 19 10 20 12

*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

const int MX = (1<<22);

int n,m;
bitset<MX> a;
bitset<MX> vis[2];

void dfs(int i,int j){
	vis[i][j] = 1;
	if(i == 0){
		if(!vis[1][j]) dfs(1,j);
	}
	else{
		if(a[(1<<n)-1-j] and (!vis[0][(1<<n)-1-j])) dfs(0,(1<<n)-1-j);
		REP(k,n){
			if(!((1<<k)&j)){
				if(!vis[1][j|(1<<k)]) dfs(1,j|(1<<k));
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	REP(i,m){
		int x; cin >> x;
		a[x] = 1;
	}
	int ans = 0;
	REP(i,(1<<n)){
		if(a[i] and (!vis[0][i])){
			dfs(0,i);
			ans ++;
		}
	}
	cout << ans << endl;
}