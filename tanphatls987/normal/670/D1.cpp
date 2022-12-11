#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e5+10;

int n,add,avail[N],cons[N];
void prepare(){
    scanf("%d%d",&n,&add);
    FOR(i,1,n) scanf("%d",cons+i);
    FOR(i,1,n) scanf("%d",avail+i);
}
bool check(int mid){
    ll rem=add;
    FOR(i,1,n) {
        rem-=max(0LL,1LL*cons[i]*mid-avail[i]);
        if (rem<0) return 0;
    }
    return 1;
}
int solve(){
    int L=1,R=inf<<1;
    while (L<=R){
//        cout<<L<<" "<<R<<'\n';
        int mid=L+(R-L)/2;
        if (check(mid)) L=mid+1;
        else R=mid-1;
    }
    return R;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}