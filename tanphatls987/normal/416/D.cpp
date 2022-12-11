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
const int N=2e5+10;

int n,a[N],d[2];
int main(){
//    INPUT;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int ans=0;
    FOR(L,1,n){
        int R=L-1;ans++;
        d[0]=d[1]=0;
        while (!d[1]&&R<n){
            ++R;
            if (a[R]!=-1) d[d[0]>0]=R;
        }
        if (!d[1]) break;
        ll change=(a[d[1]]-a[d[0]]);
        if (change%(d[1]-d[0])) R=d[1]-1;
        else{
            change/=(d[1]-d[0]);
            bool ok=1;
            if (L!=d[0]){
                ll fi=a[d[0]]-(d[0]-L)*change;
                if (fi<=0) R=d[1]-1,ok=0;
            }
            while (ok){
                ll nv=a[d[1]]+(R+1-d[1])*change;
                if (nv>0&&(nv==a[R+1]||a[R+1]==-1)) R++;
                else break;
            }
        }
//        printf("%d %d\n",L,R);
        L=R;
    }
    cout<<ans;
}