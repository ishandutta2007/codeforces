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
const int maxn=1000005;

struct node
{
    int sum,ma,mi;
    
}a[maxn<<2];

void pushup(int rt)
{
    a[rt].sum=a[lr].sum+a[rr].sum;
    a[rt].mi=min(a[lr].mi,a[lr].sum+a[rr].mi);
    a[rt].ma=max(a[lr].ma,a[lr].sum+a[rr].ma);
}
void build(int rt,int l,int r)
{
    if(l==r)
    {
        a[rt].sum=0;
        a[rt].mi=0;
        a[rt].ma=0;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,int x,int pos)
{
    if(l==r)
    {
        a[rt].sum=a[rt].mi=a[rt].ma=x;
//        cout<<a[rt].sum<<endl;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(lr,l,mid,x,pos);
    else
        update(rr,mid+1,r,x,pos);
    pushup(rt);
//    cout<<a[rt].sum<<' ';
}
string s;

int main()
{
    sync;
    int n;
    cin>>n;
    build(1,1,n);
    cin>>s;
    int pos=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
            pos=max(1,pos-1);
        else if(s[i]=='R')
            pos++;
        else if(s[i]=='(')
            update(1,1,n,1,pos);
        else if(s[i]==')')
            update(1,1,n,-1,pos);
        else
            update(1,1,n,0,pos);
        if(a[1].sum==0&&a[1].mi>=0)
        {
            cout<<a[1].ma<<' ';
        }
        else
            cout<<-1<<' ';
    }
    cout<<endl;
    return 0;
}