#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], c[n + 1];
    b[0] = 0;
    c[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        c[i] = c[i - 1] + a[i];
    }
    int q, que, l, r;
    cin >> q;
    while (q--){
        cin >> que >> l >> r;
        l--;
        if (que == 1){
            cout << b[r] - b[l] << endl;
        }
        else{
            cout << c[r] - c[l] << endl;
        }
    }
}