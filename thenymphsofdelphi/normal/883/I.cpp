#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 3e5 + 5;
ll a[N], dp[N], n, k;

bool check(ll mid){
    int cl = 0;
    for (int i = k; i <= n; i++){
        if (a[i] - a[dp[i - k] + 1] <= mid){
            cl = i;
        }
        dp[i] = cl;
    }
    if (dp[n] == n){
        return true;
    }
    return false;
}

signed main(){
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    ll l = 0, r = 1e9;
    while (l <= r){
        ll mid = (l + r) / 2;
        if (check(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}