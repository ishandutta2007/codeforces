#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    char a[n][n];
    int c[n], r[n];
    memset(c, 0, sizeof(c));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 'C'){
                c[i]++;
                r[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += c[i] * (c[i] - 1) / 2;
        ans += r[i] * (r[i] - 1) / 2;
        //cout << c[i] << ' ' << r[i] << endl;
    }
    cout << ans;
}