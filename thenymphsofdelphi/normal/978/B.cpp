#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 2; i < len; i++){
        if (s[i] == 'x' && s[i-1] == 'x' && s[i-2] == 'x'){
            ans++;
        }
    }
    cout << ans;
}