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

const int inf=1e9;
const int MOD=1e9+7;
const int N=3e5+10;

map <int,int> ma;
int n,a[N],L[N],s[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        L[i]=ma[a[i]];
        ma[a[i]]=i;
    }
    FOR(i,1,n) L[i]=max(L[i],L[i-1]);
}
void solve(){
    int top=0;
    FOR(i,1,n) if (L[i]>s[top]) s[++top]=i;
    if (!top){
        printf("-1");
        return;
    }
    s[top]=n;
    printf("%d\n",top);
    FOR(i,1,top) printf("%d %d\n",s[i-1]+1,s[i]);
}
int main(){
    prepare();
    solve();
}