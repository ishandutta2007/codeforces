#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 5;

unordered_map <string, int> cnt;
unordered_map <string, string> sm;

unordered_set <string> st;

signed main()
{
    ios_base::sync_with_stdio(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string f;
        cin >> f;
        st.clear();
        for (int j = 0; j < f.size(); j++) {
            string t = "";
            for (int k = j; k < f.size(); k++) {
                t += f[k];
                st.insert(t);
            }
        }
        for (auto t : st) {
            cnt[t]++;
            sm[t] = f;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int t = cnt[s];
        if (t) {
            cout << t << " " << sm[s] << "\n";
        }
        else {
            cout << t << " " << "-\n";
        }
    }
    return 0;
}