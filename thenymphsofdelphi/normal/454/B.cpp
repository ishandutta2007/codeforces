#include<bits/stdc++.h>
using namespace std;

int a[200005];
int b[200004];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        a[i + n] = a[i];
    }
    int idx = 0;
    b[0] = 0;
    for (int i = 1; i < n * 2; i++){
        if (a[i] >= a[i - 1]){
            b[i] = b[i - 1] + 1;
        }
        else{
            b[i] = 0;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n * 2; i++){
        if (b[i] >= n - 1){
            ans = min(ans, (n * 3 - i - 1) % n);
        }
    }
    if (ans == 1e9){
        cout << -1;
        return 0;
    }
    cout << ans;
}