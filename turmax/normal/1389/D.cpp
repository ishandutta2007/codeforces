#include <bits/stdc++.h>

using namespace std;
#define int long long
int perec(pair <int,int> a,pair <int,int> b)
{
    return max(0LL,min(a.second,b.second)-max(a.first,b.first));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    int h0=(k-perec({l1,r1},{l2,r2})*n);
    //cout<<h0<<" h0 "<<endl;
    if(h0<=0) {cout<<0<<endl;continue;}
    int o=abs(l2-l1)+abs(r2-r1);
    int f=max(0LL,max(l2-r1,l1-r2));
    //cout<<o<<" o "<<f<<" f "<<endl;
    int r=(max(r1,r2)-min(l1,l2));
    if(r*n<k)
    {
        int z=k-r*n;
        int z1=h0-(o-f);
        cout<<min(o*n+2*z,2*z1+o)<<endl;
        continue;
    }
    int s1=h0/(o-f);
    int d=h0-s1*(o-f);
    int ans1=(s1*o);
    if(d==0)
    {
        cout<<ans1<<endl;continue;
    }
    if(s1!=0)
    cout<<min(ans1+d+f,ans1+2*d)<<endl;
    else
    cout<<ans1+d+f<<endl;
    }
    return 0;
}