#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
template<class T>void read(T&ret) {
    char c;
    ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9')ret=ret*10+(c-'0'),c=getchar();
}
template<class T>void o(T x) {
    if(x<0)putchar('-'),x*=-1;
    if(x>9)o(x/10);
    putchar(x%10+'0');
}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#endif
#ifdef CY1999TXDY
#define Debug(x...) do { cerr << "cy1999txdy   " << #x << " -> "; Err(x); } while (0)
void Err() { cerr << "   ???" << endl; }
template<template<typename...> class T, typename t, typename... A>
void Err(T<t> a, A... x) { for (auto v: a) cerr << v << ' '; Err(x...); }
template<typename T, typename... A>
void Err(T a, A... x) { cerr << a << ' '; Err(x...); }
#else
#define Debug(...)
#endif
typedef long long ll;
typedef __int128_t il;
typedef pair<int,int>pii;
typedef vector<int>vi;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=6e5+10,M=5000+10;
const ll mod=1e9+7;

int n,m,l[N],r[N];
array<int,3>ar[N];
vi br;
pii ma[N<<2],lazy[N<<2],res[N];
void pushdown(int o,int l,int r){
    if(lazy[o].fi){
        Max(ma[lo],lazy[o]);
        Max(ma[ro],lazy[o]);
        Max(lazy[lo],lazy[o]);
        Max(lazy[ro],lazy[o]);
        lazy[o]={0,0};
    }
}
pii query(int ql,int qr,int o,int l,int r){
    if(ql<=l&&r<=qr){
        return ma[o];
    }
    pushdown(o,l,r);
    pii ret{};
    if(ql<=mid)Max(ret,query(ql,qr,lo,l,mid));
    if(qr>mid)Max(ret,query(ql,qr,ro,mid+1,r));
    return ret;
}
void update(int ql,int qr,pii v,int o,int l,int r){
    if(ql<=l&&r<=qr){
        Max(ma[o],v);
        Max(lazy[o],v);
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)update(ql,qr,v,lo,l,mid);
    if(qr>mid)update(ql,qr,v,ro,mid+1,r);
    ma[o]=max(ma[lo],ma[ro]);
}
int main() {
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)cin>>ar[i][j];
        ar[i][2]++;
        br.push_back(ar[i][1]);
        br.push_back(ar[i][2]);
    }
    sort(br.begin(),br.end());
    br.erase(unique(br.begin(),br.end()),br.end());
    sort(ar,ar+m);
    for(int i=0;i<m;i++){
        l[i]=lower_bound(br.begin(),br.end(),ar[i][1])-br.begin()+1;
        r[i]=lower_bound(br.begin(),br.end(),ar[i][2])-br.begin();
    }
    pii mx;
    for(int i=0;i<m;i++){
        if(!i||ar[i][0]!=ar[i-1][0]){
            mx={0,0};
        }
        Max(mx,query(l[i],r[i],1,1,br.size()-1));
        if(i==m-1||ar[i][0]!=ar[i+1][0]){
            res[ar[i][0]]=mx;
            for(int j=i;ar[j][0]==ar[i][0];j--){
                update(l[j],r[j],{mx.fi+1,ar[i][0]},1,1,br.size()-1);
            }
        }
    }
    cout<<n-ma[1].fi<<endl;
    set<int>s;
    for(int i=1;i<=n;i++)if(res[i].fi+1==ma[1].fi){
        while(i){
            s.insert(i);
            i=res[i].se;
        }
        break;
    }
    for(int i=1;i<=n;i++)if(!s.count(i)){
        cout<<i<<' ';
    }
}