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

const int inf=1e9+10;
const int MOD=1e9+7;
const int N=5e5+10;

int n,st;
ii a[N];
bool check(long double M){
    long double cur=-1e9;
    FOR(i,st,n){
        if (a[i].Y>0) cur=max(cur,a[i].X+a[i].Y*M);
        else if (cur-a[i].Y*M>=a[i].X) return 1;
    }
    return 0;
}
void solve(){
    st=1;
    while (a[st].Y<0) st++;
    bool ok=0;
    FOR(i,st,n) if (a[i].Y<0) ok=1;
    if (!ok){
        printf("-1");
        return;
    }
    long double L=0,R=1e9+5;
    FOR(te,1,200){
        long double M=(L+R)/2;
        if (check(M)) R=M;
        else L=M;
    }
    printf("%.15f",double(R));
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    solve();
}