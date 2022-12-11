#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
//#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=0;

typedef long long ll;

int x1,y1,x2,y2,x3,y3,x4,y4,d1,d2;
int main()
{
    cin>>x1>>y1>>x2>>y2;
    d1=abs(x1-x2);d2=abs(y1-y2);
    if (d1&&d2&&d1!=d2) {printf("-1");return 0;}
    if (d1&&d2)
    {
        x3=x1;y3=y2;
        x4=x2;y4=y1;
    }
    if (d1==0)
    {
        x3=x4=x2+d2;
        y3=y1;
        y4=y2;
    }
    if (d2==0)
    {
        y3=y4=y1+d1;
        x3=x1;
        x4=x2;
    }
    printf("%d %d %d %d",x3,y3,x4,y4);
}