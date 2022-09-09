#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
const int M=20*N;
int max(int a, int b){ return a>b?a:b;}
int s[M],p[M],x[M],ls[M],rs[M],clock,root[N];
void Set(int d, int &c, int ss, int se, int qi)
{
	c=++clock;ls[c]=ls[d];rs[c]=rs[d];
	if(ss==se){ x[c]=1;s[c]=1;p[c]=1;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[d],ls[c],ss,mid,qi);
	else Set(rs[d],rs[c],mid+1,se,qi);
	x[c]=max(x[ls[c]],x[rs[c]]);
	x[c]=max(x[c],s[ls[c]]+p[rs[c]]);
	if(p[ls[c]]==mid-ss+1) p[c]=p[ls[c]]+p[rs[c]];
	else p[c]=p[ls[c]];
	if(s[rs[c]]==se-mid) s[c]=s[rs[c]]+s[ls[c]];
	else s[c]=s[rs[c]];
}
pair<int,pair<int,int> > Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return mp(0,mp(0,0));
	if(qs<=ss && qe>=se) return mp(x[c],mp(p[c],s[c]));
	int mid=ss+se>>1;
	pair<int,pair<int,int> > ret1=Get(ls[c],ss,mid,qs,qe);
	pair<int,pair<int,int> > ret2=Get(rs[c],mid+1,se,qs,qe);
	pair<int,pair<int,int> > ret;
	ret.first=max(ret1.first,ret2.first);
	ret.first=max(ret.first,ret1.second.second+ret2.second.first);
	if(ret1.second.first==mid-ss+1) ret.second.first=ret1.second.first+ret2.second.first;
	else ret.second.first=ret1.second.first;
	if(ret2.second.second==se-mid) ret.second.second=ret1.second.second+ret2.second.second;
	else ret.second.second=ret2.second.second;
	return ret;
}
int h[N];
vector<int> id,Q[N];
int main()
{
	int n,q,i,l,r,k,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&h[i]),id.pb(h[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) Q[lower_bound(id.begin(),id.end(),h[i])-id.begin()].pb(i);
	for(i=id.size()-1;~i;i--)
	{
		root[i]=root[i+1];
		for(j=0;j<Q[i].size();j++) Set(root[i],root[i],1,n,Q[i][j]);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		int top=id.size()-1,bot=0,ans=0;
		while(top>=bot)
		{
			int mid=top+bot>>1;
			if(Get(root[mid],1,n,l,r).first>=k) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		printf("%i\n",id[ans]);
	}
	return 0;
}