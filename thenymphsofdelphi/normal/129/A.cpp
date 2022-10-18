#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], sum = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 0) x++;
        else y++;
    }
    if (sum % 2 == 0) cout << x;
    else cout << y;
}