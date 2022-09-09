#include <stdio.h>
const int N=200050;
const int M=2*N;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){ x[c]++;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
}
int A;
void Get(int c, int ss, int se, int qi)
{
	A+=x[c];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
int Get(int i){ A=0;Get(root,1,N,i);return A;}
int dp[N];
int main()
{
	int n,k,q,i,l,r;
	scanf("%i %i %i",&n,&k,&q);
	while(n--) scanf("%i %i",&l,&r),Set(root,1,N,l,r);
	for(i=1;i<N;i++) dp[i]=dp[i-1]+(Get(i)>=k);
	while(q--) scanf("%i %i",&l,&r),printf("%i\n",dp[r]-dp[l-1]);
	return 0;
}