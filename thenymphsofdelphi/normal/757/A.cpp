#include<bits/stdc++.h>
using namespace std;

int B, u, l, b, a, s, r;

int main(){
    string str;
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++){
        switch (str[i]){
            case 'B': B++; break;
            case 'u': u++; break;
            case 'l': l++; break;
            case 'b': b++; break;
            case 'a': a++; break;
            case 's': s++; break;
            case 'r': r++; break;
        }
    }
    int ans = min(B, u / 2);
    ans = min(ans, l);
    ans = min(ans, b);
    ans = min(ans, a / 2);
    ans = min(ans, s);
    ans = min(ans, r);
    cout << ans;
}