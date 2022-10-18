#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++){
        cnt[s[i] - 'A']++;
    }
    int ans = n;
    for (int i = 0; i < k; i++){
        ans = min(ans, cnt[i]);
    }
    cout << ans * k;
}