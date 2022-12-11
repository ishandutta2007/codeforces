#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e12;
const int MOD=1e9+7;
const int N=0;

template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
ll construct(int n1,int n2,int block,bool type){
    ll ans=1LL*(n1-block+1)*(n1-block+1)+block-1;
    int rem=n2%(block+1),intend=n2/(block+1);
    ans-=1LL*rem*(intend+1)*(intend+1)+1LL*(block+1-rem)*intend*intend;
    if (type){
        REP(pha,0,2*block+1) if (pha&1){
            FOR(i,1,(pha==1)?n1-block+1:1) printf("o");
        }else FOR(i,1,intend+((pha/2)<rem)) printf("x");
    }
    return ans;
}
void solve(int n1,int n2){
    if (!n1){
        cout<<-1LL*n2*n2<<'\n';
        FOR(i,1,n2) printf("x");
        return;
    }
    ll ans=-inf;
    int sel=0;
    FOR(block,1,n1) if (maximize(ans,construct(n1,n2,block,0)))
        sel=block;
    cout<<ans<<'\n';
    construct(n1,n2,sel,1);
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    solve(n1,n2);
}