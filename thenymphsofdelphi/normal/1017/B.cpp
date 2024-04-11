#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    string a, b;
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++){
        cnt[a[i] - '0'][b[i] - '0']++;
    }
    cout << cnt[0][0] * (cnt[1][0] + cnt[1][1]) + cnt[0][1] * cnt[1][0];
}