#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int N = 1e3 + 5, inf = 1e9 + 7;

int n;
int a[N], b[N];
int k, t, mx = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    mx = b[1];
    k = a[1] + b[1];
    t = b[1];
    for (int i = 2; i <= n; i++){
        t = max(0, t - a[i] + a[i - 1]) + b[i];
        k = max(k, a[i] + t);
        mx = max(mx, t);
    }
    cout << k << ' ' << mx << endl;
}