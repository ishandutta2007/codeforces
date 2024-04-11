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
typedef pair<int,int> ii;

string a[N];
ii d[N];
int n;
void prepare(){
    cin>>a[0]>>n;
    a[0]="0->"+a[0];
    FOR(i,1,n) cin>>a[i];
}
void solve()
{
    FOR(i,0,9) d[i]=ii(10,i);
    FORD(i,n,0){
        int m=a[i].length();
        ll nv=1,ns=0;
        REP(j,3,m){
            int cc=a[i][j]-'0';
            nv=(nv*d[cc].X)%MOD;
            ns=((ns*d[cc].X)%MOD+d[cc].Y)%MOD;
        }
        d[a[i][0]-'0']=ii(nv,ns);
    }
    printf("%d",d[0].Y);
}
int main()
{
    prepare();
    solve();
}