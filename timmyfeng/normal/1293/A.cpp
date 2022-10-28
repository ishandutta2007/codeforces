#include <bits/stdc++.h>
using namespace std;

int t, n, s, k;
set<int> close;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
        cin >> n >> s >> k;
        close.clear();
        while (k--) {
            int tmp;
            cin >> tmp;
            close.insert(tmp);
        }
        int ct = 0;
        while (1) {
            if (ct + s <= n && close.count(ct + s) == 0)
                break;
            if (s - ct > 0 && close.count(s - ct) == 0)
                break;
            ct++;
        }
        cout << ct << "\n";
    }
}