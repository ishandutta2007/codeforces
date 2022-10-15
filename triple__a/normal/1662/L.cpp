// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX/5000;
const double EPS=1e-9;
// const int MAXN=2003*2003;
const int N=200027;
const int K=360*10000;
mt19937 rng(1234);

struct st{
    int x,y,z;
};
bool cmpx(st l,st r){
    return l.x<r.x;
}
bool cmpy(st l,st r){
    return l.y<r.y;
}
int n,v;
int t[N],x[N],dp[N],C[N];
st val[N];
int lowbit(int u){return u&(-u);}
void update(int u,int w){
    for (int i=u;i<=n+6;i+=lowbit(i)) C[i]=max(C[i],w);
}
int query(int u){
    int ans=-INF;
    for (int i=u;i>0;i-=lowbit(i)) ans=max(ans,C[i]);
    return ans;
}
void init(int u){
    for (int i=u;i<=n+6;i+=lowbit(i)) C[i]=-INF;
}
void solve(int L,int R){
    if (L==R) {
        dp[L]++; return;
    }
    int md=(L+R)>>1;
    solve(L,md);
    sort(val+L,val+md+1,cmpy);
    sort(val+md+1,val+R+1,cmpy);
    int j=L;
    for (int i=md+1;i<=R;++i){
        while (j<=md&&val[j].y<=val[i].y) {update(val[j].z,dp[val[j].x]), j++;}
        // if (i==1) cerr<<i<<" "<<val[i].z<<" "<<query(val[i].z)<<endl;
        dp[val[i].x]=max(dp[val[i].x],query(val[i].z));
    }
    for (int i=L;i<=md;++i) init(val[i].z);
    sort(val+L,val+R+1,cmpx);
    solve(md+1,R);
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>v;
    for (int i=1;i<=n+6;++i) init(i);
    rep(i,n) cin>>t[i];
    rep(i,n) cin>>x[i];
    rep(i,n) {
        val[i].x=i+1, val[i].y=t[i]*v+x[i], val[i].z=t[i]*v-x[i];
    } 
    val[n].x=val[n].y=val[n].z=0;
    sort(val,val+n+1,cmpx);
    // rep(i,n+1) cerr<<val[i].x<<" "<<val[i].y<<" "<<val[i].z<<endl;
    vi q;
    rep(i,n+1) q.pb(val[i].z);
    sort(range(q));
    rep(i,n+1) val[i].z=lower_bound(range(q),val[i].z)-q.begin()+2;
    dp[0]=-1;
    rep1(i,n) dp[i]=-INF;
    solve(0,n);
    int ans=0;
    for (int i=0;i<=n;++i) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}