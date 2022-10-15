#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
int n, m, a[mxN], mx, mn;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> a[i], mx=max(a[i], mx);
    mn=mx;
    mx+=m;
    while(m) {
        int mi=0;
        for(int i=1; i<n; ++i)
            if(a[i]<a[mi])
                mi=i;
        --m;
        ++a[mi];
        mn=max(a[mi], mn);
    }
    cout << mn << " " << mx;
}