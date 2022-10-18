#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans = 1, n, a = 0;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 1; i < n; i++){
        ans += (1 << i);
    }
    for (int i = 0; i < n; i++){
        a *= 2;
        if (s[i] == '7'){
            a++;
        }
    }
    cout << ans + a;
}