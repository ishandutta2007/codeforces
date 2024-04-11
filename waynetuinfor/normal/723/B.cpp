#include <bits/stdc++.h>
using namespace std;

vector<string> vec, par;
void parse(const string&);
// bool cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; string s; cin >> n >> s;
    parse(s); 
    // cnt = true;
    int o = vec.size();
    int ans1 = 0;
    for (string str : vec) ans1 = max(ans1, (int)str.size());
    for (string str : par) parse(str);
    int ans2 = vec.size() - o;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
    // for (int)
}

void parse(const string& s) {
    if (s.length() == 0) return;
    if (s[0] == '(') {
        int ind = 0;
        while (s[ind] != ')') ++ind;
        par.push_back(s.substr(1, ind - 1));
        while (ind < s.length() && s[ind] == '_') ++ind;
        if (ind + 1 < s.length()) parse(s.substr(ind + 1, (int)s.length() - ind));
        return;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '_' || s[i] == '(') {
            if (i > 0) vec.push_back(s.substr(0, i));
            if (s[i] == '_') {
                int ind = i;
                while (s[ind] == '_') ++ind;
                parse(s.substr(ind, (int)s.length() - ind));
                return;
            } else {
                parse(s.substr(i, (int)s.length() - i));
                return;
            }
        }
    }
    vec.push_back(s);
}