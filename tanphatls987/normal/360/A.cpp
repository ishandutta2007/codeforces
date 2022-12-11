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

const int inf=1e8;
const int MOD=1e9+7;
const int N=5e3+10;

int n,m,ans[N],add[N],q[N][4],a[N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) ans[i]=inf;
    FOR(i,1,m){
        FOR(j,0,3) scanf("%d",q[i]+j);
        if (q[i][0]==1) FOR(j,q[i][1],q[i][2]) add[j]+=q[i][3];
        else{
            int cur=0;
            FOR(j,q[i][1],q[i][2]) {
                cur=max(cur,ans[j]+add[j]);
                ans[j]=min(ans[j],q[i][3]-add[j]);
            }
            if (cur<q[i][3]){
                printf("NO");
                return 0;
            }
        }
    }
//    cout<<"tick";
    FOR(i,1,n) a[i]=ans[i];
    FOR(i,1,m){
        if (q[i][0]==1) FOR(j,q[i][1],q[i][2]) a[j]+=q[i][3];
        else if (*max_element(a+q[i][1],a+q[i][2]+1)!=q[i][3]){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    FOR(i,1,n) printf("%d ",ans[i]);
}