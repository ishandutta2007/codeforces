#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[300000];

signed main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++){
        sum += (i + 2) * a[i];
    }
    sum += n * a[n - 1];
    cout << sum;
}