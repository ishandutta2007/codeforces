#include <bits/stdc++.h>
using namespace std;

int n, r, a[1000], nc, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    while(nc<n) {
        int b=-1;
        for(int i=min(nc+r-1, n-1); i>=max(nc-r+1, 0)&&b==-1; --i)
            if(a[i])
                b=i;
        if(b==-1)
            break;
        nc=b+r;
        ++ans;
    }
    cout << (nc>=n?ans:-1);
}