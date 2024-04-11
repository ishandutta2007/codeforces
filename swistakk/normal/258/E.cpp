#include <iostream>
#include <vector>
#include <algorithm>
#define M 131072
using namespace std;
struct wez
{
    int war;
    int niez;
    int szer;
};
vector<int> slo[M];
wez drz[2*M+5];
int pre[M];
int inv[M];
int roz[M];
int d;
int dfs(int v)
{
    roz[v]=1;
    inv[d]=v;
    pre[v]=d;
    d++;
    for(int i=0; i<slo[v].size(); i++)
    {
        int aktv=slo[v][i];
        if(pre[aktv]==0)
        {
            dfs(aktv);
            roz[v]+=roz[aktv];
        }
    }
}
struct z
{
    int p;
    int k;
    int x;
    int r;
};
z zap[9*M];
bool cmp(z a, z b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    if(a.r!=b.r)
    {
        return a.r<b.r;
    }
    if(a.p!=b.p)
    {
        return a.p<b.p;
    }
    return a.k<b.k;
}
void aktu(int d, int w)
{
    if(drz[d].war>=1)
    {
        drz[d].niez=drz[d].szer;
    }
    else
    {
        if(d>=M)
        {
            drz[d].niez=0;
        }
        else
        {
            drz[d].niez=drz[2*d].niez+drz[2*d+1].niez;
        }
    }
}

void dod(int a, int b, int w)
{
    a+=M-1;
    b+=M-1;
    drz[a].war+=w;
    aktu(a, w);
    
    if(a!=b)
    {
        drz[b].war+=w;
        aktu(b, w);
        
    }
    while(a)
    {
        if(a/2!=b/2)
        {
            if(a%2==0)
            {
                drz[a+1].war+=w;
                aktu(a+1, w);
                
            }
            if(b%2==1)
            {
                drz[b-1].war+=w;
                aktu(b-1, w);
                
            }
        }
        aktu(a, w);
        if(a!=b)
        {
            aktu(b, w);
        }
        a/=2;
        b/=2;
    }
}       
int odp[M];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    int licz=0;
    for(int i=1; i<=n; i++)
    {
        drz[i+M-1].szer=1;
        licz++;
        zap[licz].x=i;
    }
    for(int i=M-1; i>=1; i--)
    {
        drz[i].szer=drz[2*i].szer+drz[2*i+1].szer;
    }
    d=1;
    dfs(1);
    for(int i=1; i<=m; i++)
    {
        int a1, b1;
        cin>>a1>>b1;
        int a2=pre[a1]+roz[a1]-1;
        int b2=pre[b1]+roz[b1]-1;
        a1=pre[a1];
        b1=pre[b1];
        z z1;
        z1.p=a1;
        z1.k=a2;
        z1.x=b1;
        z1.r=-1;
        licz++;
        zap[licz]=z1;
        z1.x=a1;
        licz++;
        zap[licz]=z1;
        z1.r=1;
        licz++;
        z1.x=b2;
        zap[licz]=z1;
        z1.x=a2;
        licz++;
        zap[licz]=z1;
        z1.p=b1;
        z1.k=b2;
        z1.x=a1;
        z1.r=-1;
        licz++;
        zap[licz]=z1;
        z1.x=b1;
        licz++;
        zap[licz]=z1;
        z1.r=1;
        z1.x=a2;
        licz++;
        zap[licz]=z1;
        z1.x=b2;
        licz++;
        zap[licz]=z1;
    }
    sort(zap+1, zap+1+licz, cmp);
    for(int i=1; i<=licz; i++)
    {
        if(zap[i].r==-1)
        {
            dod(zap[i].p, zap[i].k, 1);
        }
        if(zap[i].r==1)
        {
            dod(zap[i].p, zap[i].k, -1);
        }
        if(zap[i].r==0)
        {
            int akt=zap[i].x;
            int czy=0;
            int vx=akt+M-1;
            while(vx)
            {
                if(drz[vx].war)
                {
                    czy=1;
                }
                vx/=2;
            }
            odp[inv[zap[i].x]]=drz[1].niez-czy;
        }
        //cout<<zap[i].x<<" "<<zap[i].r<<" "<<zap[i].p<<" "<<zap[i].k<<endl;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<odp[i]<<" ";
    }
    cout<<endl;
    return 0;
}