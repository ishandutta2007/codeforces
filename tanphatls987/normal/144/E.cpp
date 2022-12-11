#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=1e5+10;

int n,m,ans[N];
vector <ii> a[N];
priority_queue <ii> q;
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        int x,y;
        scanf("%d%d",&x,&y);
        y=n-y+1;
        if (x>y) swap(x,y);
        a[x].push_back(ii(-y,i));
    }
}
void solve(){
    FOR(i,1,n){
        for(auto j:a[i]) q.push(j);
        while (!q.empty()&&-q.top().X<i) q.pop();
        if (!q.empty()){
            ans[q.top().Y]=1;
            q.pop();
        }
    }
    printf("%d\n",count(ans+1,ans+m+1,1));
    FOR(i,1,m) if (ans[i]) printf("%d ",i);
}
int main(){
    prepare();
    solve();
}