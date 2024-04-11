#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    if (n > 26){
        cout << "YES";
        return 0;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (cnt[i] >= 2 || cnt[i] == n){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}