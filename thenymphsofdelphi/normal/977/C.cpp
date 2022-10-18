#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if (k == 0){
        if (a[0] == 1){
            cout << -1;
            return 0;
        }
        cout << 1;
        return 0;
    }
    if (k == n){
        cout << 1000000000;
        return 0;
    }
    k--;
    if (a[k + 1] == a[k]){
        cout << -1;
        return 0;
    }
    cout << a[k];
}