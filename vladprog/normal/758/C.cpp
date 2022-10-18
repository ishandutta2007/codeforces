#include<bits/stdc++.h>

#define ll long long
#define g(x,y) f(n,m,k,x,y)

using namespace std;

ll f(ll n,ll m,ll k,ll x,ll y)
{
    ll d=(2*n-2)*m;
    ll res=k/d-1;
    if(res<0)res=0;
    k-=d*res;
    if(x!=1&&x!=n)
        res*=2;
    for(int i=1,t=1;k>0;i+=t,k-=m)
    {
        if(i==x&&k>=y)
            res++;
        if(i==1)
            t=1;
        if(i==n)
            t=-1;
    }
    return res;
}

main()
{
    ll n,m,k,x,y;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&y);
    ll l,r,t;
    if(n==2)
    {
        if(x==2)y+=m;
        m*=2;
    }
    if(n<=2)
    {
        l=r=t=k/m;
        k%=m;
        if(k>=1)
            r+=1;
        if(k>=y)
            t+=1;
        //printf("n=%I64d m=%I64d k=%I64d x=%I64d y=%I64d l=%I64d r=%I64d t=%I64d\n",n,m,k,x,y,l,r,t);
    }
    else
    {
        l=min(min(g(1,m),g(2,m)),min(g(n,m),g(n-1,m)));
        r=max(max(g(1,1),g(2,1)),max(g(n,1),g(n-1,1)));
        t=g(x,y);
    }
    printf("%I64d %I64d %I64d",r,l,t);
}