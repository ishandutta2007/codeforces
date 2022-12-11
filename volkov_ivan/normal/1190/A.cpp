#include <bits/stdc++.h>
#define int long long

using namespace std;

deque <int> pos;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    pos.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
        pos[i]--;
    }
    int pref = 0;
    int res = 0;
    while (!pos.empty()) {
        int v = pos.front() - pref;
        int str = v / k;
        res++;
        int pref0 = 0;
        //cout << str << endl;
        while (!pos.empty() && pos.front() < (str + 1) * k + pref) {
            pos.pop_front();
            pref0++;
        }
        pref += pref0;
    }
    cout << res << endl;
}