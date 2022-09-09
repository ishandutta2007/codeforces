#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=500050;
const int M=2*N;
int a[N],b[N],t[N],n,m,c,c0,id[N],rng[N];
struct F
{
	int B,A,id;
	F(){}
	F(int a, int c, int d):B(a),A(c),id(d){}
	bool operator < (F b) const { return B<b.B || (B==b.B && id<b.id);}
};
struct SegmentTree
{
	ll mx[M],lzy[M];
	int ls[M],rs[M],root,tsz,n;
	void init(int _n){ n=_n;while(tsz) ls[tsz]=rs[tsz]=mx[tsz]=lzy[tsz]=0,tsz--;root=0;}
	SegmentTree(){}
	void Add(int &c, int ss, int se, int qs, int qe, int f)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(!c) c=++tsz;
		if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
		int mid=ss+se>>1;
		Add(ls[c],ss,mid,qs,qe,f);
		Add(rs[c],mid+1,se,qs,qe,f);
		mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
	}
	void Add(int qs, int qe, int f){ Add(root,1,n,qs,qe,f);}
	ll Get(int c, int ss, int se, int qs, int qe)
	{
		if(qs<=ss && qe>=se) return mx[c];
		int mid=ss+se>>1;
		ll ans=lzy[c];
		if(qe<=mid) ans+=Get(ls[c],ss,mid,qs,qe);
		else if(qs>mid) ans+=Get(rs[c],mid+1,se,qs,qe);
		else ans+=max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
		return ans;
	}
	ll Get(int qs, int qe){ return Get(root,1,n,qs,qe);}
} ST;
void Solve()
{
	scanf("%i %i %i %i",&n,&m,&c,&c0);
	for(int i=1;i<=n;i++) scanf("%i %i %i",&t[i],&a[i],&b[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int i, int j){ return t[i]<t[j];});
	set<F> st;
	int domet=c0-1;
	ll ans=0;
	ST.init(n);
	for(int i=1,j;i<=n;i=j)
	{
		for(j=i;j<=n && t[id[i]]==t[id[j]];j++) rng[j]=i;
		if(t[id[i]]<c0)
		{
			for(int k=i;k<j;k++)
			{
				st.insert(F(b[id[k]],a[id[k]],k));
				ST.Add(k,k,c0-t[id[k]]);
			}
		}
		else
		{
			int len=t[id[i]]-domet-1;
			while(len>0 && st.size())
			{
				auto FR=*st.begin();
				st.erase(st.begin());
				int k=FR.id;
				int can=min((ll)FR.A,c-ST.Get(rng[k],n));
				if(can>0)
				{
					int sub=min(len,can);
					len-=sub;
					ans+=(ll)sub*FR.B;
					FR.A-=sub;
					ST.Add(rng[k],i-1,sub);
					st.insert(FR);
				}
			}
			if(len>0){ printf("-1\n");return;}
			for(int k=i;k<j;k++)
			{
				st.insert(F(b[id[k]],a[id[k]],k));
			}
			domet=t[id[i]]-1;
		}
	}
	int len=m-domet-1;
	while(len>0 && st.size())
	{
		auto FR=*st.begin();
		st.erase(st.begin());
		int k=FR.id;
		int can=min((ll)FR.A,c-ST.Get(rng[k],n));
		if(can>0)
		{
			int sub=min(len,can);
			len-=sub;
			ans+=(ll)sub*FR.B;
			FR.A-=sub;
			ST.Add(rng[k],n,sub);
			st.insert(FR);
		}
	}
	if(len>0){ printf("-1\n");return;}
	printf("%lld\n",ans);
}
int main()
{
	int q;
	scanf("%i",&q);
	while(q--) Solve();
	return 0;
}