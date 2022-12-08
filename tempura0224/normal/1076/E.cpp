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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x += y;
    }
    inline T queryf(T& x,T& y){
        return x+y;
    }

public:
    SegmentTree(int sz,T E_):E(E_){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
    }

    SegmentTree(vector<T>& A,T E_):E(E_){
        int sz=A.size();
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
        rep(i,sz)node[i+n-1]=A[i];
        for(int i=n-2;i>=0;--i){
            node[i]=queryf(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int k,T x){
        k+=n-1;
        updatef(node[k],x);
        while(k>0){
            k=(k-1)/2;
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }
       //[a,b)
    T get(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return E;
        if(a<=l&&r<=b)return node[k];
        T xl=get(a,b,2*k+1,l,(l+r)/2);
        T xr=get(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    rep(i,n-1){
        int x, y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> d(n, -1);
    d[0]=0;
    auto dfs = [&](auto&& self, int x)->void{
        for(auto to: v[x]){
            if(d[to]==-1){
                d[to]=d[x]+1;
                self(self, to);
            }
        }
    };
    dfs(dfs,0);
    int m;
    cin>>m;
    vector<vector<pair<int,int>>> q(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;
        q[x].emplace_back(min(y+d[x],n),z);
    }
    SegmentTree<ll> sg(n+5, 0);
    vector<ll> ans(n);
    auto dfs2=[&](auto&& self, int x, int p)->void{
        for(auto e: q[x]){
            sg.update(e.first, e.second);
        }
        ans[x] = sg.get(d[x], n+1);
        for(auto to: v[x]){
            if(to==p)continue;
            self(self, to, x);
        }
        for(auto e: q[x]){
            sg.update(e.first, -e.second);
        }
    };
    dfs2(dfs2,0,-1);
    for(auto e: ans)cout<<e<<" ";
    cout<<endl;
    return 0;
}