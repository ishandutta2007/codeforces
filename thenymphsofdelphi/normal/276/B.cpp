#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length(), cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++){
        if (cnt[i] & 1){
            ans++;
        }
    }
    if (ans <= 1 || ans & 1){
        cout << "First";
        return 0;
    }
    cout << "Second";
}