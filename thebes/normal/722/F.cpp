#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

pll exgcd(ll a,ll b){
    if(!a) return make_pair(0LL,1LL);
    pll res = exgcd(b%a,a);
    return make_pair(res.second-(b/a)*res.first,res.first);
}

const int MN = 1e5+5, LG = 18;
ll N, M, i, j, x, y, k, len[MN], ans[MN], g, bs, ml; pll sp[MN][LG], ret, inv, res;
vector<pll> id[MN]; pll a, b;
/*
inline pll mrg(pll a,pll b){
    if(a.first==-1||b.first==-1) return make_pair(-1,-1);
    g = __gcd(a.first,b.first);
    if(a.second%g!=b.second%g) return make_pair(-1,-1);
    ret = {a.first*b.first/g,0};
    bs = a.second%g;
    inv = exgcd(a.first/g,b.first/g);
    ml = ret.first/g;
    ret.second=(b.second-bs)/g*a.first/g%ml*inv.first%ml+(a.second-bs)/g*b.first/g%ml*inv.second%ml;
    while(ret.second<0) ret.second += ml;
    while(ret.second>=ml) ret.second -= ml;
    ret.second *= g; ret.second += bs;
    return ret;
}
*/

int main(){
    for(scanf("%lld%lld",&N,&M),i=1;i<=N;i++){
        scanf("%lld",&len[i]);
        for(j=0;j<len[i];j++){
            scanf("%lld",&x);
            id[x].pb({i,j});
        }
    }
    for(k=1;k<=M;k++){
        ll pre=-1, seg, tmp, cur, idx; pll go;
        ll lst[41], pos[41], ptr;
        for(auto v : id[k]){
            /*if(v.first==pre+1) seg++;
            else seg=1;
            pre = v.first; tmp = seg;
            sp[v.first][0]=make_pair(len[v.first],v.second);
            go = sp[v.first][0];
            for(j=1;j<LG&&(1<<j)<=seg;j++){
                a = sp[v.first][j-1];
                b = sp[v.first-(1<<(j-1))][j-1];
                sp[v.first][j] = mrg(a,b);
            }
            idx = v.first, cur = 0;
            for(j=LG-1;j>=0;j--){
                if((1<<j)<=tmp&&sp[idx][j].first!=-1){
                    g = __gcd(sp[idx][j].first,go.first);
                    if(sp[idx][j].second%g!=go.second%g) continue;
                    res=mrg(sp[idx][j],go);
                    if(res.first!=-1){
                        tmp -= (1<<j);
                        cur += (1<<j);
                        go = res;
                        idx -= (1<<j);
                    }
                }
            }
            ans[k]=max(ans[k],cur);*/
            if(pre+1!=v.first) ptr=v.first, memset(lst,-1,sizeof(lst));
            pre = v.first;
            for(j=1;j<=40;j++){
                if(lst[j]==-1) continue;
                ll g = __gcd(j,len[v.first]);
                if(pos[j]%g!=v.second%g) ptr=max(ptr,lst[j]+1);
            }
            lst[len[v.first]]=v.first;
            pos[len[v.first]]=v.second;
            ans[k]=max(ans[k],v.first-ptr+1);
        }
        printf("%lld\n",ans[k]);
    }
    return 0;
}