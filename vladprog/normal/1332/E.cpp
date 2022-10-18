#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=998244353;

typedef array<int,2> row;
typedef array<row,2> matr;

matr mult(matr x,matr y)
{
    matr res;
    res[0][0]=res[1][1]=0;
    res[0][1]=res[1][0]=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int t=0;t<2;t++)
                res[i][t]+=x[i][j]*y[j][t];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            res[i][j]%=MOD;
    return res;
}

matr ppow(matr x,int y)
{
    matr res;
    res[0][0]=res[1][1]=1;
    res[0][1]=res[1][0]=0;
    while(y)
    {
        if(y&1)
            res=mult(res,x);
        y>>=1;
        x=mult(x,x);
    }
    return res;
}

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,l,r;
    cin>>n>>m>>l>>r;
    int s=n*m,k=r-l+1;
    int d,e;
    if(k%2==0)
        d=e=k/2;
    else if(l%2==0)
        e=(k+1)/2,
        d=k/2;
    else
        e=k/2,
        d=(k+1)/2;
    k%=MOD,d%=MOD,e%=MOD;
    if(s%2==1)
        cout<<ppow(k,s);
    else
    {
        matr base;
        base[0][0]=base[1][1]=e;
        base[0][1]=base[1][0]=d;
//        cout<<base[0][0]<<base[0][1]<<"\n";
//        cout<<base[1][0]<<base[1][1]<<"\n";
        matr res=ppow(base,s);
//        cout<<res[0][0]<<res[0][1]<<"\n";
//        cout<<res[1][0]<<res[1][1]<<"\n";
        cout<<res[0][0]<<"\n";
    }
}