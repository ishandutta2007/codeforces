#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k, x; cin >> n >> k >> x;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    vector<long long> cst;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1])
            cst.push_back(0);
        else
            cst.push_back((a[i] - a[i - 1] - 1) / x);
    }
    sort(cst.begin(), cst.end());
    int ans = n;
    long long sum = 0LL;
    for(int i = 0; i < (int) cst.size(); i++) {
        if(sum + cst[i] <= k)
            --ans, sum += cst[i];
    }
    cout << ans << "\n";
}