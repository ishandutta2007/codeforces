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

int n,q;
ll ar[N],pre[N];
ll mi[N<<2],ma[N<<2];
void build(int o=1,int l=1,int r=n){
    if(l==r){
        mi[o]=ma[o]=pre[l];
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    ma[o]=max(ma[lo],ma[ro]);
    mi[o]=min(mi[lo],mi[ro]);
}
ll querymi(int ql,int qr,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        return mi[o];
    }
    ll ret=linf;
    if(ql<=mid)Min(ret,querymi(ql,qr,lo,l,mid));
    if(qr>mid)Min(ret,querymi(ql,qr,ro,mid+1,r));
    return ret;
}
ll queryma(int ql,int qr,int o=1,int l=1,int r=n){
    if(ql<=l&&r<=qr){
        return ma[o];
    }
    ll ret=-linf;
    if(ql<=mid)Max(ret,queryma(ql,qr,lo,l,mid));
    if(qr>mid)Max(ret,queryma(ql,qr,ro,mid+1,r));
    return ret;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        ar[i]=a-ar[i];
        pre[i]=pre[i-1]+ar[i];
//        cout<<ar[i]<<' ';
    }
//    cout<<endl;
    build();
    while(q--){
        int l,r;cin>>l>>r;
//        K(l,r);
        if(pre[r]-pre[l-1]){
            cout<<-1<<endl;
        }
        else if(querymi(l,r)<pre[l-1]){
            cout<<-1<<endl;
        }
        else{
            cout<<queryma(l,r)-pre[l-1]<<endl;
        }
    }
}