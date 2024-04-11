#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + n);
    int ans = 0, idx = n - 1;
    while (idx >= 0){
        ans += a[idx];
        idx -= k;
    }
    ans *= 2;
    cout << ans;
}