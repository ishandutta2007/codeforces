#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, ans=0;
    cin >> n >> m >> k;
    for(; k; --k, n-=4, m-=4)
        ans+=2*(n+m)-4;
    cout << ans;
}