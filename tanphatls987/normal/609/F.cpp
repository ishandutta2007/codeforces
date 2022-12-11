#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=1e9+10;
const ll linf=1e15;
const int MOD=1e9+7;
const int N=2e5+10;

int n,m,a[N],per[N],c[N];
ll bi[N<<2];
ll laz[N<<2],w[N];
map<int,lli> se;
lli operator +(lli a,lli b){
    return lli(a.X+b.X,a.Y+b.Y);
}
bool compa(int x,int y){
    return a[x]<a[y];
}
void update(int x,ll v){
    while (x<=n){
        bi[x]=max(bi[x],v);
        x+=x&-x;
    }
}
int findpos(int v){
    int pos=0;
    for(int i=1<<int(log2(n));i;i>>=1){
        int cur=pos+i;
        if (cur>n) continue;
        if (bi[cur]<v) pos=cur;
    }
    return pos+1;
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%I64d",a+i,w+i);
    FOR(i,1,n) per[i]=i;
    sort(per+1,per+n+1,compa);
    FOR(i,1,n) update(i,a[per[i]]+w[per[i]]);
    int x,v;
    a[0]=inf;
    while (m--){
        scanf("%d%d",&x,&v);
        int idx=findpos(x);
//        cout<<"->"<<idx<<" "<<per[idx]<<'\n';
//        FOR(i,1,n) cout<<bi[i]<<" \n"[i==n];
        if (a[per[idx]]<=x){
            w[per[idx]]+=v;
            c[per[idx]]++;
            while (1){
                auto cur=se.lower_bound(a[per[idx]]);
                if (cur!=se.end()&&cur->X-a[per[idx]]<=w[per[idx]]){
                    w[per[idx]]+=cur->Y.X;
                    c[per[idx]]+=cur->Y.Y;
                    se.erase(cur);
                }else break;
            }
            update(idx,a[per[idx]]+w[per[idx]]);
        }else se[x]=se[x]+lli(v,1);
    }
}


void solve(){
    FOR(i,1,n) printf("%d %lld\n",c[i],w[i]);
}
int main(){
    prepare();
    solve();
}