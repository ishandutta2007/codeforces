#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        sum += (m + (i % 5)) / 5;
    }
    cout << sum;
}