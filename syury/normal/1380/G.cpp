//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;
const int mod = 998244353;

int n;
int a[N];
ll pref[N];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll iN = 1;
    ll x = n;
    ll p = mod - 2;
    while(p){
        if(p&1)iN = iN * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        pref[i] = i ? pref[i - 1] : 0;
        pref[i] += a[i];
        pref[i] %= mod;
    }
    for(int k = 1; k <= n; k++){
        ll sum = 0;
        int mul = 0;
        for(int i = n - 1; i >= 0; i -= k){
            int j = max(0, i - k + 1);
            ll curr = pref[i] - (j ? pref[j - 1] : 0);
            sum += curr * mul % mod;
            ++mul;
        }
        sum = sum % mod * iN % mod;
        sum = (sum % mod + mod) % mod;
        cout << sum << " \n"[k == n];
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}