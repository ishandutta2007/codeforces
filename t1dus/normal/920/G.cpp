/*input
3
7 22 1
7 22 2
7 22 3
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

int x,p,k;
vi fact[1000005];

int F(int n){
    /* returns the number of numbers <= n coprime to p */
    
    // int cnt = 0;
    // FOR(i,1,n+1){
    //     if(gcd(i,p) == 1) cnt ++;
    // }
    // return cnt;

    int ans = 0;

    FOR(i,0,(1<<fact[p].size())){
        int cnt = 0,cur = 1;
        REP(j,fact[p].size()){
            if(i&(1<<j)){
                cnt ++;
                cur *= fact[p][j];
            }  
        }
        if(cnt%2) ans -= (n)/cur;
        else ans += (n)/cur;
    }
    // cout << n << " " << ans << endl;;
    return ans;
}

void solve(){
    cin >> x >> p >> k;
    int cnt = F(x);
    int low = x+1,high = 1000000000000,mid,ans;
    while(low <= high){
        mid = (low+high)/2;
        // cout << mid << endl;
        int lol = F(mid)-cnt;
        if(lol >= k){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    FOR(i,2,1000005){
        if(fact[i].size() == 0){
            for(int j = i; j <= 1000000; j += i) fact[j].pb(i);
        }
    }

    int t = 1;
    cin >> t;
    WL(t) solve();
}