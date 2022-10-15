#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a[102], ans=0;
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    a[0]=0;
    a[n+1]=1001;
    for(int i=0, l=1; ++i<=n+1; ans=max((++l)-2, ans))
        if(a[i]>a[i-1]+1)
            l=0;
    cout << ans;
}