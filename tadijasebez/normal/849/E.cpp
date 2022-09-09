#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mt make_tuple
const int N=100050;
set<int> id[N];
vector<tuple<int,int,int> > Qs;
int n;
struct BIT
{
	vector<int> val[N];
	vector<ll> sum[N];
	int Find(int i, int j){ return lower_bound(val[i].begin(),val[i].end(),j+1)-val[i].begin();}
	void Pre(int x, int y){ for(int i=x;i<=n;i+=i&-i) val[i].pb(y);}
	void Sort(int x){ sort(val[x].begin(),val[x].end());val[x].erase(unique(val[x].begin(),val[x].end()),val[x].end());sum[x].resize(val[x].size()+1);}
	void Sort(){ for(int i=1;i<=n;i++) Sort(i);}
	void Add(int x, int y, int f){ for(int i=x;i<=n;i+=i&-i) for(int j=Find(i,y);j<sum[i].size();j+=j&-j) sum[i][j]+=f;}
	ll Get(int x, int y){ ll ans=0;for(int i=x;i;i-=i&-i) for(int j=Find(i,y);j;j-=j&-j) ans+=sum[i][j];return ans;}
} L,R;
int a[N],b[N];
void Ins(int i, int v)
{
	id[v].insert(i);
	auto it=id[v].find(i);
	bool lf=0,rf=0;
	int l,r;
	if(it!=id[v].begin()) it--,l=*it,it++,lf=1;
	it++;if(it!=id[v].end()) r=*it,rf=1;it--;
	if(rf) L.Pre(r,i),R.Pre(r,r);
	if(lf) L.Pre(i,l),R.Pre(i,i);
}
void Del(int i, int v)
{
	auto it=id[v].find(i);
	bool lf=0,rf=0;
	int l,r;
	if(it!=id[v].begin()) it--,l=*it,it++,lf=1;
	it++;if(it!=id[v].end()) r=*it,rf=1;it--;
	if(lf && rf) L.Pre(r,l),R.Pre(r,r);
	id[v].erase(i);
}
void Add(int i, int v)
{
	id[v].insert(i);
	auto it=id[v].find(i);
	bool lf=0,rf=0;
	int l,r;
	if(it!=id[v].begin()) it--,l=*it,it++,lf=1;
	it++;if(it!=id[v].end()) r=*it,rf=1;it--;
	if(lf && rf) L.Add(r,l,-abs(r-l)),R.Add(r,r,-abs(r-l));
	if(rf) L.Add(r,i,abs(r-i)),R.Add(r,r,abs(r-i));
	if(lf) L.Add(i,l,abs(i-l)),R.Add(i,i,abs(i-l));
}
void Sub(int i, int v)
{
	auto it=id[v].find(i);
	bool lf=0,rf=0;
	int l,r;
	if(it!=id[v].begin()) it--,l=*it,it++,lf=1;
	it++;if(it!=id[v].end()) r=*it,rf=1;it--;
	if(lf && rf) L.Add(r,l,abs(r-l)),R.Add(r,r,abs(r-l));
	if(rf) L.Add(r,i,-abs(r-i)),R.Add(r,r,-abs(r-i));
	if(lf) L.Add(i,l,-abs(i-l)),R.Add(i,i,-abs(i-l));
	id[v].erase(i);
}
int main()
{
	int q,i,t,x,y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),b[i]=a[i],Ins(i,a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&t,&x,&y);
		if(t==1) Del(x,b[x]),Ins(x,y),b[x]=y;
		Qs.pb(mt(t,x,y));
	}
	L.Sort();R.Sort();
	for(i=1;i<=n;i++) id[i].clear();
	for(i=1;i<=n;i++) b[i]=a[i],Add(i,a[i]);
	for(i=0;i<q;i++)
	{
        if(get<0>(Qs[i])==1)
		{
			Sub(get<1>(Qs[i]),b[get<1>(Qs[i])]);
			Add(get<1>(Qs[i]),get<2>(Qs[i]));
			b[get<1>(Qs[i])]=get<2>(Qs[i]);
		}
		else
		{
			printf("%lld\n",R.Get(get<2>(Qs[i]),get<2>(Qs[i]))-L.Get(get<2>(Qs[i]),get<1>(Qs[i])-1));
		}
	}
	return 0;
}