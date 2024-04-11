#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=1e5+10;

int b[N<<1]={0},n,m,des,s[N<<1];
ii a[N];
void update(int x,int v){
    while (x<=m){
        b[x]=(b[x]+v)%MOD;
        x+=x&-x;
    }
}
ll get(int x){
    ll tmp=0;
    while (x){
        tmp=(tmp+b[x])%MOD;
        x-=x&-x;
    }
    return tmp;
}
bool comp(ii a,ii b){
    if (a.Y==b.Y) return a.X<b.X;
    return a.Y<b.Y;
}
void prepare(){
    scanf("%d%d",&des,&n);
    FOR(i,1,n){
        scanf("%d%d",&a[i].X,&a[i].Y);
        s[2*i-1]=a[i].X;
        s[2*i]=a[i].Y;
    }
    s[2*n+1]=des;s[2*n+2]=0;
    sort(s+1,s+2*n+3);
    m=0;
    FOR(i,1,2*n+2){
        s[++m]=s[i];
        while (i<=2*n+1&&s[i+1]==s[i]) i++;
    }
    sort(a+1,a+n+1,comp);
}
void solve(){
    update(lower_bound(s+1,s+m+1,0)-s,1);
    FOR(i,1,n){
        int L=lower_bound(s+1,s+m+1,a[i].X)-s,R=lower_bound(s+1,s+m+1,a[i].Y)-s;
        ll v=(3LL*MOD+get(R-1)-get(L-1))%MOD;
        update(R,v);
    }
    int x=lower_bound(s+1,s+m+1,des)-s;
    ll ans=(3LL*MOD+get(x)-get(x-1))%MOD;
    printf("%lld",ans);
}
int main(){
    prepare();
    solve();
}