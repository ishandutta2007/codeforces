#include <iostream>
#include <algorithm>

using namespace std;

int c[15];

int main() {
    int n,l,r,x;
    cin >> n >> l >> r >> x;
    for (int i=0;i<n;i++) cin >> c[i];
    int ans = 0;
    for (int i=0;i<(1<<n);i++) {
        int cur = 0;
        int a = 1e7, b = 0;
        for (int j=0;j<n;j++) if (i&(1<<j)) a = min(a,c[j]), b = max(b,c[j]), cur+=c[j];
        if (b-a<x || cur<l || cur>r) continue;
        ans+=1;
    }
    cout << ans;

    return 0;
}