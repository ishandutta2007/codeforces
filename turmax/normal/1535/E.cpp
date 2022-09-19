#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int b[maxn];
int c[maxn];
int pr[maxn];
int u[maxn][20];
int sum1[maxn];int sum2[maxn];
int dep[maxn];
int pred(int x,int to)
{
    if(to==0) return x;
    if(to==1) return pr[x];
    for(int i=1;i<20;++i)
    {
        if((1<<i)>to)
        {
            return pred(u[x][i-1],to-(1<<(i-1)));
        }
    }
}
int finotzero(int x)
{
    if(x==0 || sum1[pr[x]]==0) return x;
    for(int i=1;i<20;++i)
    {
        if(sum1[u[x][i]]==0)
        {
            return finotzero(u[x][i-1]);
        }
    }
}
pair <int,int> get(int v,int w)
{
    if(w==0) return {0,0};
    if(sum1[v]==0) return {0,0};
    int h=finotzero(v);
    if(b[h]>w)
    {
        b[h]-=w;
        return {w,w*c[h]};
    }
    else
    {
        int o=b[h];
        b[h]=0;
        sum1[h]=0;
        pair <int,int> ans1=get(v,w-o);
        return {ans1.first+o,ans1.second+o*c[h]};
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pr[0]=(-1);dep[0]=0;
    for(int i=0;i<20;++i) u[0][i]=(-1);
    int q;
    cin>>q>>b[0]>>c[0];
    sum1[0]=b[0];sum2[0]=b[0]*c[0];
    for(int curr=1;curr<=q;++curr)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int p,b2,c2;
            cin>>p>>b2>>c2;
            pr[curr]=p;
            b[curr]=b2;c[curr]=c2;
            sum1[curr]=sum1[p]+b2;sum2[curr]=sum2[p]+b2*c2;
            dep[curr]=dep[p]+1;
            u[curr][0]=p;
            for(int i=1;i<20;++i)
            {
                if(u[curr][i-1]==(-1)) u[curr][i]=(-1);
                else u[curr][i]=u[u[curr][i-1]][i-1];
            }
            fflush(stdout);
        }
        else
        {
            int v,w;
            cin>>v>>w;
            pair <int,int> ans=get(v,w);
            cout<<ans.first<<' '<<ans.second<<endl;
        }
    }
    return 0;
}