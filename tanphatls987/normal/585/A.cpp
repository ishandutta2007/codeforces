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
const int N=4e3+10;

struct child{
    int con,v,d;
    void read(){
        scanf("%d%d%d",&v,&d,&con);
    }
}a[N];
int n;
void solve(){
    vector <int> ans;
    FOR(i,1,n){
        if (a[i].con>=0){
            ans.push_back(i);
            int dec=0;
            for(int j=i+1;j<=n;j++) if (a[j].con>=0){
                a[j].con-=a[i].v+dec;
                a[i].v=max(a[i].v-1,0);
                if (a[j].con<0) dec=min(dec+a[j].d,inf);
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) a[i].read();
    solve();
}