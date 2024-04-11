#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, k, a[26], mx = -1, val, ans = 0;
    cin >> s >> k;
    n = s.length();
    for (int i = 0; i < 26; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; i++){
        val = s[i] - 'a';
        ans += a[val] * (i + 1);
    }
    for (int i = n; i < k + n; i++){
        ans += mx * (i + 1);
    }
    cout << ans;
}