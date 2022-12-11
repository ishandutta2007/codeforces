#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")
#define inf 1000000

const int N=500;

typedef long long ll;

int h[N]={0},p,n,x;
int main()
{
    scanf("%d%d",&p,&n);
    FOR(i,1,n)
    {
        scanf("%d",&x);
        if (h[x%p])
        {
            cout<<i;
            return 0;
        }else h[x%p]=1;
    }
    printf("-1");
}