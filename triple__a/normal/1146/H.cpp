// how to come up with such solution :(

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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=307;
const int K=207;
mt19937 rng(time(NULL));

typedef bitset<300> bs;
int n;
int x[N],y[N];
bs sgn[N][N];
bs neg;
int a[N][N][N];
bool cross(int i,int j,int k){
    int xa=x[j]-x[i], xb=x[k]-x[i], ya=y[j]-y[i], yb=y[k]-y[i];
    return xa*yb<xb*ya;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i], neg.set(i,1);
    rep(i,n) rep(j,n){
        if (i==j) continue;
        rep(k,n) sgn[i][j].set(k,cross(k,i,j));
    }
    rep(i,n) rep(j,i) rep(k,j){
        bs nw;
        nw.set(i,1), nw.set(j,1), nw.set(k,1);
        auto ret1=sgn[i][j]&sgn[j][k]&sgn[k][i];
        auto ret2=(sgn[i][j]^neg)&(sgn[j][k]^neg)&(sgn[k][i]^neg);
        auto ret=(ret1|ret2)&(neg^nw);
        a[i][j][k]=a[i][k][j]=a[j][i][k]=a[j][k][i]=a[k][i][j]=a[k][j][i]=ret.count();
    }
    int bad1=0;
    rep(i,n) rep(j,i) rep(k,j){
        bad1+=(a[i][j][k])*(a[i][j][k]-1)/2;
    }
    int bad2=0;
    rep(i,n) rep(j,i){
        int cnt[2]={0,0},ccnt[2]={0,0};
        rep(k,n){
            if (k==i||k==j) continue;
            int ret=cross(i,k,j);
            cnt[ret]+=a[i][j][k], ccnt[ret]++;
        }
        bad2+=cnt[0]*ccnt[1]+cnt[1]*ccnt[0];
    }
    bad2/=2;
    bad2-=2*bad1;
    int ans=1;
    rep(i,5) ans=ans*(n-i);
    rep(i,5) ans=ans/(i+1);
    cout<<ans-bad1-bad2;
    return 0;
}


/*
5
0 0
4 0
0 4
4 4
2 3


*/