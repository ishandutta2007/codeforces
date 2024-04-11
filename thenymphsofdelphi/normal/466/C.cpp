#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500005;
int a[N], cnt[N], sum[N];

signed main(){
    int n, add = 0, t = 0, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0){
        cout << 0;
        return 0;
    }
    memset(sum, 0, sizeof sum);
    for (int i = n - 1; i >= 0; i--){
        add += a[i];
        if (add == s / 3){
            cnt[i] = 1;
        }
        else{
            cnt[i] = 0;
        }
        sum[i] = sum[i + 1] + cnt[i];
    }
    add = 0;
    for (int i = 0; i < n; i++){
        add += a[i];
        if (add == s / 3){
            t += sum[i + 2];
        }
    }
    cout << t;
}