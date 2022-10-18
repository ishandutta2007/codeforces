#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, sum = 0;
    cin >> n >> m;
    int a[n], b[n];
    int t = 0, h;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum += b[i] - a[i] + 1;
        h = a[i] - t - 1;
        sum += h % m;
        t = b[i];
    }
    cout << sum;
}