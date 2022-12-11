#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

typedef long long ll;

#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")

using namespace std;

const int maxd=110;

int n,m;
char a[maxd][maxd];
int prepare()
{
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
}
int solve()
{
    FOR(i,1,n)
    {
        REP(j,0,m) if (a[i][j]!='-')
        {
            if ((i+j)%2) a[i][j]='B';else a[i][j]='W';
        }
    }
    FOR(i,1,n) printf("%s\n",a[i]);
}
int main()
{
    prepare();
    solve();
}