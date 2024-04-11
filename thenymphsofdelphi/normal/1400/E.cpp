#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n;
int a[5005];

int cal(int l, int r, int val){
    if (l > r){
        return 0;
    }
    int mn = 1000000007, idx = 0;
    for (int i = l; i <= r; i++){
        if (a[i] < mn){
            mn = a[i];
            idx = i;
        }
    }
    return min(r - l + 1, cal(l, idx - 1, mn) + cal(idx + 1, r, mn) + mn - val);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << cal(0, n - 1, 0);
}