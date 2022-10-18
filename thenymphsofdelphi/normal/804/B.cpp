#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    string s;
    int num = 0, ans = 0;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--){
        if (s[i] == 'b'){
            num = (num + 1) % mod;
        }
        else{
            ans = (ans + num) % mod;
            num = (num + num) % mod;
        }
    }
    cout << ans;
}