#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string s, t;
    map <char, int> now;
    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n - i - 1; i++) {
        now.clear();
        now[s[i]]++;
        now[s[n - i - 1]]++;
        now[t[i]]++;
        now[t[n - i - 1]]++;
        if (now.size() == 4) {
            ans += 2;
            continue;
        }
        if (now.size() == 3) {
            if (s[i] == s[n - i - 1]) ans += 2;
            else ans++;
            continue;
        }
        if (now.size() == 2) {
            if (now[s[i]] == 2) continue;
            ans++;
        }
    }
    if (n % 2 == 1 && s[n / 2] != t[n / 2]) ans++;
    cout << ans << endl;
    return 0;
}