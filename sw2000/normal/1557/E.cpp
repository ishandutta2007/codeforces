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
//#define endl '\n'
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
string op;int x,y;
void O(){
    cout<<x<<' '<<y<<endl;
    cin>>op;
}
void solve(){
    x=1,y=1;O();
    x=1,y=2;
    bool f=0;
    while(1){
        O();
        if(op=="Done")return;
        if(op[0]=='D'){
            x++;
            f=1;
            continue;
        }
        if(f){
            f=0;
            if(y!=2){
                y=2;
                continue;
            }
        }

        if(op[0]=='U'){
            y=(y==2)?3:2;
        }
        else if(y==7){
            x++;
            f=1;
        }
        else{
            y++;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        solve();
    }
}