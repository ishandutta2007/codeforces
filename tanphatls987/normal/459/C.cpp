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

const int N=1010;

typedef long long ll;

int a[N][N],n,num,d,k,p[N]={0},h;
int check()
{
    int c=1;
    FOR(i,1,d) {c*=k;if (c>=n) return i;}
    return 0;
}
void make_st(int day)
{
    if (num==0) return;
    if (day>h)
    {
        FOR(i,1,h) a[i][num]=p[i];
        num--;
        return;
    }
    FOR(i,1,min(k,n))
    {
        p[day]=i;
        make_st(day+1);
    }
}
int main()
{
    cin>>n>>k>>d;
    h=check();
    if (h==0) {printf("-1");return 0;}
    num=n;
    make_st(1);
    FOR(i,1,h){FOR(j,1,n) printf("%d ",a[i][j]);ENDL;}
    FOR(i,h+1,d) {FOR(j,1,n) printf("1 ");ENDL;}
}