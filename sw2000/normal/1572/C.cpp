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
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5000+10;
const ll mod=1e9+7;

int ar[N],f[N][N],lst[N];
int solve(){
    int n;cin>>n;
    map<int,int>pos;
    for(int i=1;i<=n;i++)cin>>ar[i];
    for(int i=1;i<=n;i++){
        lst[i]=pos[ar[i]];
        pos[ar[i]]=i;
    }
    for(int i=1;i<=n;i++)f[i][i]=1;
    for(int len=2;len<=n;len++){
        for(int l=1,r=len;r<=n;r++,l++){
            f[l][r]=min(f[l+1][r],f[l][r-1])+1;
                int t=lst[r];
            while(t>=l){
                Min(f[l][r],f[l][t-1]+f[t+1][r]);
                t=lst[t];
            }
        }
    }
    return f[1][n]-1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}