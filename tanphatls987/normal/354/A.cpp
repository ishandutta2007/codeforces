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

const ll inf=1e15;
const int MOD=1e9+7;
const int N=1e5+10;

int a[N],n,cl,cr,pl,pr,sum=0;
void prepare(){
    scanf("%d%d%d%d%d",&n,&cl,&cr,&pl,&pr);
    FOR(i,1,n) scanf("%d",a+i),sum+=a[i];
}
int main(){
    prepare();
    ll ans=inf;
    int s1=0;a[0]=0;
    FOR(i,0,n){
        s1+=a[i];
        ll cost=1LL*s1*cl+1LL*(sum-s1)*cr;
        if (i<n-i) cost+=1LL*max(n-2*i-1,0)*pr;
        else cost+=1LL*max(i-(n-i)-1,0)*pl;
        //printf("%d %d %lld\n",i,s1,cost);
        ans=min(ans,cost);
    }
    cout<<ans;
}