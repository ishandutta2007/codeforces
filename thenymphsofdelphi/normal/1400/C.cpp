#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = s.length();
        string t(n, '1');
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                if (i - x >= 0 && i - x < n){
                    t[i - x] = '0';
                }
                if (i + x >= 0 && i + x < n){
                    t[i + x] = '0';
                }
            }
        }
        bool ck = 1;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                if (i - x >= 0 && i - x < n && t[i - x] == '1'){
                    continue;
                }
                if (i + x >= 0 && i + x < n && t[i + x] == '1'){
                    continue;
                }
                ck = 0;
                break;
            }
        }
        if (ck){
            cout << t << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}