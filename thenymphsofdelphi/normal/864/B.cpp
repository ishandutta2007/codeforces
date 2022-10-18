#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, ans = 0;
    string s;
    cin >> n >> s;
    s = 'A' + s;
    s += 'A';
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    n += 2;
    for (int i = 0; i < n; i++){
        if (isupper(s[i])){
            int temp = 0;
            for (int j = 0; j < 26; j++){
                if (cnt[j]){
                    temp++;
                }
            }
            ans = max(ans, temp);
            memset(cnt, 0, sizeof(cnt));
        }
        else{
            cnt[s[i] - 'a']++;
        }
    }
    cout << ans;
}