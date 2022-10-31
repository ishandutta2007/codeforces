#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

set<string> oks;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (int i=1;i<(1<<s.size());i++) {
        string t;
        for (int j=0;j<s.size();j++) if (i&(1<<j)) t+=s[j];
        int ok = 1;
        int ss = 0;
        int e = t.size()-1;
        while (e>ss) {
            if (t[ss]!=t[e]) ok = 0;
            ss+=1;
            e-=1;
        }
        if (ok && t>ans) ans = t;
    }
    cout << ans;

    return 0;
}