#include <bits/stdc++.h>
using namespace std;

int t, n, k, z, a[100000];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k >> z;
        for(int i=0; i<n; ++i)
            cin >> a[i];
        int ans=0;
        for(int left=0; left<=z; ++left) {
            int border=k-2*left, sum=0, mxLeft=0;
            for(int i=0; i<=border; ++i) {
                sum+=a[i];
                mxLeft=max(a[i]+a[i+1], mxLeft);
            }
            ans=max(sum+mxLeft*left, ans);
        }
        cout << ans << "\n";
    }
}