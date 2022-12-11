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
const int N=2e3+10;

int a[2][N],n[2];
ll sum[2],np[N*N];
vector <ii> tr;
struct info{
    ll v;
    int x,y;
    info (ll _v=0,int _x=0,int _y=0){
        v=_v;x=_x;y=_y;
    }
};
info p[N*N];
bool comp(info a,info b){
    return a.v<b.v;
}
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void prepare(){
    FOR(type,0,1){
        scanf("%d",n+type);
        FOR(i,1,n[type]) scanf("%d",a[type]+i);
    }
    FOR(type,0,1)
        FOR(i,1,n[type]) sum[type]+=a[type][i];
}
void solve(){
    ll ans=abs(sum[0]-sum[1]);
    FOR(i,1,n[0])
        FOR(j,1,n[1]) {
            ll cha=(a[0][i]-a[1][j]);
            if (minimize(ans,abs(sum[0]-2*cha-sum[1]))){
                tr.clear();
                tr.push_back(ii(i,j));
            }
        }
    int top=0;
    FOR(i,1,n[1])
        FOR(j,i+1,n[1]) p[++top]=info(a[1][i]+a[1][j],i,j);
    sort(p+1,p+top+1,comp);
    int m=0;
    FOR(i,1,top){
        p[++m]=p[i];
        while (i<top&&p[i+1].v==p[m].v) i++;
    }
//    cout<<m<<'\n';
    FOR(i,1,m) np[i]=p[i].v;
    FOR(i,1,n[0])
        FOR(j,i+1,n[0]){
            ll amo=a[0][i]+a[0][j];
            ll need=(sum[1]+amo*2-sum[0]-1)/2;
            int idx=lower_bound(np+1,np+m+1,need)-np;
            FOR(k,0,1) if (idx>k&&idx-k<=m)
                if (minimize(ans,abs((sum[0]+np[idx-k]-amo)-(sum[1]-np[idx-k]+amo)))){
                    tr.clear();
                    tr.push_back(ii(i,p[idx-k].x));
                    tr.push_back(ii(j,p[idx-k].y));
                }
        }
    for(auto i:tr){
        assert(i.X>0&&i.X<=n[0]);
        assert(i.Y>0&&i.Y<=n[1]);
    }
    cout<<ans<<'\n'<<tr.size()<<'\n';
    for(auto i:tr) cout<<i.X<<" "<<i.Y<<'\n';
}
int main(){
    prepare();
    solve();
}