#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[1000];

int main() {
    int n, k; cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) cnt[s[i]]++;
    for (int i = 0; i < k; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) if (cnt[j]) --cnt[j];
    }
    for (int i = 'a'; i <= 'z'; ++i) if (cnt[i]) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}