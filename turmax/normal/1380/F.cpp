#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=5e5+5;
int t[4*maxn][2][2];
int ans[20];
int z[maxn];
void upd(int node,int tl,int tr)
{
   int tm=(tl+tr)/2;
   for(int f=0;f<2;++f)
   {
       for(int s=0;s<2;++s)
       {
           if(z[tm-1]==1)
           t[node][f][s]=t[2*node+1][f][0]*t[2*node+2][0][s]+((t[2*node+1][f][1]*t[2*node+2][1][s])%p)*ans[z[tm]+10*z[tm-1]];
           else
           t[node][f][s]=t[2*node+1][f][0]*t[2*node+2][0][s];
           t[node][f][s]%=p;
       }
   }
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        t[node][0][0]=ans[z[tl]];
        t[node][1][0]=1;
        t[node][0][1]=1;
        t[node][1][1]=0;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    upd(node,tl,tr);
}
void to(int node,int tl,int tr,int pos,int x)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        t[node][0][0]=ans[z[tl]];
        t[node][1][0]=1;
        t[node][0][1]=1;
        t[node][1][1]=0;
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,x);to(2*node+2,tm,tr,pos,x);
    upd(node,tl,tr);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            ans[i+j]++;
        }
    }
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        z[i]=s[i]-'0';
    }
    build(0,0,n);
    for(int i=0;i<m;++i)
    {
        int pos,x;
        cin>>pos>>x;
        pos--;
        z[pos]=x;
        to(0,0,n,pos,x);
        cout<<(t[0][0][0]%p+p)%p<<'\n';
    }
    return 0;
}