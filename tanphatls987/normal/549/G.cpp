#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("G.inp","r",stdin)
#define OUTPUT freopen("G.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,a[N],ans[N];
priority_queue <int> q;
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) q.push(a[i]+i);
    ans[n+1]=inf;
    FORD(i,n,1){
        ans[i]=q.top()-i;
        q.pop();
        //printf("%d %d\n",i,ans[i]);
        if (ans[i]>ans[i+1]) {
            printf(":(");
            return 0;
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}