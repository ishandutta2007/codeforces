#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,x,a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&x),a[x]++;
    ll ans=0;
    vector <int> go;
    FORD(i,1000000,1) {
        int use=0;
        if (a[i+1]) use=1,a[i]++;
        FOR(j,1,a[i]/2) go.push_back(i);
        if (a[i]>=2&&use) use=0;
        a[i]%=2;
        a[i]-=use;
    }
    int m=go.size();
    REP(i,0,m-1) ans+=1LL*go[i]*go[i+1],i++;
    cout<<ans;
}