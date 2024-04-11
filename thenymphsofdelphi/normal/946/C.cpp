#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    cin >> s;
    int n = s.length(), l = 0;
    for (int i = 0; i < n; i++){
        if (s[i] - 'a' <= l){
            s[i] = l + 'a';
            l++;
        }
        if (l >= 26){
            cout << s;
            return 0;
        }
    }
    if (l >= 26){
        cout << s;
        return 0;
    }
    cout << -1;
}