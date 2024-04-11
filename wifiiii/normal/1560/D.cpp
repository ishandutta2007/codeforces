#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(string s, string t) {
    int j = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(j < t.size() && s[i] == t[j]) ++j;
    }
    return j;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s = to_string(n);
        int ans = 233;
        for(int i = 0; i <= 60; ++i) {
            string x = to_string(1ll << i);
            ans = min<int>(ans, s.size() + x.size() - 2 * calc(s, x));
        }
        cout << ans << endl;
    }
}