#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], ans[n];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans[i] += a[i] * 15;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i]; j++){
            int x;
            cin >> x;
            ans[i] += x * 5;
        }
    }
    int mn = 1000000000;
    for (int i = 0; i < n; i++){
        mn = min(mn, ans[i]);
    }
    cout << mn;
}