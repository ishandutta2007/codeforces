#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int M=60*N*2;
const ll lim=2e16+7;
const int inf=1e9+7;
/*int root[2],tsz,ls[M],rs[M],mx[M];
void Set(int &c, ll ss, ll se, ll qi, int val)
{
	if(!c) c=++tsz;
	if(ss==se){ mx[c]=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
int Get(int c, ll ss, ll se, ll qs, ll qe)
{
	if(qs>qe || qs>se || ss>qe) return mx[0];
	if(qs<=ss && qe>=se) return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
void Clear()
{
	for(int i=1;i<=tsz;i++) ls[i]=rs[i]=mx[i]=0;
	root[0]=root[1]=tsz=0;
}*/
int t[N],x[N],id[N],n,v;
pair<ll,ll> p[N];
ll s[N];
int Solve(bool zero)
{
	int ans=0;
	s[0]=-inf;
	for(int j=1;j<=n;j++)
	{
		int i=id[j];
		if(zero && (p[i].first<0 || p[i].second<0)) continue;
        if(p[i].second>=s[ans]) s[++ans]=p[i].second;
        else *upper_bound(s+1,s+1+ans,p[i].second)=p[i].second;
	}
	/*for(int j=1;j<=n;j++)
	{
		int i=id[j];
		int tmp=max(Get(root[0],-lim,lim,x[i]-v*t[i],x[i]),Get(root[1],-lim,lim,x[i],x[i]+v*t[i]))+1;
		ans=max(ans,tmp);
		Set(root[0],-lim,lim,x[i]-t[i]*v,tmp);
		Set(root[1],-lim,lim,x[i]+t[i]*v,tmp);
	}*/
	return ans;
}
int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i",&x[i],&t[i]),id[i]=i;
	scanf("%i",&v);
	for(int i=1;i<=n;i++) p[i]={(ll)t[i]*v-x[i],(ll)t[i]*v+x[i]};
	sort(id+1,id+1+n,[&](int i, int j){ return p[i]<p[j];});
	int ans1=Solve(1);
	int ans2=Solve(0);
	printf("%i %i\n",ans1,ans2);
	return 0;
}