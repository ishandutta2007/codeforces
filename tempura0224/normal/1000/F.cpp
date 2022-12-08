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
        x = y;
    }
    inline T queryf(T& x,T& y){
        return max(x, y);
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

struct B{
    int l, m, r, id;
};


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m = 500001;
    vector<vector<int>> a(m);
    rep(i,m)a[i].push_back(-1);
    rep(i,n){
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    rep(i,m)a[i].push_back(n);
    vector<B> bs;
    rep(i,m){
        if(a[i].size()==2)continue;
        rep(j,a[i].size()-2){
            bs.push_back({a[i][j]+1, a[i][j+1], a[i][j+2], i});
        }
    }
    sort(bs.begin(),bs.end(),[](auto l, auto r){
        return l.r > r.r;
    });
    SegmentTree<pair<pair<int,int>,int>> sg(n, {{-1,-1}, -1});
    vector<priority_queue<pair<int,int>>> qs(n);
    int q;
    cin>>q;
    rep(i,q){
        int l, r;
        cin>>l>>r;
        --l;
        qs[l].push({r, i});
    }
    rep(i,n){
        if(qs[i].size()){
            auto t = qs[i].top();
            sg.update(i, {t, i});
        }
    }
    vector<int> ans(q);
    for(auto b: bs){
        while(1){
            auto ret = sg.get(b.l, b.m+1);
            if(ret.first.first <=b.m)break;
            else {
                if(ret.first.first <= b.r){
                    ans[ret.first.second]=b.id;
                }
                if(qs[ret.second].size()){
                    auto t = qs[ret.second].top();
                    sg.update(ret.second, {t, ret.second});
                    qs[ret.second].pop();
                } else {
                    sg.update(ret.second, {{-1, -1}, -1});
                }
            }
        }
    }
    for(auto e: ans)cout<<e<<endl;
    return 0;
}