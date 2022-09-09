#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const long double eps=1e-14;
vector<long double> id;
int Find(long double x){ return lower_bound(id.begin(),id.end(),x-eps)-id.begin()+1;}
const int N=200050;
const int M=20*N;
int sum[M],ls[M],rs[M],root[N],tsz;
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++tsz;sum[c]=sum[p]+1;ls[c]=ls[p];rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<pair<int,int> > qs;
int x[N],v[N],L[N],R[N];
long double l[N],r[N];
vector<int> hi,lo;
int main()
{
	int n,w,i;
	scanf("%i %i",&n,&w);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x[i],&v[i]);
		if(x[i]<0)
		{
			x[i]*=-1;
			l[i]=(long double)v[i]/x[i]-(long double)w/x[i];
			r[i]=(long double)v[i]/x[i]+(long double)w/x[i];
			id.pb(l[i]);
			id.pb(r[i]);
			lo.pb(i);
		}
		else
		{
			v[i]*=-1;
			l[i]=(long double)v[i]/x[i]+(long double)w/x[i];
			r[i]=(long double)v[i]/x[i]-(long double)w/x[i];
			id.pb(l[i]);
			id.pb(r[i]);
			hi.pb(i);
		}
	}
	sort(id.begin(),id.end());
	vector<long double> tmp;
	for(i=0;i<id.size();i++)
	{
		if(tmp.size() && tmp.back()+eps>id[i]) continue;
		tmp.pb(id[i]);
	}
	id.clear();
	for(i=0;i<tmp.size();i++) id.pb(tmp[i]);
	for(i=1;i<=n;i++)
	{
		L[i]=Find(l[i]);
		R[i]=Find(r[i]);
		//printf("%i:%i %i\n",i,L[i],R[i]);
	}
	for(i=0;i<lo.size();i++)
	{
		qs.pb(mp(L[lo[i]],R[lo[i]]));
	}
	for(i=0;i<hi.size();i++)
	{
		qs.pb(mp(L[hi[i]],R[hi[i]]));
	}
	sort(qs.begin(),qs.end());
	for(i=0;i<qs.size();i++)
	{
		if(i>0) root[i]=root[i-1];
		Set(root[i],root[i],1,N,qs[i].second);
	}
	int sz=qs.size()-1;
	ll sol=0;
	for(i=0;i<hi.size();i++)
	{
		int j=hi[i];
		int rt=upper_bound(qs.begin(),qs.end(),mp(L[j],N))-qs.begin()-1;
		if(rt>=0) sol+=Get(root[rt],1,N,R[j],N);
		//if(rt>=0)
		//{
			int rt1=lower_bound(qs.begin(),qs.end(),mp(L[j],0))-qs.begin()-1;
			//printf("rt:%i rt1:%i\n",rt,rt1);
			//if(rt1>=0)
			//{
				sol+=Get(root[sz],1,N,1,R[j]);
				if(rt1>=0) sol-=Get(root[rt1],1,N,1,R[j]);
				if(rt>=0) sol-=Get(root[rt],1,N,R[j],R[j]);
				if(rt1>=0) sol+=Get(root[rt1],1,N,R[j],R[j]);
			//}
		//}
		//printf("%i %lld\n",j,sol);
	}
	for(i=0;i<lo.size();i++)
	{
		int j=lo[i];
		int rt=upper_bound(qs.begin(),qs.end(),mp(L[j],N))-qs.begin()-1;
		if(rt>=0) sol+=Get(root[rt],1,N,R[j],N);
		//if(rt>=0)
		//{
			int rt1=lower_bound(qs.begin(),qs.end(),mp(L[j],0))-qs.begin()-1;
			//printf("rt:%i rt1:%i\n",rt,rt1);
			//if(rt1>=0)
			//{
				sol+=Get(root[sz],1,N,1,R[j]);
				if(rt1>=0)sol-=Get(root[rt1],1,N,1,R[j]);
				if(rt>=0) sol-=Get(root[rt],1,N,R[j],R[j]);
				if(rt1>=0)sol+=Get(root[rt1],1,N,R[j],R[j]);
			//}
		//}
		//printf("%i %lld\n",j,sol);
	}
	printf("%lld\n",(sol-n)/2);
	return 0;
}