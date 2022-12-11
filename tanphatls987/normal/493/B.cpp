#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,x,last,a[2][N]={0},c1=0,c2=0;
ll sc1,sc2;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&x);
        if (x>0) sc1+=x,a[0][++c1]=x;
        else sc2+=-x,a[1][++c2]=-x;
        if (i==n) last=(x<0);
    }

}
void solve(){
    if (sc1>sc2) {printf("first");return;}
    else if (sc2>sc1) {printf("second");return;}
    FOR(i,1,max(c1,c2)){
        if (a[0][i]>a[1][i]) {printf("first");return;}
        else if (a[1][i]>a[0][i]) {printf("second");return;}
    }
    if (!last) printf("first");else printf("second");
}
int main(){
    prepare();
    solve();
}