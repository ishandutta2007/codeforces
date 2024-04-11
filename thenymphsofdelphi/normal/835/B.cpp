#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int k, n, sum = 0, ans = 0, t = 10;
    int dig[11];
    memset(dig, 0, sizeof(dig));
    string s;
    cin >> k >> s;
    n = s.length();
    for (int i = 0; i < n; i++){
        sum += s[i] - '0';
        dig[s[i] - '0']++;
        t = min(t, (int)(s[i] - '0'));
    }
    if (sum >= k){
        cout << 0;
        return 0;
    }
    while (sum < k){
        if (t == 9){
            break;
        }
        if (dig[t] == 0){
            t++;
            continue;
        }
        sum += 9 - t;
        dig[t]--;
        ans++;
    }
    cout << ans;
}