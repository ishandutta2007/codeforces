#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void parse(const string&);
vector<string> path;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    bool alpha = false;
    for (int i = 0; i < s.length(); ++i) if (s[i] != '/') alpha = true;
    if (!alpha) return cout << "/" << endl, 0;
    int ind = 0;
    while (ind < s.length() && s[ind] == '/') ++ind;
    parse(s.substr(ind, s.length() - ind));
    for (string p : path) cout << "/" << p; cout << endl;
    return 0;
}

void parse(const string& s) {
    if (s.length() == 0) return;
    int ind = 0;
    while (ind < s.length() && s[ind] != '/') ++ind;
    path.push_back(s.substr(0, ind));
    while (ind < s.length() && s[ind] == '/') ++ind;
    parse(s.substr(ind, s.length() - ind));
}