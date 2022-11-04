//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
 
int n;
struct node
{
    int l,r,lazy,len,sum;
}a[maxn<<2];
void pushup(int rt)
{
    a[rt].sum=a[lr].sum+a[rr].sum;
}
void build(int rt,int l,int r)//1,n,
{
    a[rt].l=l;
    a[rt].r=r;
    a[rt].len=r-l+1;
    a[rt].lazy=0;
    if(l==r)
    {
        a[rt].sum=0;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}
void pushdown(int rt)//
{
    if(a[rt].lazy)
    {
        a[lr].sum=a[lr].len;
        a[lr].lazy+=a[rt].lazy;
        a[rr].sum=a[rr].len;
        a[rr].lazy+=a[rt].lazy;
        a[rt].lazy=0;
    }
}
void add(int rt,int L,int R,int s)//
{
    if(a[rt].l==L&&a[rt].r==R)
    {
        a[rt].sum=a[rt].len;
        a[rt].lazy+=s;
        return;
    }
    pushdown(rt);//
    int mid=(a[rt].l+a[rt].r)/2;
    if(mid>=R)
        add(lr,L,R,s);
    else if(mid<L)//
        add(rr,L,R,s);
    else
    {
        add(lr,L,mid,s);
        add(rr,mid+1,R,s);
    }
    pushup(rt);
}
int query(int rt,int L,int R)//
{
    if(a[rt].l==L&&a[rt].r==R)
    {
        return a[rt].sum;
    }
    pushdown(rt);
    int mid=(a[rt].l+a[rt].r)/2;
    if(mid>=R)
        return query(lr,L,R);
    else if(mid<L)
        return query(rr,L,R);
    return query(lr,L,mid)+query(rr,mid+1,R);
}
 
int aa[maxn];
struct Node
{
    int l,r,v;
}s[maxn];
bool cmp(Node a,Node b)
{
    return a.v>b.v;
}
int main()
{
    sync;
    int m,k,t;
    cin>>m>>n>>k>>t;
    for(int i=0;i<m;i++)
    {
        cin>>aa[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>s[i].l>>s[i].r>>s[i].v;
    }
    t=t-n-1;
    sort(s,s+k,cmp);
    int qw=0;
    int sss=9999999;
    build(1,1,n);
    for(int i=0;i<k;i++)
    {
        add(1,s[i].l,s[i].r,1);
        qw=query(1,1,n);
        sss=s[i].v;
        if(qw*2>t)
            break;
        sss=0;
    }
//    cout<<sss<<endl;
    sort(aa,aa+m);
    cout<<m-(lower_bound(aa,aa+m,sss)-aa)<<endl;
    return 0;
}