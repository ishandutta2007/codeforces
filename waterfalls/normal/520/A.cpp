#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;
int has[26];

int main() {
    cin >> n >> s;
    for (int i=0;i<n;i++) if (s[i]>'Z') has[s[i]-'a'] = 1; else has[s[i]-'A'] = 1;
    int ok = 1;
    for (int i=0;i<26;i++) if (!has[i]) ok = 0;
    cout << (ok ? "YES" : "NO");

    return 0;
}