#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

template<typename T> struct RMXQ_S1_GR
{
	vector<T> mx;
	int n;T inf;
	RMXQ_S1_GR(){}
	void init(int _n, T _inf){ inf=_inf;n=_n+1;mx.clear();mx.assign(n*2,-inf);}
	void Set(int i, T f){ for(i+=n,mx[i]=f;i>1;i>>=1) mx[i>>1]=max(mx[i],mx[i^1]);}
	T Get(int l, int r)
	{
		T ans=-inf;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans=max(ans,mx[l++]);
			if(r%2==0) ans=max(ans,mx[r--]);
		}
		return ans;
	}
};

template<typename T> struct Segment_Tree_S1_GR
{
	vector<T> val;
	int n;T neutral;
	function<T(T,T)> combine;
	Segment_Tree_S1_GR(){}
	void init(int _n, T _neutral, function<T(T,T)> f)
	{
		neutral=_neutral;
		n=_n+1;
		val.clear();
		val.assign(n*2,neutral);
		combine=f;
	}
	void Set(int i, T f)
	{
		i+=n;
		val[i]=f;
		for(i>>=1;i>1;i>>=1)
			val[i]=combine(val[i<<1],val[i<<1|1]);
	}
	T Get(int l, int r)
	{
		T ans_l=neutral;
		T ans_r=neutral;
		for(l+=n,r+=n;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans_l=combine(ans_l,val[l++]);
			if(r%2==0) ans_r=combine(val[r--],ans_r);
		}
		return combine(ans_l,ans_r);
	}
};

template<typename T> struct BIT
{
	vector<T> val;
	int n;T neutral;
	function<T(T,T)> combine,subtract;
	void init(int _n, T _neutral, function<T(T,T)> f, function<T(T,T)> g=[](T a, T b){ return a-b;})
	{
		neutral=_neutral;
		n=_n+1;
		val.clear();
		val.assign(n,neutral);
		combine=f;
		subtract=g;
	}
	void Set(int i, T f){ for(;i<n;i+=i&-i) val[i]=combine(val[i],f);}
	void Set(int l, int r, T f){ Set(l,f);Set(r+1,-f);}
	T Get(int i){ T ans=neutral;for(;i;i-=i&-i) ans=combine(val[i],ans);return ans;}
	T Get(int l, int r){ return subtract(Get(r),Get(l-1));}
};

template<typename Node, typename Tag> struct Segment_Tree_Lazy
{
	vector<Node> val;
	vector<Tag> lzy;
	int n;Node neutral_node;Tag neutral_tag;
	function<Node(Node,Node,int,int)> combine;
	function<Node(Node,Tag,int,int)> upd;
	function<Tag(Tag,Tag)> combine_tags;
	void init(int _n, Node _neutral_node, Tag _neutral_tag, function<Node(Node,Node,int,int)> f, function<Node(Node,Tag,int,int)> g, function<Tag(Tag,Tag)> h)
	{
		neutral_node=_neutral_node;
		neutral_tag=_neutral_tag;
		n=_n;
		val.clear();
		val.assign(4*n,neutral_node);
		lzy.clear();
		lzy.assign(4*n,neutral_tag);
		combine=f;
		upd=g;
		combine_tags=h;
	}
	void upd_node(int c, int ss, int se, Tag t)
	{
		val[c]=upd(val[c],t,ss,se);
		lzy[c]=combine_tags(lzy[c],t);
	}
	void push(int c, int ss, int se)
	{
		int mid=ss+se>>1;
		upd_node(c<<1,ss,mid,lzy[c]);
		upd_node(c<<1|1,mid+1,se,lzy[c]);
		lzy[c]=neutral_tag;
	}
	void Set(int c, int ss, int se, int qi, Node f)
	{
		if(ss==se){ val[c]=f;return;}
		int mid=ss+se>>1;
		push(c,ss,se);
		qi<=mid?Set(c<<1,ss,mid,qi,f):Set(c<<1|1,mid+1,se,qi,f);
		val[c]=combine(val[c<<1],val[c<<1|1],mid-ss+1,se-mid);
	}
	void Set(int qi, Node f){ Set(1,1,n,qi,f);}
	void Add(int c, int ss, int se, int qs, int qe, Tag t)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(qs<=ss && qe>=se){ upd_node(c,ss,se,t);return;}
		int mid=ss+se>>1;
		push(c,ss,se);
		Add(c<<1,ss,mid,qs,qe,t);
		Add(c<<1|1,mid+1,se,qs,qe,t);
		val[c]=combine(val[c<<1],val[c<<1|1],mid-ss+1,se-mid);
	}
	void Add(int qs, int qe, Tag t){ Add(1,1,n,qs,qe,t);}
	Node Get(int c, int ss, int se, int qi)
	{
		if(ss==se) return val[c];
		int mid=ss+se>>1;
		push(c,ss,se);
		return qi<=mid?Get(c<<1,ss,mid,qi):Get(c<<1|1,mid+1,se,qi);
	}
	Node Get(int qi){ return Get(1,1,n,qi);}
	Node Get(int c, int ss, int se, int qs, int qe)
	{
		if(qs>qe) return neutral_node;
		if(qs<=ss && qe>=se) return val[c];
		int mid=ss+se>>1;
		push(c,ss,se);
		if(qe<=mid) return Get(c<<1,ss,mid,qs,qe);
		if(qs>mid) return Get(c<<1|1,mid+1,se,qs,qe);
		return combine(Get(c<<1,ss,mid,qs,qe),Get(c<<1|1,mid+1,se,qs,qe),mid-max(ss,qs)+1,min(se,qe)-mid);
	}
	Node Get(int qs, int qe){ return Get(1,1,n,qs,qe);}
};

/*template<typename T> struct Implicit_Segment_Tree
{
	vector<int> ls,rs;

	void push(int c, int ss, int se){}
	void pull(int c, int ss, int se){}
}*/


/*struct Node
{
	int l,r,sz,ans;
	Node(){}
	Node(int x){ l=r=ans=x;sz=1;}
	Node(int a, int b, int c, int d):l(a),r(b),sz(c),ans(d){}
};*/
const int N=100050;
const int A=26;
const int mod=998244353;
const int base=37;
char s[N];
int main()
{
	int n,m,k,q,l,r,d;
	scanf("%i %i %i",&n,&k,&m);
	q=m+k;
	scanf("%s",s+1);
	vector<int> po(n+1),sum(n+1);
	po[0]=1;for(int i=1;i<=n;i++) po[i]=(ll)po[i-1]*base%mod;
	sum[0]=1;for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+po[i])%mod;
	Segment_Tree_Lazy<int,int> ST;
	ST.init(n,0,-1,[&](int x, int y, int l, int r)
		{
			return ((ll)y*po[l]+x)%mod;
		},[&](int x, int y, int ss, int se)
		{
			return y==-1?x:(ll)y*sum[se-ss]%mod;
		},[](int x, int y)
		{
			return y==-1?x:y;
		});
	for(int i=1;i<=n;i++) ST.Set(i,s[i]-'0');
	while(q--)
	{
		int t,l,r,d;
		scanf("%i %i %i %i",&t,&l,&r,&d);
		if(t==1) ST.Add(l,r,d);
		else
		{
			//printf("%i %i\n",ST.Get(l,r-d),ST.Get(l+d,r));
			if(ST.Get(l,r-d)==ST.Get(l+d,r)) printf("YES\n");
			else printf("NO\n");
		}
	}

	/*Segment_Tree_Lazy<int,int> ST[A];
	for(int i=0;i<A;i++) ST[i].init(n,0,-1,[](int x, int y, int ss, int se){ return x+y;},[](int x, int y, int ss, int se){ return y==-1?x:(se-ss+1)*y;},[](int x, int y){ return y==-1?x:y;});
	for(int i=1;i<=n;i++) ST[s[i]-'a'].Set(i,1);
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		vector<int> cnt(A,0);
		for(int i=0;i<A;i++) cnt[i]=ST[i].Get(l,r),ST[i].Add(l,r,0);
		if(k==1) for(int i=0,sum=0;i<A;sum+=cnt[i],i++) ST[i].Add(l+sum,l+sum+cnt[i]-1,1);
		else for(int i=A-1,sum=0;~i;sum+=cnt[i],i--) ST[i].Add(l+sum,l+sum+cnt[i]-1,1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<A;j++)
			if(ST[j].Get(i)==1)
				printf("%c",'a'+j);
	}
	printf("\n");*/
	/*int n,q;
	scanf("%i %i",&n,&q);
	//Segment_Tree_S1_GR<Node> ST;
	//ST.init(n,Node(0,0,0,0),[](Node x, Node y){ return Node(x.l==x.sz?x.sz+y.l:x.l,y.r==y.sz?y.sz+x.r:y.r,x.sz+y.sz,max({x.ans,y.ans,x.r+y.l}));});
	BIT<ll> ST;
	ST.init(n,0,[](int x, int y){ return x+y;},[](int x, int y){ return x-y;});
	for(int i=1,x;i<=n;i++) scanf("%i",&x),ST.Set(i,x);//,ST.Set(i,Node(x));
	while(q--)
	{
		int l,r;
		scanf("%i %i",&l,&r);
		printf("%i\n",ST.Get(l,r));
	}*/
	return 0;
}