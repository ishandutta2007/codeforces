#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int cnt1=0,cnt2=0;for(int i=0;i<n;++i) {if(a[i]<0) cnt2++; else cnt1++;}
        for(int i=0;i<cnt2;++i) a[i]=(-abs(a[i]));
        for(int i=cnt2;i<n;++i) a[i]=abs(a[i]);
        cout<<(is_sorted(a,a+n) ? "YES" : "NO")<<'\n';
    }
    return 0;
}