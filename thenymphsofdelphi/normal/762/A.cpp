#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            a.push_back(i);
            a.push_back(n / i);
            if (i * i == n) a.pop_back();
        }
    }
    sort(a.begin(), a.end());
    if (k > a.size()) cout << -1;
    else cout << a[k - 1];
}