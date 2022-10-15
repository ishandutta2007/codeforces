#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, h, x[mxN][2], ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> h, --h;
    for(int i=0; i<n; ++i)
        cin >> x[i][0] >> x[i][1];
    for(int i1=n-1, i2=n-1, s=0; i1>=0; --i1) {
        s+=x[i1][1]-x[i1][0];
        while(x[i1][0]+h+s<x[i2][1]) {
            s-=x[i2][1]-x[i2][0];
            --i2;
        }
        ans=max(h+s, ans);
    }
    cout << ans+1;
}