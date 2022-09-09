#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const ll inf=9e18;
ll p[N],a[N],x[N],b[N];
int sol[N];
multiset<pair<ll,ll> > Free;
map<ll,int> idx;
vector<ll> id;
int FindL(ll x){ return upper_bound(id.begin(),id.end(),x)-id.begin();}
int FindH(ll x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll mn[M];
void Set(int &c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz,mn[c]=inf;
	if(qs<=ss && qe>=se){ mn[c]=min(mn[c],f);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
}
ll Get(int c, int ss, int se, int qi)
{
	if(ss==se) return mn[c];
	int mid=ss+se>>1;
	if(qi<=mid) return min(mn[c],Get(ls[c],ss,mid,qi));
	else return min(mn[c],Get(rs[c],mid+1,se,qi));
}
pair<ll,ll> GetNext(ll p)
{
	auto it=Free.lower_bound(mp(p,-inf));
	if(it==Free.end()) return mp(inf,inf);
	else return *it;
}
int main()
{
	int n,m,i;mn[0]=inf;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld %lld",&p[i],&a[i]),idx[p[i]]=i;
	for(i=1;i<=m;i++) scanf("%lld %lld",&x[i],&b[i]),id.pb(x[i]);
	sort(id.begin(),id.end());
	id.resize(unique(id.begin(),id.end())-id.begin());
	int sz=id.size();
	for(i=1;i<=n;i++) Set(root,1,sz,FindH(p[i]),FindL(p[i]+a[i]),p[i]);
	for(i=1;i<=m;i++)
	{
		ll pos=Get(root,1,sz,FindH(x[i]));
		if(pos!=inf)
		{
			int j=idx[pos];
			sol[j]++;
			a[j]+=b[i];
			while(GetNext(p[j]).first<=p[j]+a[j])
			{
				pair<ll,ll> eat=GetNext(p[j]);
				Free.erase(Free.find(eat));
				sol[j]++;
				a[j]+=eat.second;
			}
			Set(root,1,sz,FindH(p[j]),FindL(p[j]+a[j]),p[j]);
		}
		else Free.insert(mp(x[i],b[i]));
	}
	for(i=1;i<=n;i++) printf("%i %lld\n",sol[i],a[i]);
	return 0;
}