#include <bits/stdc++.h>
using namespace std;
int vn[10];
int vi[100005];
int fv[100005];
struct ura
{
    int val,pz;
}v[600005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int add (int pz)
{
    ++fv[v[pz].pz];
    if(fv[v[pz].pz]==1)
        return 1;
    return 0;
}
int scoate (int pz)
{
    --fv[v[pz].pz];
    if(fv[v[pz].pz]==0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j,k=0;
    for(i=1;i<=6;++i)
        cin>>vn[i];
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>vi[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=6;++j)
            v[++k]={vi[i]-vn[j],i};
    sort(v+1,v+n*6+1,cmp);
    int st=1,dr=0;
    int cntc=0;
    int rz=1000000000;
    while(st<=n*6)
    {
        while(cntc<n && dr<n*6)
            cntc+=add(++dr);
        if(cntc<n)
            break;
        rz=min(rz,v[dr].val-v[st].val);
        cntc-=scoate(st++);
    }
    cout<<rz;
    return 0;
}