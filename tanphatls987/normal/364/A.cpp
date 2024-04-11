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

const int N=4010;

typedef long long ll;

int a[N]={0},n,m,c;
ll h[100010]={0};
string S;
int main()
{
    cin>>m>>S;
    n=S.length();
    FOR(i,1,n) a[i]=a[i-1]+(S[i-1]-'0');
    FOR(i,1,n) FOR(j,i,n) h[a[j]-a[i-1]]++;
    ll ans=0;
    if (m==0) c=a[n];else c=int(trunc(sqrt(m)));
    FOR(i,1,c) if (m%i==0&&m/i<=a[n])
    {
        ans+=h[i]*h[m/i];
        if (i!=m/i) ans+=h[i]*h[m/i];
    }
    if (m==0) ans+=h[0]*h[0];
    cout<<ans;
}