#include<bits/stdc++.h>
using namespace std;

set<int> sq;

bool issq(int x) {
    return sq.count(x);
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        sq.insert(i * i);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -1e6;
    for (int i = 0; i < n; i++) {
        if(!issq(a[i]))
            ans = max(ans, a[i]);
    }
    cout << ans << "\n";
    
}