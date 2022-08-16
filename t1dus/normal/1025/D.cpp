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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,a[705],G[705][705];
int dp[705][705][2];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    FOR(i,1,n+1) cin >> a[i];
    a[0] = 0;
    a[n+1] = 0;
    REP(i,n+2){
        REP(j,n+2){
            G[i][j] = min(gcd(a[i],a[j]),2);
        }
    }
    if(n != 700 or 1){
        for(int i = n+1; i >= 1; i--){
        FOR(j,0,n+1){
            if(i > j) dp[i][j][0] = dp[i][j][1] = 1;
            else{
                dp[i][j][0] = dp[i][j][1] = 0;
                FOR(k,i,j+1){
                    if(G[k][i-1] > 1 and dp[i][k-1][1] and dp[k+1][j][0]){
                        dp[i][j][0] = 1;
                    }
                    if(G[k][j+1] > 1 and dp[i][k-1][1] and dp[k+1][j][0]){
                        dp[i][j][1] = 1;
                    }
                }
            }
        }
    }
    }
    // REP(i,n+2){
    //     REP(j,n+2){
    //         cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
    //     }
    // }
    if(dp[1][n][0]) cout << "Yes\n";
    else cout << "No\n";
}