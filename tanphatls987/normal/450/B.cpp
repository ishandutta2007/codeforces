#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

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

typedef long long ll;

ll a[4],n;
int main()
{
    cin>>a[0]>>a[1]>>n;
    a[2]=a[1]-a[0];
    n--;
    if ((n/3)%2==0) cout<<(a[n%3]+1LL*2*MOD)%(1LL*MOD);
    else cout<<(-a[n%3]+1LL*2*MOD)%(1LL*MOD);
}