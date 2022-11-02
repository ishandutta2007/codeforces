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
struct Node
{
    int c,s,id,bel;
}q[V];
int h[V],dn;
LL s[V];
bool cmp1(Node x,Node y)
{
    if(x.c!=y.c)return x.c<y.c;
    if(x.s!=y.s)return x.s>y.s;
    return x.id<y.id;
}
bool cmp2(Node x,Node y)
{
    if(x.bel!=y.bel)
    {
        if(h[x.bel]!=h[y.bel])
        return h[x.bel]<h[y.bel];
        return x.c<y.c;
    }
    if(x.s!=y.s)return x.s>y.s;
    return x.id<y.id;
}
int n,i,j,hn,Q[V];
LL pre[V];
int rt,OT[V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&q[i].c,&q[i].s);
            q[i].id=i;
        }
        dn=0;
        sort(q,q+n,cmp1);
        s[dn]=q[0].s;h[dn]=1;q[0].bel=0;
        for(i=1;i<n;i++)
        {
            if(q[i].c==q[i-1].c)
            {
                s[dn]+=q[i].s;
                h[dn]++;
            }
            else
            {
                dn++;
                s[dn]=q[i].s;
                h[dn]=1;
            }
            q[i].bel=dn;
        }
        dn++;
        sort(q,q+n,cmp2);
        hn=0;
        LL ans=0;
        int id1=-1,id2=-1;
        q[n].bel=-1;q[n].s=0;
        int pn=1;pre[0]=q[0].s;
        for(i=1;i<=n;i++)
        {
            if(q[i].bel==q[i-1].bel)
            {
                pre[pn]=pre[pn-1]+q[i].s;
                pn++;
            }
            else
            {
                int bl=q[i-1].bel;
                for(j=0;j<hn;j++)
                {
                    if(pre[min(h[Q[j]]+1,h[bl])-1]+s[Q[j]]>ans)
                    {
                        ans=pre[min(h[Q[j]]+1,h[bl])-1]+s[Q[j]];
                        id1=bl;id2=Q[j];
                    }
                }
                if(hn==0||h[bl]>h[Q[hn-1]])
                {
                    Q[hn++]=bl;
                }
                else if(h[bl]==h[Q[hn-1]]&&s[bl]>s[Q[hn-1]])
                {
                    Q[hn-1]=bl;
                }
                pre[0]=q[i].s;pn=1;
            }
        }
        cout<<ans<<endl;
    //  printf("%d %d\n",id1,id2);
        if(h[id1]<h[id2])swap(id1,id2);
        int s1=-1,s2=-2;
        for(i=0;i<n;i++)
        if(q[i].bel==id1){s1=i;break;}
        for(i=0;i<n;i++)
        if(q[i].bel==id2){s2=i;break;}
        rt=0;
        while(1)
        {
            if(s1==n||q[s1].bel!=id1)break;
            else OT[rt++]=q[s1].id+1;
            s1++;
            if(s2==n||q[s2].bel!=id2)break;
            else OT[rt++]=q[s2].id+1;
            s2++;
        }
        printf("%d\n",rt);
        for(i=0;i<rt;i++)
        {
            if(i)printf(" ");
            printf("%d",OT[i]);
        }puts("");
    }
}