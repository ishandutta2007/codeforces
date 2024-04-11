#include <bits/stdc++.h>

using namespace std;

vector<int> buildPF(string s) {
    vector<int> p(s.length());

    int j = 0; p[0] = 0;
    for(int i = 1; i < s.length(); ++i) {
        while (j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }

    return p;
}

string findLongestPrefixPalin(string s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    s = s + "#" + tmp;

    vector<int> p = buildPF(s);
    return s.substr(0, p.back());
}

string solve(string s) {    
    string outer;

    int i = 0, j = s.length() - 1;
    while (i < j && s[i] == s[j]) {
        outer += s[i];
        ++i;
        --j;
    }
    s = s.substr(i, j - i + 1);

    string ans = outer;

    string pref = findLongestPrefixPalin(s);
    reverse(s.begin(), s.end());
    string suf = findLongestPrefixPalin(s);
    if (pref.length() > suf.length())
        ans += pref;
    else
        ans += suf;

    reverse(outer.begin(), outer.end());
    ans += outer;

    return ans;    
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nTest;
    cin >> nTest;

    while (nTest--) {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }

}