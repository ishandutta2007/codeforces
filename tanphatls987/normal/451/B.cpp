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

int a[N],n;
int main()
{
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int l=1;
    while (a[l+1]>a[l]&&l<n) l++;
    int r=l;
    while (a[r+1]<a[r]&&r<n) r++;
    FOR(i,1,(r-l+1)/2) swap(a[l+i-1],a[r-i+1]);
    FOR(i,1,n) if (a[i]<a[i-1]) {printf("no");return 0;}
    printf("yes\n%d %d",l,r);

}