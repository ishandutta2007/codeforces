#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
const int M=30*N;
const int T=1e9;
#define ll long long
ll x[M];
int ls[M],rs[M],clock,root;
ll max(ll a, ll b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void Set(int &c, int ss, int se, int qi, ll val)
{
	if(!c) c=++clock;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
struct Ring
{
	int l,r,h;
	Ring(){}
	Ring(int a, int b, int c){ l=a,r=b,h=c;}
	inline bool operator < (const Ring &b) const
	{
		return r<b.r || (r==b.r && l>b.l);
	}
} A[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&A[i].l,&A[i].r,&A[i].h);
		A[i].l++;
	}
	sort(A+1,A+1+n);
	int c=0;
	for(i=1;i<=n;i++)
	{
		if(A[i].r==A[c].r) A[c].l=min(A[c].l,A[i].l),A[c].h+=A[i].h;
		else A[++c]=A[i];
	}
	for(i=1;i<=c;i++)
	{
		ll tmp=Get(root,1,T,A[i].l,A[i].r)+A[i].h;
		Set(root,1,T,A[i].r,tmp);
	}
	printf("%lld\n",x[root]);
	return 0;
}