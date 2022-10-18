#include<bits/stdc++.h>
using namespace std;

string string_time(int h, int m){
    string ans = "  :  ";
    ans[0] = h / 10 + '0';
    ans[1] = h % 10 + '0';
    ans[3] = m / 10 + '0';
    ans[4] = m % 10 + '0';
    return ans;
}

int main(){
    string s, a, b;
    cin >> s;
    int h, m;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    int cnt = 0;
    while (1){
        a = string_time(h, m);
        b = a;
        reverse(b.begin(), b.end());
        if (b == a){
            cout << cnt;
            return 0;
        }
        cnt++;
        m++;
        if (m == 60){
            m = 0;
            h++;
        }
        if (h == 24){
            h = 0;
        }
    }
}