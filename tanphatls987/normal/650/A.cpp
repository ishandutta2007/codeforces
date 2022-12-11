#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=2e5+10;

int n;
ii a[N];
ll C2(int x){
    return 1LL*(x-1)*x/2;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int en=1;en<=n;){
        int st=en;
        while (en<=n&&a[en].X==a[st].X) en++;
        ans+=C2(en-st);
    }
    FOR(i,1,n) swap(a[i].X,a[i].Y);
    sort(a+1,a+n+1);
    for(int en=1;en<=n;){
        int st=en;
        while (en<=n&&a[en].X==a[st].X) en++;
        ans+=C2(en-st);
    }
    for(int en=1;en<=n;){
        int st=en;
        while (en<=n&&a[en].X==a[st].X&&a[en].Y==a[st].Y) en++;
        ans-=C2(en-st);
    }
    cout<<ans;
}
int main(){
    //freopen("input.inp","r",stdin);
    prepare();
}