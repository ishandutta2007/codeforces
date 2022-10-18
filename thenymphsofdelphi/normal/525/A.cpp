#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (islower(s[i])){
            cnt[s[i] - 'a']++;
        }
        else{
            if (cnt[s[i] - 'A']){
                cnt[s[i] - 'A']--;
            }
            else{
                ans++;
            }
        }
    }
    cout << ans;
}