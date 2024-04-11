#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string s;
string x = "CODEFORCES";

int main() {
    cin >> s;
    int ok = 0;
    for (int i=0;i<s.size();i++) for (int j=i;j<s.size();j++) {
        string cur = "";
        for (int k=0;k<s.size();k++) if (k<i || k>j) cur+=s[k];
        if (cur.compare(x)==0) ok = 1;
    }
    if (ok) cout << "YES";
    else cout << "NO";

    return 0;
}