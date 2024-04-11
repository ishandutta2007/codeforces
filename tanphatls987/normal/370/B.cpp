#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e2+10;

int n,m,x,a[N][N],h[N]={0};
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&m);
        while (m--){
            scanf("%d",&x);
            a[i][x]=1;
        }
    }
    FOR(i,1,n) h[i]=1;
    FOR(i,1,n)
        FOR(j,1,n) if (j!=i){
            bool danger=1;
            FOR(k,1,100) if (a[i][k]&&!a[j][k]) danger=0;
            if (danger) h[j]=0;
        }
    FOR(i,1,n) cout<<(h[i]?"YES":"NO")<<'\n';
}