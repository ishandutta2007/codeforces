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


ll n;
template<typename T,const T id>
struct ConvexHullTrick{
    struct Line{
        T a,b;
        Line(T a=0,T b=0):a(a),b(b){}
        T get(T x){return -(n-a-x)*(n-1-a-x)/2-b;}
    };

    struct Node{
        Line l;
        Node *lhs,*rhs;
        Node(Line l):l(l),lhs(nullptr),rhs(nullptr){}
    };

    const T mi,ma;
    Node* root=nullptr;

    ConvexHullTrick(T mi=0,T ma=1<<30):mi(mi),ma(ma){}
    Node* insert(Node* p,T lb,T ub,Line& l){
        if(!p)return new Node(l);
        if(p->l.get(lb)>=l.get(lb)&&p->l.get(ub)>=l.get(ub))return p;
        if(p->l.get(lb)<=l.get(lb)&&p->l.get(ub)<=l.get(ub)){
            p->l = l;
            return p;
        }
        T mid=(lb+ub)/2;
        if(p->l.get(mid)<l.get(mid))swap(p->l , l);
        if(p->l.get(lb)<=l.get(lb)){
            p->lhs=insert(p->lhs,lb,mid,l);
        }
        else {
            p->rhs=insert(p->rhs,mid,ub,l);
        }
        return p;

    }
    void insert(T a,T b){
        Line l(a,b);
        root=insert(root,mi,ma,l);
    }

    void insert(Line l){
        root=insert(root,mi,ma,l);
    }
    T query(Node* p,T lb,T ub,T t){
        if(!p)return id;
        if(lb==ub)return p->l.get(t);
        T mid=(lb+ub)/2;
        if(t<=mid)return max(p->l.get(t),query(p->lhs,lb,mid,t));
        else return max(p->l.get(t),query(p->rhs,mid,ub,t));
    }

    T query(T x){
        return query(root,mi,ma,x);
    }
};


vector<int> v[505050];
ll ans=longinf;
int dist[505050];
pair<ll,ll> dfs(int x,int p){
    ConvexHullTrick<ll,-longinf> cht;
    cht.insert(0,0);
    ll res1=1,res2=longinf;
    vector<pair<ll,ll>> b;
    for(auto to : v[x]){
        if(to==p)continue;
        auto ret = dfs(to,x);
        ans = min(ans,-cht.query(ret.first)+ret.second);
        cht.insert(ret.first, ret.second);
        res1+=ret.first;
        b.push_back(ret);
    }
    for(auto e : b){
        res2 = min(res2, (res1-e.first)*(res1-e.first-1)/2+e.second);
    }
    if(res1==1)res2=0;
    return {res1,res2};
}
int main(){
    cin>>n;
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,-1);
    cout<<n*(n-1)-ans<<endl;
    return 0;
}