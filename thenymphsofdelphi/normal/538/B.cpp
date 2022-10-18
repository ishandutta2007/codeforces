#include<bits/stdc++.h>
using namespace std;

int convert(string s){
    int ans = 0;
    for (int i = 0; i < s.length(); i++){
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}

int main(){
    string s, t;
    cin >> s;
    int n = s.length(), k = -1;
    for (int i = 0; i < n; i++){
        k = max(k, s[i] - '0');
    }
    cout << k << endl;
    for (int i = 1; i <= k; i++){
        t = s;
        for (int j = 0; j < n; j++){
            if ((s[j] - '0') >= i){
                t[j] = '1';
            }
            else{
                t[j] = '0';
            }
        }
        int ans = convert(t);
        cout << ans << ' ';
    }
}