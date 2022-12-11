#include <bits/stdc++.h>
using namespace std;
int ok;
struct ura
{
    int x,y,u,v;
}v[100005];
map<int,int>newvalue;
int vall[400005];
bool cmp (ura a, ura b)
{
    return a.x<b.x;
}
int lsb (int x)
{
    return x&-x;
}
int aibmx[500005],aibmn[500005]; /// u->mx | v->mn
void updatemx (int pz, int val)
{
    for(int i=pz;i<=500000;i+=lsb(i))
        if(aibmx[i]==0 || v[aibmx[i]].u<v[val].u)
            aibmx[i]=val;
}
void updatemn (int pz, int val)
{
    for(int i=pz;i<=500000;i+=lsb(i))
    {
        if(aibmn[i]==0 || v[aibmn[i]].v>v[val].v)
            aibmn[i]=val;
    }
}
int querymx (int pz)
{
    int rz=0;
    for(int i=pz;i>=1;i-=lsb(i))
    {
        if(rz!=0 && aibmx[i]==0)
            continue;
        if(rz==0 || v[aibmx[i]].u>v[rz].u)
            rz=aibmx[i];
    }
    return rz;
}
int querymn (int pz)
{
    int rz=0;
    for(int i=pz;i>=1;i-=lsb(i))
    {
        if(rz!=0 && aibmn[i]==0)
            continue;
        if(rz==0 || v[aibmn[i]].v<v[rz].v)
            rz=aibmn[i];
    }
    return rz;
}
void verif (int b, int a)
{
    if(max(v[a].x,v[b].x)<=min(v[a].y,v[b].y) && max(v[a].u,v[b].u)>min(v[a].v,v[b].v))
        ok=1;
    if(max(v[a].x,v[b].x)>min(v[a].y,v[b].y) && max(v[a].u,v[b].u)<=min(v[a].v,v[b].v))
        ok=1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    long long n,w,t,i,j,k=0,pas=1<<15,mod,sc,cnt=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].x>>v[i].y>>v[i].u>>v[i].v;
        vall[++k]=v[i].x;
        vall[++k]=v[i].y;
        vall[++k]=v[i].u;
        vall[++k]=v[i].v;
    }
    sort(vall+1,vall+k+1);
    j=0;
    for(i=1;i<=k;++i)
    {
       if(i==1 || vall[i]!=vall[i-1])
            ++j;
        newvalue[vall[i]]=j;
    }
    for(i=1;i<=n;++i)
    {
        v[i].x=newvalue[v[i].x];
        v[i].y=newvalue[v[i].y];
        v[i].u=newvalue[v[i].u];
        v[i].v=newvalue[v[i].v];
    }
    sort(v+1,v+n+1,cmp);/// n*4-a+100;
    for(i=1;i<=n;++i)
    {
        int valmx=querymx(n*4-v[i].x+100);
        if(valmx!=0)
            verif(valmx,i);
        int valmn=querymn(n*4-v[i].x+100);
        if(valmn!=0)
            verif(valmn,i);
        updatemx(n*4-v[i].y+100,i);
        updatemn(n*4-v[i].y+100,i);
    }
    for(i=1;i<=n;++i)
    {
        swap(v[i].x,v[i].u);
        swap(v[i].y,v[i].v);
    }
    for(i=0;i<=500000;++i)
        aibmx[i]=aibmn[i]=0;
    sort(v+1,v+n+1,cmp);/// n*4-a+100;
    for(i=1;i<=n;++i)
    {
        int valmx=querymx(n*4-v[i].x+100);
        if(valmx!=0)
            verif(valmx,i);
        int valmn=querymn(n*4-v[i].x+100);
        if(valmn!=0)
            verif(valmn,i);
        updatemx(n*4-v[i].y+100,i);
        updatemn(n*4-v[i].y+100,i);
    }
    if(ok)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}