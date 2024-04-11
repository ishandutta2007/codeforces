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
const int N=100007;
const int K=207;
mt19937 rng(time(NULL));

int n;
int a[N],ans[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        vector<pii> edges[2];
        rep1(i,n-1) edges[i&1].pb({i,i+1});
        auto query=[&](vector<pii> &res)->string{
            if (sz(res)==0) return "";
            cout<<"Q "<<sz(res)<<" ";
            for (auto [x,y]:res) cout<<x<<" "<<y<<" ";
            cout<<endl;
            string s;
            cin>>s;  
            return s;
        };
        auto ret0=query(edges[0]), ret1=query(edges[1]);
        rep(i,sz(edges[0])){
            a[edges[0][i].F]=ret0[i]-'0';
        }
        rep(i,sz(edges[1])){
            a[edges[1][i].F]=ret1[i]-'0';
        }
        vi fk;
        fk.pb(1);
        for (int i=1;i<n;++i){
            if (!a[i]) fk.pb(i+1); 
        }
        vector<pii> q;
        for (int i=0;i<sz(fk);i+=4){
            if (i+2<sz(fk)) q.pb({fk[i],fk[i+2]});
            if (i+3<sz(fk)) q.pb({fk[i+1],fk[i+3]});
        }
        auto ret2=query(q);
        q.clear();
        for (int i=2;i<sz(fk);i+=4){
            if (i+2<sz(fk)) q.pb({fk[i],fk[i+2]});
            if (i+3<sz(fk)) q.pb({fk[i+1],fk[i+3]});
        }
        auto ret3=query(q);
        vi val(sz(fk)+1,0);
        val[0]=0, val[1]=1; 
        int le=0, ri=0;
        for (int i=2;i<sz(fk);i+=4){
            auto mex=[&](int u,int v){
                if (u>v) swap(u,v);
                if (u) return 0;
                if (v==1) return 2;
                return 1;
            };
            if (i<sz(fk)) {
                if (ret2[le]=='1') val[i]=val[i-2];
                else val[i]=mex(val[i-2],val[i-1]);
                le++;
            }
            if (i+1<sz(fk)) {
                if (ret2[le]=='1') val[i+1]=val[i-1];
                else val[i+1]=mex(val[i-1],val[i]);
                le++;
            }
            if (i+2<sz(fk)) {
                if (ret3[ri]=='1') val[i+2]=val[i];
                else val[i+2]=mex(val[i],val[i+1]);
                ri++;
            }
            if (i+2<sz(fk)) {
                if (ret3[ri]=='1') val[i+3]=val[i+1];
                else val[i+3]=mex(val[i+1],val[i+2]);
                ri++;
            }
        }
        int cnt=sz(fk)-1;
        for (int i=n;i>0;--i){
            if (i<fk[cnt]) cnt--;
            ans[i]=val[cnt];
        }
        vi rrr[3];
        for (int i=1;i<=n;++i) rrr[ans[i]].pb(i);
        cout<<"A "<<sz(rrr[0])<<" "<<sz(rrr[1])<<" "<<sz(rrr[2])<<endl;
        rep(_,3) {
            for (auto c:rrr[_]) cout<<c<<" ";
            cout<<endl;
        } 
    }
    return 0;
}


/*
12 6
1 3
3 7
5 7
7 11
9 11
11 3

*/