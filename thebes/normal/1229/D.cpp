#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
        void __(unsigned x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
        template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 2e5+5, MK = 122;
int N, K, i, j, k, x, y, sz[MK], ds[MK], o[MK], nxt; ll ans;
struct edge{int x,y,i;};
vector<edge> a, b, e;
map<vi,int> mp;
vi ree, avai, p[MN];
vector<vi> heh;

void init(int k,vi avail){
        if(!k) mp[ree]=nxt++, heh.pb(ree);
        else{
                vi eat_cheese;
                for(int i=0;i<avail.size();i++){
                        eat_cheese.clear();
                        for(int j=0;j<avail.size();j++){
                                if(i!=j) eat_cheese.pb(avail[j]);
                        }
                        ree.pb(avail[i]);
                        init(k-1,eat_cheese);
                        ree.pop_back();
                }
        }
}

int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}

int main(){
        for(scanf("%d%d",&N,&K),i=1;i<=N;i++){
                for(j=0;j<K;j++){
                        scanf("%d",&x); x--;
                        p[i].pb(x);
                }
        }
        for(i=1;i<=K;i++) avai.pb(i);
        init(K,avai);
        avai.resize(K);
        for(j=N;j>=1;j--){
                for(i=0;i<heh.size();i++){
                        ree=heh[i];
                        for(k=0;k<K;k++){
                                avai[k]=ree[p[j][k]];
                        }
                        a.pb({i,mp[avai],j});
                }
                b.clear();
                for(i=1;i<=mp.size();i++) ds[i]=i, sz[i]=1, o[i]=0;
                o[0]=1;
                for(i=a.size()-1;i>=0;i--){
                        x=a[i].x, y=a[i].y;
                        if(fnd(x)!=fnd(y)){
                                b.pb(a[i]);
                                x=fnd(x), y=fnd(y);
                                if(o[x]!=o[y]){
                                        if(o[x]<o[y]) swap(x,y);
                                        ans+=1LL*sz[y]*(N-a[i].i+1);
                                }
                                o[x]|=o[y];
                                sz[x]+=sz[y];
                                ds[y]=x;
                        }
                }
                a.clear();
                for(i=b.size()-1;i>=0;i--) a.pb(b[i]);
                ans+=N-j+1;
        }
        printf("%lld\n",ans);
        return 0;
}