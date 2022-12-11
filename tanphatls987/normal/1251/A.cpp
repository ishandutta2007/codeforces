#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int h[26];
        memset(h, 0, sizeof(h));
        string s;
        cin >> s;
        for(int en = 0; en < s.size(); ) {
            int st = en;
            while (en < s.length() && s[st] == s[en]) en++;
            if ((en - st) % 2 == 1) h[s[st] - 'a'] = 1;
        }
        for(int i = 0; i < 26; i++) if (h[i]) 
            cout << char('a' + i);
        cout << '\n';
    }
}