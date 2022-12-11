#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int L=*max_element(a+1,a+n+1);
    ll cur=0;
    FOR(i,1,n) cur+=L-a[i];
    int ans;
    if (cur<L) ans=(1LL*n*L-cur+n-2)/(n-1);
    else ans=L;
    cout<<ans;
}