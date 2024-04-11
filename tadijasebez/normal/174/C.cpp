#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int Max[M],Min[M],id[M],y[M],ls[M],rs[M],a[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ Max[c]=Min[c]=a[ss];id[c]=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	Max[c]=max(Max[ls[c]],Max[rs[c]]);
	Min[c]=min(Min[ls[c]],Min[rs[c]]);
	if(Max[c]==Max[ls[c]]) id[c]=id[ls[c]];
	else id[c]=id[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		y[c]--;
		Max[c]--;
		Min[c]--;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	Max[c]=max(Max[ls[c]],Max[rs[c]])+y[c];
	Min[c]=min(Min[ls[c]],Min[rs[c]])+y[c];
	if(Max[c]==Max[ls[c]]+y[c]) id[c]=id[ls[c]];
	else id[c]=id[rs[c]];
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return Min[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+y[c];
}
vector<pair<int,int> > sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	while(Max[root]>0)
	{
		int goal=Max[root];
		int l=id[root];
		int top=n;
		int bot=l;
		int mid,r;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(root,1,n,l,mid)==goal) r=mid,bot=mid+1;
			else top=mid-1;
		}
		sol.push_back(make_pair(l,r));
		Set(root,1,n,l,r);
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}