#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            cout << s[n - 1];
        }
        cout << endl;
    }
}