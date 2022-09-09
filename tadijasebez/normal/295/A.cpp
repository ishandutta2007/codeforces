#include <stdio.h>
#define ll long long
const int N=100050;
const int M=4*N;
int ls[M],rs[M],clock,root1,root2;
ll x[M];
void Set(int &c, int ss, int se, int qs, int qe, ll val)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){x[c]+=val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
ll A;
void Get(int c, int ss, int se, int qi)
{
	A+=x[c];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
ll Get(int c, int qi){A=0;Get(c,1,N,qi);return A;}
int b[N],e[N],d[N],a[N];
int main()
{
	int n,m,k,l,r,i;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++) scanf("%i %i %i",&b[i],&e[i],&d[i]);
	while(k--) scanf("%i %i",&l,&r),Set(root1,1,N,l,r,1);
	for(i=1;i<=m;i++) Set(root2,1,N,b[i],e[i],Get(root1,i)*d[i]);
	for(i=1;i<=n;i++) printf("%lld ",Get(root2,i)+a[i]);
	printf("\n");
	return 0;
}