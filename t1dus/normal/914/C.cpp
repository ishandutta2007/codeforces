/*input
111111011
2
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

string n;
int k;

int b[1005],dp[1005][1005][2];

int cb(int n){
    int res = 0;
    while(n){
        n &= (n-1);
        res ++;
    }
    return res;
}

int comp(int ind,int sb,int any){
    if(dp[ind][sb][any] != -1) return dp[ind][sb][any];
    if(sb == 0) return 1;
    if(ind == n.length()) return 0;
    if(any or n[ind] == '1'){
        return dp[ind][sb][any] = (comp(ind+1,sb-1,any)+comp(ind+1,sb,1))%MOD;
    }
    else{
        return dp[ind][sb][any] = comp(ind+1,sb,any);
    }
}

void solve(){
    cin >> n >> k;
    if(k == 0){
        cout << "1\n";
        return;
    }
    if(k == 1){
        cout << n.length()-1 << endl;
        return;
    }
    b[1] = 0;
    FOR(i,2,1001) b[i] = 1+b[cb(i)];
    
    REP(i,1005) REP(j,1005) REP(l,2) dp[i][j][l] = -1;
    int ans = 0;
    FOR(i,1,1001){
        if(b[i] > 4) cout << i << " " << b[i] << endl;
        if(b[i] == k-1){
            ans += comp(0,i,0);
            // cout << i << endl;
            ans %= MOD;
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    WL(t) solve();
}