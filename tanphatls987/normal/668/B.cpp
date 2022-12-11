#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,ans[N];
deque <int> q[2];

int main(){
//    freopen("input.inp","r",stdin);
    int test,type,v;
    scanf("%d%d",&n,&test);
    REP(i,0,n) q[i&1].push_back(i);
    int shift=0,odd=1,n1=n/2;
    while (test--){
        scanf("%d",&type);
        if (type==2) odd^=1;
        else {
            scanf("%d",&v);
            v=(n+v)%n;
            shift=(shift+(v/2)+n1)%n1;
            if (v&1){
                int x=q[odd].back();
                q[odd].pop_back();
                q[odd].push_front(x);
                odd^=1;
            }
        }
    }
    FOR(type,0,1)
        REP(i,0,n1) {
            ans[(i*2+(type==odd)+shift*2)%n]=q[type].front();
            q[type].pop_front();
        }
    REP(i,0,n) printf("%d ",ans[i]+1);
}