#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef long double db;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<db,db>pdd;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e5+10,M=500;
const ll mod=998244353;
const db eps=1e-8;
int sgn(db a){return a<-eps?-1:(a<eps?0:1);}

bool ok(vi v){
    for(int i=0;i<v.size();i++){
        if(v[i]!=v[v.size()-i-1])return 0;
    }
    return 1;
}
int solve(){
    int n;cin>>n;
    vi ar(n);
    for(auto &i:ar)cin>>i;
    for(int i=0;i<n;i++){
        if(ar[i]!=ar[ar.size()-i-1]){
            vi tmp;
            for(auto j:ar)if(j!=ar[i]){
                tmp.push_back(j);
            }
            if(ok(tmp))return 1;
            tmp.clear();
            for(auto j:ar)if(j!=ar[ar.size()-i-1]){
                tmp.push_back(j);
            }
            if(ok(tmp))return 1;
            return 0;
        }
    }
    return 1;

}
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"YES":"NO")<<endl;
    }
}