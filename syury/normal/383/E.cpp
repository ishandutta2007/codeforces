//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 24;

uint16_t f[1<<N];
int n;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int mask = (1<<(s[0]-'a'))|(1<<(s[1]-'a'))|(1<<(s[2]-'a'));
        ++f[mask];
    }
    for(int i = 0; i < N; i++){
        for(int mask = 0; mask < (1<<N); mask++)
            f[mask] += (mask&(1<<i)) ? f[mask^(1<<i)] : 0;
    }
    int ans = 0;
    for(int i = 0; i < (1<<N); i++)
        ans ^= (n - f[i])*(n - f[i]);
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    while(T--)
        solve();
    return 0;
}