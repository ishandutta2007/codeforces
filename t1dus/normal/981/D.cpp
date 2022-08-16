/*input
1 1
10000000000000
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
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

int power(int a,int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2);
	x = (x*x);
	if(b%2) return (x*a);
	return x;
}

int n,k,a[55],dp[55][55],cur = 0;

bool pos(int x){
	int lol = cur+power(2,x);
	REP(i,55) REP(j,55) dp[i][j] = 0;
	dp[0][0] = 1;
	FOR(i,1,n+1){
		FOR(j,1,k+1){
			int sm = 0;
			for(int l = i; l >= 1; l --){
				sm += a[l];
				if((sm&lol) == lol){
					if(dp[l-1][j-1]){
						dp[i][j] = 1;
						break;
					}
				}
			}
		}
	}
	return dp[n][k];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	REP(i,n) cin >> a[i+1];
	for(int i = 55; i >= 0; i --){
		if(pos(i)) cur += power(2,i);
	}
	cout << cur << endl;
}