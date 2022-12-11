#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;


string s;
int v[2];
int n;

int tr[N];
void prepare() {
    string s1;
    cin >> s1 >> s;
    v[0] = count(s1.begin(), s1.end(), '0');
    v[1] = count(s1.begin(), s1.end(), '1');
    n = s.length();
    
    for(int i = 1; i < n; i++) {
        int z = tr[i - 1];
        while (z && s[i] != s[z]) z = tr[z - 1];
        if (s[i] == s[z]) z++;
        tr[i] = z;
    }
}
void solve() {
    for(int i = 0; i < n; i++) {
        if (v[s[i] - '0']) {
            cout << s[i];
            v[s[i] - '0']--;
        } else {
            for(int j = 0; j <= 1; j++) cout << string(v[j], char('0' + j));
            return;
        }
    }
    while (1) {
        for(int i = tr[n - 1]; i < n; i++) {
            if (v[s[i] - '0']) {
                cout << s[i];
                v[s[i] - '0']--;
            } else {
                for(int j = 0; j <= 1; j++) cout << string(v[j], char('0' + j));
                return;
            }
        }
    }
}
int main() {
    prepare();
    solve();
}