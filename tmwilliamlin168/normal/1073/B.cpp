#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, a[mxN], bi;
bool c[mxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i], --a[i];
    for(int i=0, j=0; i<n; ++i) {
        cin >> bi, --bi;
        int ans=0;
        while(!c[bi]) {
            c[a[j++]]=1;
            ++ans;
        }
        cout << ans << " ";
    }
}