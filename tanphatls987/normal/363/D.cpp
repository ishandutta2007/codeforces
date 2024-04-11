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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,bud,a[N],b[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&bud);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
}
bool check(int M){
    ll ans=0;
    REP(i,0,M) ans+=max(0,b[M-i]-a[n-i]);
    return ans<=bud;
}
int cal(int len){
    int ans=0;
    REP(i,0,len) ans+=min(a[n-i],b[len-i]),bud-=max(0,b[len-i]-a[n-i]);
    return max(0,ans-bud);
}
int main(){
    prepare();
    int L=0,R=min(n,m);
    while (L<=R){
        int M=(L+R)/2;
        if (check(M)) L=M+1;
        else R=M-1;
    }
    cout<<R<<" "<<cal(R);
}