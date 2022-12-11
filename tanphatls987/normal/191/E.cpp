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

const ll inf=1e14;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,b[N],t[N];
ll a[N],p[N],k;
void update(int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
bool check(ll M){
//    cout<<M<<'\n';
    memset(b,0,sizeof(int)*(m+1));
    update(t[0],1);
    ll c=0;
    FOR(i,1,n){
        ll val=a[i]-M;
        int idx=upper_bound(p+1,p+m+1,val)-p-1;
        c+=get(idx);
        update(t[i],1);
    }
//    cout<<M<<" "<<c<<'\n';
    return c>=k;
}
void prepare(){
    scanf("%d%I64d",&n,&k);
    FOR(i,1,n) scanf("%I64d",a+i),a[i]+=a[i-1];
    FOR(i,1,n+1) p[i]=a[i-1];
    sort(p+1,p+n+2);
    m=unique(p+1,p+n+2)-p-1;
    FOR(i,0,n) t[i]=lower_bound(p+1,p+m+1,a[i])-p;
}
int main(){
    prepare();
    ll L=-inf,R=inf;
    while (L<=R){
//        cout<<L<<" "<<R<<'\n';
        ll M=(L+R)/2;
        if (check(M)) L=M+1;
        else R=M-1;
    }
    cout<<R;
}