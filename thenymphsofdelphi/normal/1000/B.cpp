#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int N = 100005;
int a[N], l[N], d[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, mx, difl, difd;
    cin >> n >> k;
    l[0] = 0;
    d[0] = 0;
    a[0] = 0;
    for (int i = 1; i <= n + 1; i++){
        l[i] = l[i - 1];
        d[i] = d[i - 1];
        if (i <= n){
            cin >> a[i];
        }
        else{
            a[i] = k;
        }
        if (i % 2 == 1){
            l[i] += a[i] - a[i - 1];
        }
        else{
            d[i] += a[i] - a[i - 1];
        }
    }
    mx = l[n + 1];
    for (int i = 1; i <= n + 1; i++){
        difl = l[n + 1] - l[i];
        difd = d[n + 1] - d[i];
        if (i % 2 == 1){
            mx = max(mx, l[n + 1] + difd - difl - 1);
        }
        else{
            mx = max(mx, l[n + 1] + difd - difl + (d[i] - d[i - 1] - 1));
        }
    }
    cout << mx;
}