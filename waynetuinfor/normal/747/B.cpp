#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> mp;
string s;
int n, t;

int main() {
    cin >> n >> s;
    mp['A'] = mp['G'] = mp['T'] = mp['C'] = 0;
    for (int i = 0; i < n; ++i) if (s[i] != '?') mp[s[i]]++;
    //for (auto it = mp.begin(); it != mp.end(); ++it) cout << it->first << ' ' << it->second << '\n';
    if (n % 4) { cout << "===\n"; return 0; }
    t = n / 4;
    if (mp['A'] > t || mp['C'] > t || mp['T'] > t || mp['G'] > t) { cout << "===\n"; return 0; }
    auto it = mp.begin();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            while (it->second >= t) it++;
            s[i] = it->first;
            it->second++;
        }
    }
    cout << s << '\n';
    return 0;
}