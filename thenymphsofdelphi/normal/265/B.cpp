#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ans += n * 2 - 1;
    ans += a[0];
    for (int i = 1; i < n; i++){
        ans += abs(a[i] - a[i - 1]);
    }
    cout << ans;
}