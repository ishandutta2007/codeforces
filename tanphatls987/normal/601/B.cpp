#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

int n,m,a[N],L[N],R[N],s[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    REP(i,1,n) a[i]=abs(a[i]-a[i+1]);
    int top=0;
    a[0]=a[n]=inf;
    REP(i,1,n){
        while (a[s[top]]<=a[i]) top--;
        L[i]=s[top]+1;
        s[++top]=i;
    }
    top=0;
    s[0]=n;
    FORD(i,n-1,1){
        while (a[s[top]]<a[i]) top--;
        R[i]=s[top]-1;
        s[++top]=i;
    }
//    REP(i,1,n) cout<<a[i]<<" \n"[i==n-1];
//    REP(i,1,n) cout<<L[i]<<" \n"[i==n-1];
//    REP(i,1,n) cout<<R[i]<<" \n"[i==n-1];
}
ll solve(int x,int y){
    ll ans=0;
    REP(i,x,y) ans+=1LL*a[i]*(i-max(L[i],x)+1)*(min(R[i],y-1)-i+1);
    return ans;
}
int main(){
    prepare();
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",solve(x,y));
    }
}