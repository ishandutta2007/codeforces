#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
const int inf=1e9+7;
const ll oo=9e18;
const int M=2*N;
int ls[M],rs[M],tsz,root;
int lzy[M],val[M],a[N];
void push(int c)
{
	lzy[ls[c]]=max(lzy[ls[c]],lzy[c]);
	lzy[rs[c]]=max(lzy[rs[c]],lzy[c]);
	lzy[c]=0;
}
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=0;
	if(ss==se){ val[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qi, int x)
{
	if(ss==se){ val[c]=x;lzy[c]=0;return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
}
void Max(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]=max(lzy[c],x);return;}
	push(c);
	int mid=ss+se>>1;
	Max(ls[c],ss,mid,qs,qe,x);
	Max(rs[c],mid+1,se,qs,qe,x);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se)
	{
		val[c]=max(lzy[c],val[c]);
		lzy[c]=0;
		return val[c];
	}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid) return Get(ls[c],ss,mid,qi);
	else return Get(rs[c],mid+1,se,qi);
}
int main()
{
	int n,q;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		int t,l,x;
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&l,&x);
			Set(root,1,n,l,x);
		}
		else
		{
			scanf("%i",&x);
			Max(root,1,n,1,n,x);
		}
	}
	for(int i=1;i<=n;i++) printf("%i ",Get(root,1,n,i));
	return 0;
}