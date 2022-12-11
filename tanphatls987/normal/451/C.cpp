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

const int N=0;

typedef long long ll;
int tc;
ll n,k,d1,d2;

int solve()
{
    ll a,b,c;
    if (n%3) {printf("no\n");return 0;}
    //a>b&&b>c
    if ((k-d1+d2)%3==0)
    {
        b=(k-d1+d2)/3;
        a=b+d1;
        c=b-d2;
        if (n/3>=a&&n/3>=b&&n/3>=c&&a<=k&&b<=k&&c<=k&&a>=0&&b>=0&&c>=0) {printf("yes\n");return 0;}
    }
    //a<b&&b>c
    if ((k+d1+d2)%3==0)
    {
        b=(k+d1+d2)/3;
        a=b-d1;
        c=b-d2;
        if (n/3>=a&&n/3>=b&&n/3>=c&&a<=k&&b<=k&&c<=k&&a>=0&&b>=0&&c>=0) {printf("yes\n");return 0;}
    }
    //a>b&&b<c
    if ((k-d1-d2)%3==0)
    {
        b=(k-d1-d2)/3;
        a=b+d1;
        c=b+d2;
        if (n/3>=a&&n/3>=b&&n/3>=c&&a<=k&&b<=k&&c<=k&&a>=0&&b>=0&&c>=0) {printf("yes\n");return 0;}
    }
    //a<b&&b<c
    if ((k+d1-d2)%3==0)
    {
        b=(k+d1-d2)/3;
        a=b-d1;
        c=b+d2;
        if (n/3>=a&&n/3>=b&&n/3>=c&&a<=k&&b<=k&&c<=k&&a>=0&&b>=0&&c>=0) {printf("yes\n");return 0;}
    }
    printf("no\n");
}
int main()
{
    cin>>tc;
    while (tc)
    {
        cin>>n>>k>>d1>>d2;
        solve();
        tc--;
    }
}