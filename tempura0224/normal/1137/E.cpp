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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;



template<typename T>
struct ConvexHullTrick{
    struct Line{
        T a,b,idx;
        Line(T a=0,T b=0,T idx=0):a(a),b(b),idx(idx){}
        pair<ll,ll> get(T x){
			return {a*x+b,idx};
		}
    };

    struct Node{
        Line l;
        Node *lhs,*rhs;
        Node(Line l):l(l),lhs(nullptr),rhs(nullptr){}
    };

    const int n;
    const vector<T> pos;
    Node* root;
	const pair<ll,ll> id={longinf,longinf};

    ConvexHullTrick(const vector<T> &pos):n(pos.size()),pos(pos),root(nullptr){}
    Node* insert(Node* p,int lb,int ub,Line& l){
        if(!p)return new Node(l);
        if(p->l.get(pos[lb])<=l.get(pos[lb])&&p->l.get(pos[ub])<=l.get(pos[ub]))return p;
        if(p->l.get(pos[lb])>=l.get(pos[lb])&&p->l.get(pos[ub])>=l.get(pos[ub])){
            p->l = l;
            return p;
        }
        int mid=(lb+ub)/2;
        if(p->l.get(pos[mid])>l.get(pos[mid]))swap(p->l , l);
        if(p->l.get(pos[lb])>=l.get(pos[lb])){
            p->lhs=insert(p->lhs,lb,mid,l);
        }
        else {
            p->rhs=insert(p->rhs,mid+1,ub,l);
        }
        return p;

    }
    void insert(T a,T b,T idx){
        Line l(a,b,idx);
        root=insert(root,0,n-1,l);
    }
    pair<ll,ll> query(Node* p,int lb,int ub,int t){
        if(!p)return id;
        if(lb==ub)return p->l.get(pos[t]);
        int mid=(lb+ub)/2;
        if(t<=mid)return min(p->l.get(pos[t]),query(p->lhs,lb,mid,t));
        else return min(p->l.get(pos[t]),query(p->rhs,mid+1,ub,t));
    }

    pair<ll,ll> query(T x){
        int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();
        return query(root,0,n-1,t);
    }
};

struct Query{
	ll type, first, second;
};

int main(){
	int n,q;
	cin>>n>>q;
	vector<Query> query(q);
	ll sum=0;
	vector<ll> S;
	S.push_back(0);
	rep(i,q){
		ll type;
		scanf("%lld",&type);
		if(type<=2){
			ll l;
			scanf("%lld",&l);
			query[i]={type,l,0};
		}
		else {
			ll b,s;
			scanf("%lld%lld",&b,&s);
			query[i]={type,b,s};
			sum+=s;
			S.push_back(sum);
		}
	}
	ConvexHullTrick<ll> cht(S);
	ll sumb=0,sums=0;
	ll lidx=0,ridx=n;
	cht.insert(0,0,0);
	for(auto Q : query){
		if(Q.type==1){
			lidx-=Q.first;
			ll cur=sums*lidx+sumb;
			cht.insert(lidx,-cur,lidx);

		}
		else if(Q.type==2){
			ll cur=sums*ridx+sumb;
			cht.insert(ridx,-cur,ridx);
			ridx+=Q.first;
		}
		else{
			Q.first-=Q.second*lidx;
			sumb+=Q.first;
			sums+=Q.second;
		}
		auto ret=cht.query(sums);
		printf("%lld %lld\n",ret.second-lidx+1,ret.first+sumb);
	}
	return 0;
}