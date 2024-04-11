#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef unsigned long long int ll; 
typedef long double ld;
typedef vector<ll> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

const int maxn=int(1e5)+5;
const ll p=1000033LL;
const ll mod=ll(1e9)+7;
ll pw[maxn];
ll pwacc[maxn];

struct sg{
    vi v,sz;
    vector<int> lazy;
    int n;
    sg(int _n){
        n=1;
        while(n<_n)n<<=1;
        v.assign(n*2,0);
        lazy.assign(n*2,-1);
        sz.assign(n*2,1);
    }
    ll comb(ll a, ll b, int sz_a){
        return (a+pw[sz_a]*b)%mod;
    }
    void build(vi s){
        rep(i,0,s.size()){
            v[i+n]=s[i];
        } 
        for(int i=n-1;i>0;i--){
            v[i]=comb(v[2*i],v[2*i+1],sz[2*i]);
            sz[i]=sz[2*i]+sz[2*i+1];
        }
    }
    void prop(){
        rep(i,1,n){
            push(i);
        }
    }
    void push(int i){
        if(lazy[i]!=-1){
            lazy[2*i]=lazy[2*i+1]=lazy[i];
            v[2*i]=v[2*i+1]=(pwacc[sz[2*i]]*lazy[i])%mod;
            lazy[i]=-1;
        }
    }
    pair<ll,int> get_hash(int l, int r,int x=0,int y=-1,int i=1){
        if(y==-1)y=n;
        if(r<=x || y<=l)return mp(0,0);
        if(l<=x && y<=r)return mp(v[i],y-x);
        push(i);
        int mid=(x+y)/2;
        pair<ll,int> left  = get_hash(l,r,x,mid,2*i);
        pair<ll,int> right = get_hash(l,r,mid,y,2*i+1);
        return mp(comb(left.X,right.X,left.Y),left.Y+right.Y);
    }
    void update(int val,int l, int r,int x=0,int y=-1,int i=1){
        if(y==-1)y=n;
        //cout<<x<<" "<<y<<endl;
        if(r<=x || y<=l)return;
        if(l<=x && y<=r){
            lazy[i]=val;
            v[i]=pwacc[sz[i]]*val;
            return;
        }
        push(i);
        int mid=(x+y)/2;
        update(val,l,r,x,mid,2*i);
        update(val,l,r,mid,y,2*i+1);
        v[i]=comb(v[2*i],v[2*i+1],sz[2*i]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pw[0]=1;
    pwacc[0]=0;
    rep(i,1,maxn) pwacc[i] = (pwacc[i-1] + pw[i-1])%mod, pw[i]=(pw[i-1]*p)%mod;
    int n,m,k;
    cin>>n>>m>>k;
    string s; cin>>s;
    vi v(n); 
    rep(i,0,n)v[i]=s[i]-'0';
    sg st(n);
    st.build(v);
    rep(i,0,m+k){
        int l,r,x,t;
        cin>>t>>l>>r>>x; --l;
        if(t==2){
            //cout<<l<<" "<<r-x<<endl;
            //cout<<l+x<<" "<<r<<endl;
            ll left = st.get_hash(l,r-x).X;
            ll right = st.get_hash(l+x,r).X;
            //cout<<left<<" "<<right<<endl;
            cout<<(left==right?"YES":"NO")<<"\n";
            ////cout<<flush;
        }
        else{
            st.update(x,l,r);
        }
        //st.prop();
        // rep(i,1,2*st.n){
        //     if(__builtin_clz(i)!=__builtin_clz(i-1))cout<<endl;
        //     cout<<st.v[i]<<" ";
        // }
        //cout<<endl;
    }
    return 0;
}