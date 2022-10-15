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
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=100007;
const int K=207;
mt19937 rng(time(NULL));
int n,k;
int a[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        vector<vi> ans;
        cin>>n;
        int cur=0;
        while ((cur+1)*(cur+2)<=2*n) cur++;
        vi a(n,0);
        rep(i,n) cin>>a[i];
        while (sz(a)){
            int m=sz(a);
            vi lvl(m,INF),prv(m,-1);
            vector<pii> c(m,{INF,0ll});
            rep(i,m) {
                int pos=lower_bound(range(c),make_pair(a[i],0ll))-c.begin();
                c[pos]={a[i],i};
                if (pos) prv[i]=c[pos-1].S;
                lvl[i]=pos;
            }
            vi cnt(m,0);
            int mx2=-1;
            rep(i,m) if (c[i].F<INF) mx2=i;
            vi ta,aaa;
            if (mx2<cur){
                vector<vi> abc(mx2+1);
                rep(i,m){
                    abc[lvl[i]].pb(a[i]);   
                }
                rep(i,mx2+1) ans.pb(abc[i]);
                break;
            }
            else{
                int now=c[mx2].S;
                while (now!=-1){
                    aaa.pb(a[now]), a[now]=-1;
                    now=prv[now];
                }
                reverse(range(aaa));
                rep(i,m) if (a[i]!=-1) ta.pb(a[i]);
            }
            a=ta, ans.pb(aaa), cur--;
        }
        cout<<sz(ans)<<"\n";
        for (auto c:ans){
            cout<<sz(c)<<" ";
            for (auto d:c) cout<<d<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}


/*
5 3
1 2
2 3
3 4
4 5


*/