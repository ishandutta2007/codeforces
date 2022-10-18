#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int l = 200, r = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > k){
            if (l > 100){
                l = i;
            }
            if (r < i){
                r = i;
            }
        }
    }
    if (l == 200){
        cout << n;
        return 0;
    }
    cout << l + n - r - 1;
}