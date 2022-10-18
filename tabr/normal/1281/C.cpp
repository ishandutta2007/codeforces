#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    ll mod = 1e9 + 7;
    while (t--) {
        int x;
        string s;
        cin >> x >> s;
        ll ans = s.size();
        rep(i, 0, x) {
            if(s[i]=='1')continue;
            ll l = s[i] - '0'; 
               
            if (s.size() < x) {
                string t = s.substr(i + 1);
                rep(jj,1,l)rep(j,0,t.size())if(s.size()<x)s.push_back(t[j]);
                else break;
            }
            
            ans = (mod + (ans - i - 1) * l + i + 1) % mod;
        }
        cout << ans << endl;
    }
 
    return 0;
}