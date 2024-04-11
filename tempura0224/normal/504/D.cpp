#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

constexpr int S = 2048;
using B = bitset<2048>;

vector<B> a;
vector<B> d;
vector<int> c(S,-1);
B add(B& b){
    int n  = a.size();
    B ans;
    rep(i,S){
        if(b[i]==0||c[i]==-1)continue;
        b^=a[c[i]];
        ans^=d[c[i]];
    }
    a.push_back(b);
    ans[n]=1;
    d.push_back(ans);
    ans[n]=0;
    rep(i,S){
        if(b[i]==1){
            c[i]=n;
            break;
        }
    }
    if(b==0)return ans;
    else return {};
}
using ull = unsigned long long;

vector<ull> add(vector<ull> a,vector<ull> b){
    ull d = 0;
    vector<ull> res;
    while(a.size()<b.size())a.push_back(0);
    while(b.size()<a.size())b.push_back(0);
    rep(i,a.size()){
        res.push_back((a[i]+b[i]+d)&((1ll<<32)-1));
        d = (a[i]+b[i]+d)>>32;
    }
    if(d)res.push_back(1);
    return res;
}
vector<ull> mul(vector<ull>& a,ull k){
    vector<ull> mulk;
    ull dk = 0;
    rep(i,a.size()){
        mulk.push_back((a[i]*k+dk)&((1ll<<32)-1));
        dk = (a[i]*k+dk)>>32;
    }
    if(dk)mulk.push_back(dk);
    return  mulk;
}

vector<ull> calc(string& s){
    int n=s.size();
    vector<ull> a;
    ull x = 0;
    ull d = 1;
    rep(i,n){
        x = 10*x+s[i]-'0';
        d*=10;
        if(i%9==8){
            vector<ull> b(1,x);
            a = add(b, mul(a,d));
            d=1;
            x=0;
        }
    }
    vector<ull> b(1,x);
    a = add(b, mul(a,d));
    return a;
}

B vec_to_B(vector<ull> v){
    B ans;
    rep(i,v.size()){
        B z(v[i]);
        ans ^= z<<(32*i);
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        auto ret = vec_to_B(calc(s));
        auto ans = add(ret);
        cout<<ans.count()<<" ";
        rep(e,S)if(ans[e])cout<<e<<" ";
        cout<<"\n";
    }

    return 0;
}