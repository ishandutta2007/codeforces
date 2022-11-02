#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int MAX=100100;
struct Node
{
    int l,r;
    int nu;
    LL s[5];
}p[MAX*4];
int b[MAX],a[MAX],r[MAX],va[MAX];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    p[nu].nu=0;
    for(int i=0;i<5;i++)
    p[nu].s[i]=0;
    if(l==r)return;
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
}
void Up(int nu)
{
    p[nu].nu=p[nu*2].nu+p[nu*2+1].nu;
    int d=p[nu*2].nu%5;
    for(int i=0;i<5;i++)
    {
        p[nu].s[i]=p[nu*2].s[i]+p[nu*2+1].s[(i-d+5)%5];
    }
}
void update(int nu,int po,int flag)
{
    if(p[nu].l==po&&p[nu].r==po)
    {
        if(flag==1)
        {p[nu].nu=1;p[nu].s[0]=va[p[nu].l];}
        else
        {p[nu].nu=0;p[nu].s[0]=0;}
        return;
    }
    int mid=(p[nu].l+p[nu].r)/2;
    if(po<=mid)update(nu*2,po,flag);
    else update(nu*2+1,po,flag);
    Up(nu);
//  printf("%d %d %d  ",nu,p[nu].l,p[nu].r);
//  for(int i=0;i<5;i++)cout<<p[nu].s[i]<<" ";puts("");
}
int n;
bool cmp(int x,int y)
{return b[x]<b[y];}
void lisan()
{
    sort(r,r+n,cmp);
    int pre=b[r[0]];
    int M=1;
    a[r[0]]=M;va[1]=pre;
    for(int i=1;i<n;i++)
    {
        if(pre!=b[r[i]])
        {pre=b[r[i]];M++;va[M]=pre;}
        a[r[i]]=M;
    }
}
int i,Q[MAX];
char ch[120];
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='a')Q[i]=0;
            else if(ch[0]=='d')Q[i]=1;
            else Q[i]=2;
            if(Q[i]!=2)
            {
                scanf("%d",&b[i]);
                r[i]=i;
            }
            else b[i]=1;
        }
        lisan();
    //  puts("OK");
        init(1,1,n);
        for(i=0;i<n;i++)
        {
            if(Q[i]==0)
            {
                update(1,a[i],1);
            }
            else if(Q[i]==1)
            {
                update(1,a[i],-1);
            }
            else cout<<p[1].s[2]<<endl;
        }
    }
}