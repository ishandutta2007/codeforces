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
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(1234);

int n,m;
int sz[N];
int sum[6],a[6][6][6],p[6],ans[N],aaa[N];
vi st[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    // rep1(i,n) cin>>aaa[i];
    auto query=[&](int u,int v,int w){
        cout<<"? "<<u<<" "<<v<<" "<<w<<endl;
        // int q=min({aaa[u],aaa[v],aaa[w]})+max({aaa[u],aaa[v],aaa[w]});
        int q;
        cin>>q;
        return q;
    };
    rep1(i,5) rep1(j,i-1) rep1(k,j-1){
        // cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
        int u=query(i,j,k);
        // cin>>u;
        sum[i]+=u, sum[j]+=u, sum[k]+=u;
        a[i][j][k]=a[i][k][j]=a[j][i][k]=a[j][k][i]=a[k][i][j]=a[k][j][i]=u;
    }
    rep1(i,5) p[i]=i;
    sort(p+1,p+6,[&](int u,int v){return sum[u]>sum[v];});
    // rep1(i,5) cout<<p[i]<<endl;
    int A=a[p[1]][p[2]][p[3]],B=a[p[1]][p[2]][p[5]], C=a[p[3]][p[4]][p[5]];
    int D=(A+B+C)/2;
    ans[p[5]]=D-A, ans[p[3]]=D-B, ans[p[1]]=D-C;
    ans[p[2]]=a[p[2]][p[3]][p[5]]-ans[p[5]];
    ans[p[4]]=a[p[1]][p[2]][p[4]]-ans[p[1]];
    int aa=p[1], bb=p[5], cc=p[3];
    for (int i=6;i<=n;++i){
        // cout<<"? "<<aa<<" "<<bb<<" "<<i<<endl;
        int u=query(aa,bb,i);
        // cin>>u;
        if (u!=ans[aa]+ans[bb]){
            if (u>ans[aa]+ans[bb]) ans[i]=u-ans[bb]; 
            else ans[i]=u-ans[aa];
        }
        else{
            int u=query(aa,cc,i);
            if (u!=ans[aa]+ans[cc]) ans[i]=u-ans[aa];
            else{
                int u=query(cc,bb,i);
                ans[i]=u-ans[bb];
            }
        }
    }
    cout<<"! ";
    for (int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

/*
1
10000000 -2000000000 2000000000 123 321 12312312312 123123123
*/