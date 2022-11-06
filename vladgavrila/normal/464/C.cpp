#include <cstdio>
#include <iostream>

using namespace std;

#define maxn 100010
#define mod 1000000007

int n, m, x, y;
long long lg[10], val[10];
string s, cmd[maxn];

int lgput(int nr, long long exp)
{
    if(exp==0)
        return 1;

    int aux=lgput(nr, exp/2);

    aux=(1LL*aux*aux)%mod;
    if(exp%2)
        aux=(1LL*aux*nr)%mod;

    return aux;
}

int main()
{
    cin>>s;
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>cmd[i];

    for(int i=0; i<10; ++i)
    {
        lg[i]=1;
        val[i]=i;
    }

    for(int p=n; p>0; --p)
    {
        x=cmd[p][0]-'0';
        long long vl=0, llg=0, y;

        m=cmd[p].size();
        for(int i=3; i<m; ++i)
        {
            y=cmd[p][i]-'0';
            if(y>=0 && y<10)
            {
                vl=(1LL*vl*lgput(10, lg[y])+val[y])%mod;
                llg+=lg[y];
                while(llg>=mod-1)
                    llg-=mod-1;
            }
        }

        val[x]=vl;
        lg[x]=llg;
    }

    m=s.size();
    long long vl=0, llg=0, y;

    for(int i=0; i<m; ++i)
    {
        y=s[i]-'0';
        if(y>=0 && y<10)
            vl=(1LL*vl*lgput(10, lg[y])+val[y])%mod;
    }

    cout<<vl<<"\n";


    return 0;
}