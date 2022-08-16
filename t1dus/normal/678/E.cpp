/*input
3
0.0 0.5 0.8
0.5 0.0 0.4
0.2 0.6 0.0
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

int power(int a,int b,int m = MOD){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2,m)%m;
    x = (x*x)%m;
    if(b%2) return (x*a)%m;
    return x;
}

int n;
double a[19][19],dp[19][(1<<19)];

double solve(int ind,int mask){    
    if(dp[ind][mask] != -1) return dp[ind][mask];
    int cnt = 0;
    REP(i,n){
        if(i != ind and ((mask&(1<<i)) == 0)) cnt ++;
    }
    if(!cnt) return dp[ind][mask] = (ind == 0);
    double ans = 0;
    REP(i,n){
        if(i != ind and ((mask&(1<<i)) == 0)){
            double x = a[ind][i]*solve(ind,mask|(1<<i));
            double y = a[i][ind]*solve(i,mask|(1<<ind));
            remax(ans,x+y);
        }
    }
    return dp[ind][mask] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    REP(i,19) REP(j,(1<<19)) dp[i][j] = -1;

    cout << fixed << setprecision(10);

    cin >> n;
    REP(i,n) REP(j,n) cin >> a[i][j];
    
    double ans = 0;
    REP(i,n){
        remax(ans,solve(i,0));
    }
    cout << ans << endl;
}