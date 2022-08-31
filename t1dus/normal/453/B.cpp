/*input
5
1 6 4 2 8
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

int n,a[105];
vi primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int fact[65];
int dp[105][(1<<16)],take[105][(1<<16)];

void solve(int ind,int mask){
    if(ind >= n){
        dp[ind][mask] = 0;
        return;
    }
    if(dp[ind][mask] != -1) return ;
    dp[ind][mask] = INF;
    FOR(i,1,60){
        if(fact[i]&mask) continue;
        solve(ind+1,mask|fact[i]);
        int lol = abs(a[ind]-i)+dp[ind+1][fact[i]|mask];
        if(lol < dp[ind][mask]){
            dp[ind][mask] = lol;
            take[ind][mask] = i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    REP(i,105) REP(j,(1<<16)){
        dp[i][j] = -1;
        take[i][j] = -1;
    }

    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,61){
        fact[i] = 0;
        REP(j,16){
            if(i%primes[j] == 0) fact[i] |= (1<<j);
        }
    }
    solve(0,0);
    int cur = 0;
    REP(i,n){
        cout << take[i][cur] << " ";
        cur |= fact[take[i][cur]];
    }
}