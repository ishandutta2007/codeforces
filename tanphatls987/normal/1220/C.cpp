#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    auto best = char('z' + 1);
    for(int i = 0; i < s.length(); i++) {
        best = min(best, s[i]);
        cout << ((s[i] == best) ? "Mike" : "Ann") << '\n';
    }
}