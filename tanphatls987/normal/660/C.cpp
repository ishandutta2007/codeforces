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
const int N=5e5+10;

int n,k,a[N];
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    int ans=-1,pos;
    for(int en=1,st=1,c=0;en<=n;en++){
        c+=a[en]^1;
        while (c>k) c-=a[st++]^1;
        if (ans<en-st){
            ans=en-st;
            pos=en;
        }
    }
    printf("%d\n",ans+1);
    FORD(i,pos,1) if (k&&!a[i]) a[i]=1,k--;
    FOR(i,1,n) printf("%d ",a[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}