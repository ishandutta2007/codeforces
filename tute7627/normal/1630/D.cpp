//from https://mojacoder.app/users/hotman78/problems/flipping-signs-2/submissions/b1f43149-fad9-4794-9e27-f89b866ddcc3

#include<bits/stdc++.h>
using namespace std;
struct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define endl ('\n')
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>using V=vector<T>;
template<typename T>using VV=V<V<T>>;
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void debug(T t){bool f=0;for(auto i:t){cerr<<(f?" ":"")<<i;f=1;}cerr<<endl;}
template<typename T>inline void debug2(T t){for(auto i:t)output(i);}
#define loop(n) for(long long _=0;_<(long long)(n);++_)
#define _overload4(_1,_2,_3,_4,name,...) name
#define __rep(i,a) repi(i,0,a,1)
#define _rep(i,a,b) repi(i,a,b,1)
#define repi(i,a,b,c) for(long long i=(long long)(a);i<(long long)(b);i+=c)
#define rep(...) _overload4(__VA_ARGS__,repi,_rep,__rep)(__VA_ARGS__)
#define _overload3_rev(_1,_2,_3,name,...) name
#define _rep_rev(i,a) repi_rev(i,0,a)
#define repi_rev(i,a,b) for(long long i=(long long)(b)-1;i>=(long long)(a);--i)
#define rrep(...) _overload3_rev(__VA_ARGS__,repi_rev,_rep_rev)(__VA_ARGS__)

// #define rep(i,...) for(auto i:range(__VA_ARGS__)) 
// #define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))
// #define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
// #define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
// #define irep(i) for(lint i=0;;++i)
// inline vector<long long> range(long long n){if(n<=0)return vector<long long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}
// inline vector<long long> range(long long a,long long b){if(b<=a)return vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}
// inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
// template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#define extrep(v,...) for(auto v:__MAKE_MAT__({__VA_ARGS__}))
#define bit(n,a) ((n>>a)&1)
vector<vector<long long>> __MAKE_MAT__(vector<long long> v){if(v.empty())return vector<vector<long long>>(1,vector<long long>());long long n=v.back();v.pop_back();vector<vector<long long>> ret;vector<vector<long long>> tmp=__MAKE_MAT__(v);for(auto e:tmp)for(long long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return ret;}
using graph=vector<vector<int>>;
template<typename T>using graph_w=vector<vector<pair<int,T>>>;
template<typename T,typename E>ostream& operator<<(ostream& out,pair<T,E>v){out<<"("<<v.first<<","<<v.second<<")";return out;}
constexpr inline long long powll(long long a,long long b){long long res=1;while(b--)res*=a;return res;}
#line 2 "code.cpp"

lint solve(){
    lint n,k;
    cin>>n;
    lint m;
    cin >> m;
    vec a(n);
    rep(i,n)cin>>a[i];
    k = 0;
    for(int i=0;i<m;i++){
      lint b;cin>>b;
      k=gcd(k,b);
    }
    lint ans=0;
    {
        lint ans2=0;
        mat v(k);
        rep(i,n){
            v[i%k].push_back(a[i]);
        }
        for(auto e:v){
            lint cnt=0;
            for(auto s:e)cnt+=(s<0);
            for(auto& s:e)s=abs(s);
            ans2+=SUM(e)-(cnt%2*(*min_element(all(e))))*2;
        }
        chmax(ans,ans2);
    }
    rep(i,k)a[i]*=-1;
    {
        lint ans2=0;
        mat v(k);
        rep(i,n){
            v[i%k].push_back(a[i]);
        }
        for(auto e:v){
            lint cnt=0;
            for(auto s:e)cnt+=(s<0);
            for(auto& s:e)s=abs(s);
            ans2+=SUM(e)-(cnt%2*(*min_element(all(e))))*2;
        }
        chmax(ans,ans2);
    }
    return ans;
}

int main(){
    //random_device rnd;
    int t;
    cin >> t;
    while(t--){
      cout<<solve()<<endl;
    }
    // rep(i,20){
    //     string s=to_string(i);
    //     while(s.size()<2)s="0"+s;
    //     freopen(("in/00_small_"+s+".txt").c_str(),"w",stdout);
    //     lint n=rnd()%20+1,k=rnd()%n+1;
    //     vec a(n);
    //     rep(i,n){
    //         a[i]=lint(rnd()%2'000'000'001LL)-1'000'000'000LL;
    //     }
    //     cout<<n<<" "<<k<<endl;
    //     output(a);
    //     cout<<flush;
    // }
    // rep(i,20){
    //     string s=to_string(i);
    //     while(s.size()<2)s="0"+s;
    //     freopen(("in/01_random_"+s+".txt").c_str(),"w",stdout);
    //     lint n=rnd()%100000+1,k=rnd()%n+1;
    //     vec a(n);
    //     rep(i,n){
    //         a[i]=lint(rnd()%2'000'000'001LL)-1'000'000'000LL;
    //     }
    //     cout<<n<<" "<<k<<endl;
    //     output(a);
    //     cout<<flush;
    // }
    // rep(i,20){
    //     string s=to_string(i);
    //     while(s.size()<2)s="0"+s;
    //     freopen(("in/00_small_"+s+".txt").c_str(),"r",stdin);
    //     freopen(("out/00_small_"+s+".txt").c_str(),"w",stdout);
    //     cout<<solve()<<endl<<flush;
    // }
    // rep(i,20){
    //     string s=to_string(i);
    //     while(s.size()<2)s="0"+s;
    //     freopen(("in/01_random_"+s+".txt").c_str(),"r",stdin);
    //     freopen(("out/01_random_"+s+".txt").c_str(),"w",stdout);
    //     cout<<solve()<<endl<<flush;
    // }
}