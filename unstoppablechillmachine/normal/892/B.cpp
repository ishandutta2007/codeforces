 #include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e6 + 10;

_ void source() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), need_ers;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (!arr[i] && i > 1) {
            st.ins(i - 1);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i]) {
            auto it = st.lower_bound(i - arr[i]);
            while (it != st.end() && *it < i) {
                //st.ers(it);
                need_ers.pb(*it);
                it++;
            }
            for (auto it : need_ers) {
                st.ers(it);
            }
            need_ers.clear();
        }
    }
    cout << st.size() + 1;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}