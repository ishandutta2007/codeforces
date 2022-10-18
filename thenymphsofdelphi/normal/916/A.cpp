#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, h, m, ans = 0;
    string s;
    cin >> x;
    cin >> s;
    h = (s[0] - '0') * 10 + s[1] - '0';
    cin >> s;
    m = (s[0] - '0') * 10 + s[1] - '0';
    while (h % 10 != 7 && m % 10 != 7){
        ans++;
        m -= x;
        if (m < 0) m += 60, h--;
        if (h < 0) h += 24;
    }
    cout << ans;
}