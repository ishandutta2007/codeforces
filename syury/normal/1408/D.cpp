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

const int C = (int)1e6 + 6;
const int N = 2222;

int n, m;
int a[N], b[N], c[N], d[N];
int add[C];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d", a + i, b + i);
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", c + i, d + i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int dx = c[j] - a[i] + 1;
            int dy = d[j] - b[i] + 1;
            dy = max(dy, 0);
            dx = max(dx, 0);
            add[dx] = max(add[dx], dy);
        }
    }
    int ans = C * 3;
    int carry = 0;
    for(int x = C - 1; x >= 0; x--){
        ans = min(ans, carry + x);
        carry = max(carry, add[x]);
    }
    printf("%d\n", ans);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}