#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;

bool check(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int now = 0, p = -1;
    vector<int> pos; pos.push_back(-1);
    for (int i = 0; i < s.length(); ++i) {
        if (!check(s[i])) pos.push_back(i);
    }
    pos.push_back(s.length());
    vector<int> ans;
    for (int i = 1; i < pos.size(); ++i) {
        // cout << "pos[i] = " << pos[i] << " pos[i - 1] = " << pos[i - 1] << endl;
        if ((pos[i] - pos[i - 1] - 1) < 3) continue;
        set<char> st;
        for (int j = pos[i - 1] + 1; j < pos[i]; ++j) st.insert(s[j]);
        if (st.size() == 1) continue;
        // for (int j = pos[i - 1] + 3; j < pos[i]; j += 2) ans.push_back(j);
        for (int j = pos[i - 1] + 1; j < pos[i]; ) {
            int ind = j, cnt = 0;
            set<char> st;
            for (; ind < pos[i]; ++ind) {
                st.insert(s[ind]);
                ++cnt;
                if (st.size() > 1 && cnt >= 3) {
                    ans.push_back(ind);
                    break;
                }
            }
            j = ind;
        }
    }
    int ind = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (ind < ans.size() && ans[ind] == i) cout << ' ', ++ind;
        cout << s[i];
    } 
    cout << endl;
    return 0;
}