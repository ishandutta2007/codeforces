#include <bits/stdc++.h>
using namespace std;

int cnt[1000];
bool v[10010];

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) ++cnt[s[i]];
    int cur = 0;
    int o = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] & 1) ++o;
    } 
    if (o < 2 || o % 2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}