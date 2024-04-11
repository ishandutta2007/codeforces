#include <bits/stdc++.h>
using namespace std;

int n, b;

bool query(int a, string s) {
    while ((int) s.size() < b) {
        s += '1';
    }

    cout << a << " " << s << endl;

    string r;
    cin >> r;
    return r == "yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;

    vector<int> indices;
    string ans;

    for (int i = 1; i <= n; ++i) {
        indices.push_back(i);
    }

    while ((int) ans.size() < b) {
        vector<int> stk;
        for (auto i : indices) {
            while (!stk.empty() && query(i, ans)) {
                stk.pop_back();
                ans.pop_back();
            }

            if ((int) ans.size() < b) {
                stk.push_back(i);
                ans += query(i, ans + '0') ? '1' : '0';
            }
        }

        indices.clear();
        while (!stk.empty()) {
            int i = stk.back();
            stk.pop_back();
            if (query(i, ans)) {
                while (!indices.empty()) {
                    indices.pop_back();
                    ans.pop_back();
                }
            }
            indices.push_back(i);
        }
    }

    cout << "0 " << ans << endl;
}