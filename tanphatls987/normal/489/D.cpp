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
const int N=3e3+10;

int n,m,x,y,f[N];
vector <int> a[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
    }
}
int main(){
    prepare();
    ll ans=0;
    FOR(i,1,n){
        memset(f,0,sizeof(f));
        for(auto &j:a[i])
            for(auto& k:a[j]) f[k]++;
        //FOR(j,1,n) printf("%d\n",f[j]);ENDL;
        FOR(j,1,n) if (i!=j)
            if (f[j]) ans+=(1LL*f[j]*(f[j]-1))/2;
        //cout<<i<<" "<<ans<<'\n';
    }
    cout<<ans;
}