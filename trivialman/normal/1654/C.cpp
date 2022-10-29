#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const int INF = 1e5 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, x, y;
LL a[N], sum;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        rep(i, 1, n) cin >> a[i], sum += a[i];
        sort(a + 1, a + n + 1);

        bool flag = true;
        multiset<LL> st;
        st.clear();
        st.insert(sum);
        int r = n;
        while (st.size()) {
            auto iter = st.end();
            LL x = *(--iter);
            st.erase(iter);
            if (x < a[r]) {
                flag = false;
                break;
            } else if (x == a[r])
                r--;
            else
                st.insert(x / 2), st.insert((x + 1) / 2);
        }
        cerr << endl;
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}