/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
const int N=100001;
const int oo=1000000000;
struct Node
{
    int l,r;
    int cnt,s;
}tr[4*V];
void init(int id,int l,int r)
{
    tr[id].l=l;
    tr[id].r=r;
    tr[id].cnt=tr[id].s=0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(id*2,l,mid);
    init(id*2+1,mid+1,r);
}
void update(int id,int pos, int v)
{
//    printf("%d %d %d %d %d\n",id,tr[id].l,tr[id].r,pos,v);
    if(tr[id].l==pos&&tr[id].r==pos)
    {
        tr[id].s=v;
        tr[id].cnt=1;
        return;
    }
    int mid=(tr[id].l+tr[id].r)/2;
    if(pos<=mid)update(id*2,pos,v);
    else update(id*2+1,pos,v);
    tr[id].s=tr[id*2].s+tr[id*2+1].s;
    tr[id].cnt=tr[id*2].cnt+tr[id*2+1].cnt;
}
int read(int id,int kth)
{
    if(kth<=0)return 0;
    if(tr[id].l==tr[id].r)return tr[id].s;
    if(tr[2*id].cnt>=kth)return read(id*2,kth);
    else return tr[id*2].s+read(id*2+1,kth-tr[id*2].cnt);
}
bool cmprev(int x,int y)
{return x>y;}
int sz[V],p[V];
struct Elf
{
    int x,y,z;
}ee[V];
bool cmpe(Elf x,Elf y)
{
    return x.x<y.x;
}
struct l2id
{
    int l,id;
}lid[V];
bool cmpl(l2id x,l2id y)
{
    return x.l>y.l;
}
vector<int> a[V];
vector<int> pos[V];
int nn,x,y;
int main()
{
    while(~scanf("%d",&nn))
    {
        int base=0;
        for(int i=0;i<=N;i++)
        a[i].clear(),pos[i].clear();
        for(int i=0;i<nn;i++)
        {
            scanf("%d%d",&x,&y);
            if(x==0)base++;
            else
            {
                a[x].push_back(y);
                pos[x].push_back(y);
            }
        }
        for(int i=0;i<N;i++)
        sort(a[i].begin(),a[i].end(),cmprev);
        for(int i=0;i<N;i++)sz[i]=a[i].size();
        memset(p,0,sizeof(p));
        int n=0;
        int nd=0;
        for(int i=0;i<N;i++)
        for(int j=0;j<sz[i];j++)
        {
            ee[n].x=a[i][j];
            ee[n].y=i;
            ee[n++].z=j;
            nd+=a[i][j];
        }
        sort(ee,ee+n,cmpe);
        for(int i=0;i<n;i++)
        pos[ee[i].y][ee[i].z]=i;
        int m=0;
        for(int i=0;i<N;i++)
        if(sz[i]!=0)
        {
            lid[m].l=sz[i];
            lid[m++].id=i;
        }
        sort(lid,lid+m,cmpl);
        init(1,0,n);
        int allp=m-1;
        int ret=nd;
        int free=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++)
        {
            int ex=i-(n-free)-base;
            int tmp=nd+read(1,ex);
            ret=min(ret,tmp);
            //printf("%d %d %d %d %d %d\n",i,free,ex,n,nd,tmp);
            for(int k=allp;k>=0;k--)
            {
                int j=lid[k].id;
            //  printf("%d %d %d %d\n",k,j,pos[j][p[j]],a[j][p[j]]);
                update(1,pos[j][p[j]],a[j][p[j]]);
                nd-=a[j][p[j]];
                free++;
                p[j]++;
                if(p[j]==sz[j])allp=k-1;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}