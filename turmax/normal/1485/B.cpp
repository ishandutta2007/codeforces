#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q,k;
    cin>>n>>q>>k;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int pr[n-1];
    pr[0]=0;
    for(int i=0;i<(n-2);++i)
    {
        pr[i+1]=pr[i]+a[i+2]-a[i]-2;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r) {cout<<(k-1)<<endl;continue;}
        //cout<<l<<" l "<<r<<" r "<<endl;
        cout<<pr[r-2]-pr[l-1]+(a[l]-2)+(k-a[r-2]-1)<<endl;
    }
    return 0;
}