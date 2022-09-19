#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int pr1[n];pr1[0]=0;for(int i=1;i<n;++i) {pr1[i]=pr1[i-1]+max(0LL,a[i-1]-a[i]);}
    int pr2[n];pr2[n-1]=0;for(int i=n-2;i>=0;--i) {pr2[i]=pr2[i+1]+max(0LL,a[i+1]-a[i]);}
    while(q--)
    {
        int s,t;cin>>s>>t;--s;--t;
        if(s<t) cout<<pr1[t]-pr1[s]<<'\n';
        else cout<<pr2[t]-pr2[s]<<'\n';
    }
    return 0;
}