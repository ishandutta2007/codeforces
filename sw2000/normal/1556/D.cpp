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
//#define endl '\n'
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

int f(int x,int a,int b){
    ll ret=0;
    for(int i=0;i<30;i++){
        if(x&1<<i){
            ret+=a&1<<i;
        }
        else{
            ret+=b&1<<i;
        }
    }
    return ret;
}
int n,k;
int ar[N],a[N],b[N];
int main() {
//    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    cin>>n>>k;
    for(int i=0;i<3;i++){
        cout<<"and "<<i+1<<" "<<(i+1)%3+1<<endl;
        cin>>a[i];
        cout<<"or "<<i+1<<" "<<(i+1)%3+1<<endl;
        cin>>b[i];
    }
    for(int i=0;i<30;i++){
        if((b[1]&1<<i)==0){
            if(b[0]&1<<i)ar[1]+=1<<i;
        }
    }
    ar[1]+=b[1]&(a[0]|a[2]);

    ar[2]=f(ar[1],a[0],b[0]);
    ar[3]=f(ar[1],a[2],b[2]);
    for(int i=4;i<=n;i++){
        cout<<"and "<<i<<" "<<1<<endl;
        cin>>a[i];
        cout<<"or "<<i<<" "<<1<<endl;
        cin>>b[i];
        ar[i]=f(ar[1],a[i],b[i]);
    }
    sort(ar+1,ar+1+n);
    cout<<"finish "<<ar[k]<<endl;
}