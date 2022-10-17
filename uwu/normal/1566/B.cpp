#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        if (s.find('0') == s.npos) cout << 0 << '\n';
        else if (s.find('1') == s.npos) cout << 1 << '\n';
        else{
            int cnt = 0;
            for (char c : s) cnt += c == '0';
            bool seen = 0; int cnt2 = 0;
            for (char c : s){
                if (c == '1' && seen) break;
                if (c == '0') seen = 1, cnt2++;
            }
            if (cnt == cnt2) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}