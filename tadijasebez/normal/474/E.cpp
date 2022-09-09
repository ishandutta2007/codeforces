#include <stdio.h>
#define ll long long
const int N=100050;
const int M=62*N;
const ll inf=(ll)1000000000*1000000000;
struct Node
{
	int val,ind;
	Node(){ val=0,ind=0;}
	Node(int a, int b){ val=a,ind=b;}
	inline Node operator + (const Node &b) const
	{
		Node c;
		if(val<b.val) c=b;
		else c=*this;
		return c;
	}
} x[M];
int ls[M],rs[M],clock,root;
void Set(int &c, ll ss, ll se, ll qi, Node val)
{
	if(!c) c=++clock;
	x[c]=x[c]+val;
	if(ss==se) return;
	ll mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
Node Get(int c, ll ss, ll se, ll qs, ll qe)
{
	if(ss>qe || qs>se) return Node();
	if(qs<=ss && qe>=se) return x[c];
	ll mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int dp[N],par[N],best;
void Print(int i)
{
	if(par[i]) Print(par[i]);
	printf("%i ",i);
}
int main()
{
	int n,d,i;ll x;
	scanf("%i %i",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		Node tmp=Get(root,-inf,inf,-inf,x-d)+Get(root,-inf,inf,x+d,inf);
		dp[i]=tmp.val+1;
		par[i]=tmp.ind;
		if(dp[i]>dp[best]) best=i;
		Set(root,-inf,inf,x,Node(dp[i],i));
	}
	printf("%i\n",dp[best]);
	Print(best);
	printf("\n");
	return 0;
}