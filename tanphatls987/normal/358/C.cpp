#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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

const int N=100010;

typedef long long ll;

int n,v,a[4]={0},c[N];
void pushin(int i)
{
    int key=((a[3]<a[1])?3:1);
    if (c[i]<=a[key]) {printf("pushBack\n");return;}
    a[key]=c[i];
    switch (key)
    {
        case 1:{printf("pushStack");break;}
        //case 2:{printf("pushQueue");break;}
        case 3:{printf("pushFront");break;}
    }
    ENDL;
}
void extract()
{
    printf("%d",(a[1]>0)+(a[2]>0)+(a[3]>0));
    if (a[1]) printf(" popStack");
    if (a[2]) printf(" popQueue");
    if (a[3]) printf(" popFront");
    ENDL;
    a[1]=a[2]=a[3]=0;
}
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&c[i]);
    FOR(i,1,n)
    {
        int ma=i,j;
        for(j=i;j<=n&&c[j]>0;j++) if (c[ma]<c[j]) ma=j;
        a[2]=c[ma];
        FOR(k,i,j-1) if (k!=ma) pushin(k);else printf("pushQueue\n");
        if (j<=n) extract();
        i=j;
    }
}