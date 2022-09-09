#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mp make_pair
const int N=500050;
const int M=60*N;
int max(int a, int b){ return a>b?a:b;}
int ls[M],rs[M],tsz,Max[M],root[N],id[M];
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];
	if(ss==se){ Max[c]=val;id[c]=ss;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
	Max[c]=max(Max[ls[c]],Max[rs[c]]);
	if(Max[ls[c]]==Max[c]) id[c]=id[ls[c]];
	else id[c]=id[rs[c]];
}
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return mp(0,0);
	if(qs<=ss && qe>=se) return mp(Max[c],id[c]);
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int a[N],last[N],t[N];
int main()
{
	int n,q,i,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),last[i]=n+1;
	for(i=n;i>=1;i--)
	{
		root[i]=root[i+1];
		if(last[a[i]]!=n+1) Set(root[i],root[i],1,N,last[a[i]],0);
		Set(root[i],root[i],1,N,i,last[a[i]]);
		last[a[i]]=i;
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		pair<int,int> ans=Get(root[l],1,N,l,r);
		if(ans.first<=r) printf("0\n");
		else printf("%i\n",a[ans.second]);
	}
	return 0;
}