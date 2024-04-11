#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int a[n];bool ok1=0,ok2=1;for(int i=0;i<n;++i) {cin>>a[i];ok1|=a[i];ok2&=a[i];}
        if(n>=k) {puts(ok1 ? "YES" : "NO");} else {puts(ok2 ? "YES" : "NO");}
    }
    return 0;
}