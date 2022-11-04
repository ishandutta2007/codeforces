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
const int maxn=200050;
struct node
{
    int val,id;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.val==b.val)
    {
        return a.id<b.id;
    }
    return a.val>b.val;
}

set<int>v;

struct qr
{
    int k,pos,id,ans;
}q[maxn];

bool cc(qr a,qr b)
{
    return a.k<b.k;
}
int b[maxn];
 int n,m;
void add(int pos)
{
    while(pos<=n)
    {
        b[pos]++;
        pos+=(pos&-pos);
    }
}
int query(int x)
{
    int rt=0;
    while(x>=1)
    {
        rt+=b[x];
        x-=(x&-x);
    }
    return rt;
}

int solve(int pos)
{
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(query(mid)>=pos)
            r=mid;
        else
            l=mid+1;
//        cout<<l<<' ';
    }
//    if(query(l-1)>=pos)
//        return l-1;
//    if(query(l)>=pos)
//        return l;
    return l;
}
int d[maxn],e[maxn];
int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        a[i].val=b;
        a[i].id=i;
        e[i]=b;
    }
    sort(a+1,a+n+1,cmp);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].k>>q[i].pos;
        q[i].id=i;
        q[i].ans=0;
    }
    sort(q+1,q+m+1,cc);
    int p=0;
    for(int i=1;i<=m;i++)
    {
        
        while(p<q[i].k)
        {
            p++;
            add(a[p].id);
        }
//        cout<<i<<' ';
        q[i].ans=solve(q[i].pos);
//        cout<<q[i].k<<' '<<q[i].pos<<' '<<q[i].ans<<endl;
    }
   
    for(int i=1;i<=m;i++)
    {
        d[q[i].id]=q[i].ans;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<e[d[i]]<<endl;
    }
    return 0;
}