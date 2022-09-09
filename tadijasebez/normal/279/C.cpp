#include <stdio.h>
#include <algorithm>
using namespace std;
#define mp make_pair
const int N=100050;
const int M=2*N;
int ls[M],rs[M],k1[M],k2[M],tsz,root,a[N];
pair<int,int> x[M];
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		x[c]=mp(a[ss],ss);
		k1[c]=a[ss]<=a[ss+1];
		k2[c]=a[ss]>=a[ss+1];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=max(x[ls[c]],x[rs[c]]);
	k1[c]=k1[ls[c]]+k1[rs[c]];
	k2[c]=k2[ls[c]]+k2[rs[c]];
}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return mp(0,0);
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
pair<int,int> operator + (pair<int,int> a, pair<int,int> b){ a.first+=b.first;a.second+=b.second;return a;}
pair<int,int> Take(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe || qs>qe) return mp(0,0);
	if(qs<=ss && qe>=se) return mp(k1[c],k2[c]);
	int mid=ss+se>>1;
	return Take(ls[c],ss,mid,qs,qe)+Take(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,i,q,l,r;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		int id=Get(root,1,n,l,r).second;
		if(Take(root,1,n,l,id-1).first==id-l && Take(root,1,n,id,r-1).second==r-id) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}