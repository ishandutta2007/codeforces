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

int n;
ll ar[N],f[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    ll left=0,ans=0;
    for(int i=2;i<=n;i+=2){
        ll a=0,mi=linf;
        for(int j=i;j>0;j-=2){
            a+=ar[j]-ar[j-1];
            if(a<0){
                f[i]=1;
                break;
            }
            else if(a==0){
                f[i]=f[j-2]+1;
                break;
            }
        }
        a=0;
        for(int j=i;j>0;j-=2){
            a+=ar[j]-ar[j-1];
            K(a);
            if(a<0){
                mi=0;
                break;
            }
            if(a<mi){
                ans+=f[j-2];
                mi=a;
            }
        }
        ans+=ar[i]-mi;
        K(ar[i],mi,ans);
    }
    cout<<ans;
}