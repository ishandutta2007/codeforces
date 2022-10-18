#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> k;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (cnt[i] % k != 0){
            cout << -1;
            return 0;
        }
        cnt[i] /= k;
    }
    for (int l = 0; l < k; l++){
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < cnt[i]; j++){
                cout << (char)(i + 'a');
            }
        }
    }
}