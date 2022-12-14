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
const int N=2e5+10,M=500;
const ll mod=1e9+7;
const db eps=1e-8;
int sgn(db a){return a<-eps?-1:(a<eps?0:1);}

int solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }
    vector<pii>br;
    int ret=0;
    for(auto i:mp){
        br.push_back(i);
        Max(ret,i.se);
    }
    for(int i=0;i+1<br.size();i++){
        int lst=0,cnt=br[i].se+1;
        vi v{br[i].fi,br[i+1].fi};
        while(1){
            auto j=lower_bound(br.begin(),br.end(),(pii){2*v.back()-v[0],0});
            if(j==br.end())break;
            v.push_back(j->fi);
            cnt++;
        }
        Max(ret,cnt);
    }
    return n-ret;
}
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}