#include <bits/stdc++.h>
using namespace std;
int v[200005];
struct ura
{
    int st,dr;
}a[200005];
int fv[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,t,s=0;
    cin>>n>>i;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(a[v[i]].st==0)
            a[v[i]].st=i;
        a[v[i]].dr=i;
    }
    int st=1,dr=1;
    while(st<=n)
    {
        int drc=a[v[st]].dr;
        for(dr=st;dr<=drc;++dr)
            drc=max(drc,a[v[dr]].dr);
        --dr;
        int x=0;
        for(i=st;i<=dr;++i)
        {
            ++fv[v[i]];
            x=max(x,fv[v[i]]);
        }
        for(i=st;i<=dr;++i)
            --fv[v[i]];
        s+=dr-st+1-x;
        st=dr+1;
    }
    cout<<s;
    return 0;
}