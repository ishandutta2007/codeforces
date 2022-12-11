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

int n,a[N],s[N];
set <int> mse;
map <int,int> ma;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    mse.insert(a[1]);
    FOR(i,2,n){
        auto j=mse.lower_bound(a[i]);
        if (j==mse.begin()) printf("%d ",*j);
        else{
            auto lj=j;
            lj--;
            printf("%d ",(ma[*lj]<ma[*j])?*j:*lj);
        }
        mse.insert(a[i]);
        ma[a[i]]=i;
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}