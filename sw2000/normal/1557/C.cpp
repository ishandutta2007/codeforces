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
const int N=2e5+10,M=5000+10;
const ll mod=1e9+7;

int n,k;
ll base[N],two[N]{1};
int solve(){
    cin>>n>>k;
    base[0]=1;
    for(int i=1;i<=k;i++)base[i]=base[i-1]*two[n]%mod;
    ll ret=0,add=1;
    for(int i=0;i<k;i++){
        if(n%2==0){
            ret+=add*base[k-i-1]%mod;
            add*=two[n-1]-1;
        }
        else add*=two[n-1]+1;
        add%=mod;
    }
    ret+=add;
    ret%=mod;
    return ret;
}
int main() {
    for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}