#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100,MOD=1e9+7;

typedef array<int,2> row;
typedef array<row,2> matr;

row mult(row a,matr b)
{
    row res={0,0};
    for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
            res[k]=(res[k]+a[j]*b[j][k])%MOD;
    return res;
}

matr mult(matr a,matr b)
{
    matr res={row{0,0},
              row{0,0}};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                res[i][k]=(res[i][k]+a[i][j]*b[j][k])%MOD;
    return res;
}

unordered_map<int,matr> mem;

matr ppow(matr a,int b)
{
    if(mem.count(b))
        return mem[b];
    matr&res=mem[b]={row{1,0},
                     row{0,1}};
    while(b)
    {
        if(b&1)
            res=mult(res,a);
        b>>=1;
        a=mult(a,a);
    }
    return res;
}

row add(row a,row b)
{
    return {(a[0]+b[0])%MOD,(a[1]+b[1])%MOD};
}

const row start={1,0};

const matr one={row{0,1},
                row{1,1}};

int a[N];
row t[4*N];
int p[4*N];

void build(int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=mult(start,ppow(one,a[tl]));
    else
    {
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=add(t[v*2],t[v*2+1]);
    }
}

void push(int v,int tl,int tr)
{
    if(!p[v])
        return;
    t[v]=mult(t[v],ppow(one,p[v]));
    if(tl<tr)
    {
        p[v*2]+=p[v];
        p[v*2+1]+=p[v];
    }
    p[v]=0;
}

void upd(int v,int tl,int tr,int l,int r,int x)
{
    push(v,tl,tr);
    if(l==tl&&r==tr)
    {
        p[v]+=x;
        push(v,tl,tr);
        return;
    }
    int tm=(tl+tr)/2;
    if(r<=tm)
        upd(v*2,tl,tm,l,r,x),
        push(v*2+1,tm+1,tr);
    else if(l>=tm+1)
        push(v*2,tl,tm),
        upd(v*2+1,tm+1,tr,l,r,x);
    else
        upd(v*2,tl,tm,l,tm,x),
        upd(v*2+1,tm+1,tr,tm+1,r,x);
    t[v]=add(t[v*2],t[v*2+1]);
}

int get(int v,int tl,int tr,int l,int r)
{
    push(v,tl,tr);
    if(l==tl&&r==tr)
        return t[v][1];
    int tm=(tl+tr)/2;
    if(r<=tm)
        return get(v*2,tl,tm,l,r);
    else if(l>=tm+1)
        return get(v*2+1,tm+1,tr,l,r);
    else
        return (get(v*2,tl,tm,l,tm)+
                get(v*2+1,tm+1,tr,tm+1,r))%MOD;
}

#define read(x) scanf("%I64d",&(x))
#define write(x) printf("%I64d\n",x)

signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n,m;
    read(n),read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    build(1,1,n);
    while(m--)
    {
        int tp,l,r;
        read(tp),read(l),read(r);
        if(tp==1)
        {
            int x;
            read(x);
            upd(1,1,n,l,r,x);
        }
        else
            write(get(1,1,n,l,r));
    }
}