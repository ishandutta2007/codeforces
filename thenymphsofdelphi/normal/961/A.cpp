#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a[1000], i, x, ans = 1001;
    cin >> n >> m;
    for (i = 0; i < n; i++){
        a[i] = 0;
    }
    for (i = 0; i < m; i++){
        cin >> x;
        a[x - 1]++;
    }
    for (i = 0; i < n; i++){
        ans = min(ans, a[i]);
    }
    cout << ans;
}