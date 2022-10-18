#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (cnt[i] > k){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}