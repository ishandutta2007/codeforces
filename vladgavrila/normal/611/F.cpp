#include <cstdio>
#include <iostream>

using namespace std;

#define maxn 1000010
#define mod 1000000007

int n, m, nmoves, hx, wy;
int x[maxn];
int y[maxn];
int tp[maxn];
int xmin, ymin, xmax, ymax;
int sol;
string s;

void addMove(int xlm, int ylm, int tlm)
{
    ++nmoves;
    x[nmoves%maxn]=xlm;
    y[nmoves%maxn]=ylm;
    tp[nmoves%maxn]=tlm;
}

int main()
{
    cin>>n>>hx>>wy;
    cin>>s;

    for(int i=0; i<n; ++i)
    {
        tp[++nmoves]=1;
        if(s[i]=='U')
            x[nmoves]=-1;
        else
        if(s[i]=='D')
            x[nmoves]=1;
        else
        if(s[i]=='L')
            y[nmoves]=-1;
        else
        if(s[i]=='R')
            y[nmoves]=1;
    }

    int xlm=0, ylm=0, tlm=0;
    int xx=0, yy=0, tt=0;

    for(int i=1; i<=nmoves && hx>0 && wy>0; ++i)
    {
        int xc=x[i%maxn];
        int yc=y[i%maxn];
        int tc=tp[i%maxn];
        xx+=xc; xlm+=xc;
        yy+=yc; ylm+=yc;
        tt=(tt+tc)%mod; tlm=(tlm+tc)%mod;

        if(xx<xmin || xx>xmax)
        {
            --hx;
            sol = (sol + 1LL * tt * wy) % mod;
            xmin = min(xmin, xx);
            xmax = max(xmax, xx);

            addMove(xlm, ylm, tlm);
            xlm=ylm=tlm=0;
        }
        else
        if(yy<ymin || yy>ymax)
        {
            --wy;
            sol = (sol + 1LL * tt * hx) % mod;
            ymin = min(ymin, yy);
            ymax = max(ymax, yy);

            addMove(xlm, ylm, tlm);
            xlm=ylm=tlm=0;
        }
    }

    if(hx>0 && wy>0)
    {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<sol<<"\n";

    return 0;
}