#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1 || n == 2){
        cout << 0;
        return 0;
    }
    int a[n];
    bool b[n];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int mn = a[0], mx = a[n - 1], l = 0, r = n - 1, cnt = n;
    while (a[l] == mn && !b[l]){
        cnt--;
        b[l] = 1;
        l++;
    }
    while (a[r] == mx && !b[r]){
        cnt--;
        b[r] = 1;
        r--;
    }
    cout << cnt;
}