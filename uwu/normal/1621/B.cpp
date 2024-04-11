#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 2 * 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int L, R; cin >> L >> R;
        int c; cin >> c;
        cout << c << '\n';
        int cl, cr, ca; cl = cr = ca = c;
        for (int i = 2; i <= N; ++i){
            int l, r, c; cin >> l >> r >> c;
            if (r > R) R = r, cr = ca = inf;
            if (l < L) L = l, cl = ca = inf;
            if (l == L) cl = min(cl, c);
            if (r == R) cr = min(cr, c);
            if (l == L && r == R) ca = min(ca, c);
            cout << min(ca, cl + cr) << '\n';
        }
    }
}