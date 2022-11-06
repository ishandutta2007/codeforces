#include <iostream>

using namespace std;

#define maxn 63

long long n, m, w, sol;
long long tp[maxn][maxn];
long long p2[maxn];

long long solve(long long lg, int nr, int k)
{
    if(k<0 || nr<0)
        return 0;
    if(lg>=p2[nr])
        return tp[nr][k];

    if(lg<=p2[nr-1])
        return solve(lg, nr-1, k);

    return solve(lg, nr-1, k)+solve(lg-p2[nr-1], nr-1, k-1);
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);
    cin>>n>>m;
    ++n;

    p2[0]=1;
    for(int i=1; i<maxn; ++i)
        p2[i]=p2[i-1]*2;

    long long x=1, pt=0;

    while(x<m)
    {
        ++pt;
        x*=2;
    }

    if(x!=m)
    {
        cout<<"0\n";
        return 0;
    }

    w=pt;

    tp[0][0]=1;

    for(int i=1; i<maxn-1; ++i)
    {
        tp[i][0]=1;
        for(int j=1; j<maxn-1; ++j)
            tp[i][j]=tp[i-1][j]+tp[i-1][j-1];
    }

    x=1; pt=0;

    while(n>0)
    {
        sol+=solve(n, pt, w);
        n-=p2[pt];
        ++pt;
    }

    if(m==1)
        --sol;

    cout<<sol<<"\n";

    return 0;
}