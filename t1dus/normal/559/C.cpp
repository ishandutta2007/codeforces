/*input
100 100 3
15 16
16 15
99 88
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

int h,w,n;
vector<pii> bc;
int dp[2005];
int fact[200005],ifact[200005];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    FOR(i,2,200005){
        fact[i] = (i*fact[i-1])%MOD;
        ifact[i] = power(fact[i],MOD-2);
    }
    cin >> h >> w >> n;
    REP(i,n){
        int x,y; cin >> x >> y;
        x --;
        y --;
        bc.pb({x,y});
    }
    sort(all(bc));
    bc.pb({h-1,w-1});
    dp[0] = (((fact[bc[0].F+bc[0].S]*ifact[bc[0].F])%MOD)*ifact[bc[0].S])%MOD;
    // cout << dp[0] << endl;
    FOR(i,1,n+1){
        dp[i] = (((fact[bc[i].F+bc[i].S]*ifact[bc[i].F])%MOD)*ifact[bc[i].S])%MOD;
        // cout << i << " " << dp[i] << endl;
        REP(j,i){
            int x = bc[i].F-bc[j].F,y = bc[i].S-bc[j].S;
            if(x >= 0 and y >= 0){
                dp[i] -= (dp[j]*((((fact[x+y]*ifact[x])%MOD)*ifact[y])%MOD))%MOD;
                dp[i] %= MOD;
                dp[i] += MOD;
                dp[i] %= MOD;
            }
        }
        // cout << dp[i] << endl;
    }
    cout << dp[n] << endl;
}