#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=4e6+10;

int n,m,x,bans,p[20],s[2];
deque <int> q[2];
void solve(){
    int ans=0;
    while (ans<4000000){
        ans++;
        FOR(i,0,1) s[i]=q[i].back(),q[i].pop_back();
        int go=(s[1]>s[0]);
        q[go].push_front(s[1-go]);
        q[go].push_front(s[go]);
        if (!q[go^1].size()) {
            printf("%d %d\n",ans,go+1);
            //bans=max(bans,ans);
            return;
        }
    }
    printf("-1\n");
}
int main(){
    cin>>n;
    FOR(i,0,1){
        cin>>m;
        while (m--){
            cin>>x;
            q[i].push_front(x);
        }
    }
    solve();
}