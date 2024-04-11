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

const int N=3010;

typedef long long ll;

int n,m,a[N]={0};
void prepare()
{
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d",a+i);
    sort(a+1,a+m+1);
}
int main()
{
    prepare();
    FOR(i,1,m) if (a[i]==1||a[i]==n||(a[i]==a[i+1]-1&&a[i]==a[i+2]-2)) {printf("NO");return 0;}
    printf("YES");
}