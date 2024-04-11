#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
bool perec(int l1,int r1,int l2,int r2)
{
    return max(l1,l2)<=min(r1,r2);
}
int comp(int l1,int r1,int l2,int r2)
{
    int o=max(0LL,min(r1,r2)+1-max(l1,l2));
    int z=inv(((r1-l1+1)*(r2-l2+1))%p);
    return ((1-(o*z)%p)+p)%p;
}
int comp2(int l1,int r1,int l2,int r2,int l3,int r3)
{
    int z1=comp(l1,r1,l2,r2);int z2=comp(l2,r2,l3,r3);
    if(!perec(l1,r1,l2,r2)) {return z2;}
    if(!perec(l2,r2,l3,r3)) {return z1;}
    if(!perec(l1,r1,l3,r3)) {return (z1+z2-1)%p;}
    int h=1;h*=inv(r1-l1+1);h%=p;h*=inv(r2-l2+1);h%=p;h*=inv(r3-l3+1);h%=p;
    int o=min({r1,r2,r3})-max({l1,l2,l3})+1;
    return ((z1+z2-1+(o*h))%p+p)%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    int c[n-1];int sum=0;
    for(int i=0;i<n-1;++i) {c[i]=comp(a[i],b[i],a[i+1],b[i+1]);sum+=c[i];sum%=p;}
    int ans=((sum+1)*(sum+1))%p;
    for(int i=0;i<n-1;++i) {ans-=(c[i]*c[i])%p;ans+=(c[i]%p);ans%=p;}
    for(int i=0;i<n-2;++i) {ans-=(2*c[i]*c[i+1])%p;int f=comp2(a[i],b[i],a[i+1],b[i+1],a[i+2],b[i+2]);ans+=(2*f);ans%=p;}
    cout<<(ans%p+p)%p;
    return 0;
}