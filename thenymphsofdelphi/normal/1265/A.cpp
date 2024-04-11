#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    cin >> q;
    while (q--){
        string s; cin >> s;
        int n = s.length();
        s = ' ' + s + ' ';
        bool ck = 0;
        for (int i = 2; i <= n; i++){
            if (s[i] == s[i - 1] && s[i] != '?'){
                ck = 1;
                break;
            }
        }
        if (ck){
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++){
            if (s[i] == '?'){
                if (s[i - 1] != 'a' && s[i + 1] != 'a'){
                    s[i] = 'a';
                    continue;
                }
                if (s[i - 1] != 'b' && s[i + 1] != 'b'){
                    s[i] = 'b';
                    continue;
                }
                if (s[i - 1] != 'c' && s[i + 1] != 'c'){
                    s[i] = 'c';
                    continue;
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << s[i]; cout << endl;
    }
}