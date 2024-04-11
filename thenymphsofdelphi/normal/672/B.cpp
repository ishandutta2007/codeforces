#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n > 26){
        cout << -1;
        return 0;
    }
    string s;
    cin >> s;
    bool a[26];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        a[s[i] - 'a'] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++){
        if (a[i]){
            cnt++;
        }
    }
    cout << n - cnt;
}