#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt[26 * 26];
    memset(cnt, 0, sizeof(cnt));
    int n, t;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++){
        t = (s[i - 1] - 'A') * 26 + (s[i] - 'A');
        cnt[t]++;
    }
    int mx = -1;
    char a, b;
    for (int i = 0; i < 26 * 26; i++){
        if (mx < cnt[i]){
            mx = cnt[i];
            a = (i / 26) + 'A';
            b = (i % 26) + 'A';
        }
    }
    cout << a << b;
}