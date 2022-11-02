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

int a[111], b[111], c[111];
int ans[111];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    ans[0] = a[0];
    for(int i = 1; i < n - 1; i++){
        if(ans[i - 1] == a[i])
            ans[i] = b[i];
        else
            ans[i] = a[i];
    }
    if(ans[n - 2] != a[n - 1] && ans[0] != a[n - 1])
        ans[n - 1] = a[n - 1];
    else if(ans[n - 2] != b[n - 1] && ans[0] != b[n - 1])
        ans[n - 1] = b[n - 1];
    else
        ans[n - 1] = c[n - 1];
    for(int i = 0; i < n; i++)cout << ans[i] << ' ';
    cout << '\n';
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}