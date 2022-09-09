#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
struct Line{ ll k,n;int id;Line(ll a=0, ll b=0, int c=0):k(a),n(b),id(c){}pair<ll,int> Get(ll x){ return mp(k*x+n,id);}};
bool operator < (Line a, Line b){ return a.k<b.k || (a.k==b.k && a.n>b.n);}
pair<ll,int> max(pair<ll,int> a, pair<ll,int> b){ return a>b?a:b;}
ll sec(Line a, Line b)
{
	ll p=a.n-b.n,q=b.k-a.k;
	if(q<0) q=-q,p=-p;
	if(p<0) return p/q;
	else return (p+q-1)/q;
}
const int N=100050;
const int M=2*N;
int ls[M],rs[M],tsz,root,a[N],b[N],ptr[M];
vector<Line> Hull[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ Hull[c].pb(Line(b[ss],a[ss],ss));return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	int i=0,j=0;
	while(i<Hull[ls[c]].size() || j<Hull[rs[c]].size())
	{
		if(i==Hull[ls[c]].size()) Hull[c].pb(Hull[rs[c]][j++]);
		else if(j==Hull[rs[c]].size()) Hull[c].pb(Hull[ls[c]][i++]);
		else if(Hull[ls[c]][i]<Hull[rs[c]][j]) Hull[c].pb(Hull[ls[c]][i++]);
		else Hull[c].pb(Hull[rs[c]][j++]);
	}
	int sz=1;
	for(i=1;i<Hull[c].size();i++)
	{
		if(Hull[c][sz-1].k==Hull[c][i].k) continue;
		while(sz>1 && sec(Hull[c][sz-1],Hull[c][sz-2])>=sec(Hull[c][sz-1],Hull[c][i])) sz--;
		Hull[c][sz++]=Hull[c][i];
	}
	Hull[c].resize(sz);
}
pair<ll,int> Get(int c, int ss, int se, int qs, int qe, int t)
{
	if(qs<=ss && qe>=se)
	{
		while(ptr[c]+1<Hull[c].size() && Hull[c][ptr[c]+1].Get(t)>Hull[c][ptr[c]].Get(t)) ptr[c]++;
		return Hull[c][ptr[c]].Get(t);
	}
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe,t);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe,t);
	return max(Get(ls[c],ss,mid,qs,qe,t),Get(rs[c],mid+1,se,qs,qe,t));
}
int l[N],r[N],t[N],id[N],ans[N];
bool comp(int i, int j){ return t[i]<t[j];}
int main()
{
	int n,q,i,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]);
	Build(root,1,n);
	for(i=1;i<=q;i++) scanf("%i %i %i",&l[i],&r[i],&t[i]),id[i]=i;
	sort(id+1,id+1+q,comp);
	for(j=1;j<=q;j++)
	{
		i=id[j];
		ans[i]=Get(root,1,n,l[i],r[i],t[i]).second;
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}