#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define K(a...)
#endif
typedef unsigned long long ul;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int mod=998244353;

int n,ar[N];
ll solve(){
    cin>>n;
    ll cnt=0;
    vi pos;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        ar[i]%=2;
        cnt+=ar[i];
        if(ar[i])pos.push_back(i);
    }
    if(n%2==0){
        if(cnt!=n/2)return -1;
        ll ret=linf;
        ll sum=0;
        for(int i=1;i<=n;i+=2)sum+=abs(pos[i/2]-i);
        Min(ret,sum);
        sum=0;
        for(int i=2;i<=n;i+=2)sum+=abs(pos[i/2-1]-i);
        Min(ret,sum);
        return ret;
    }
    else{
        if(cnt==n/2){
            ll ret=0;
            for(int i=2;i<=n;i+=2)ret+=abs(pos[i/2-1]-i);
            return ret;
        }
        else if(cnt==n/2+1){
            ll ret=0;
            for(int i=1;i<=n;i+=2)ret+=abs(pos[i/2]-i);
            return ret;
        }
        else return -1;
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}