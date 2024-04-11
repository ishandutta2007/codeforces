#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100000];

signed main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i == 0){
            continue;
        }
        cout << a[i - 1] + a[i] << " ";
        if (i == n - 1){
            cout << a[i];
            return 0;
        }
    }
}