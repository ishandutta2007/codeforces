#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[300005];

signed main(){
    int n, sum = 0, ex;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        sum += abs(i + 1 - a[i]);
    }
    cout << sum;
}