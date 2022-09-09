#include <stdio.h>
#include <algorithm>
#define ll long long
const int N=200050;
const int M=4*N;
int t[N];
bool comp(int i, int j)
{
	if(i>j) return !comp(j,i);
	if(t[i]==0 && t[j]==0) return true;
	if(t[i]==1 && t[j]==0) return false;
	if(t[i]==0 && t[j]==1) return false;
	return false;
}
int y[N];
int x[M],ls[M],rs[M],clock,root1,root2;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
ll sol;
int main()
{
	int i,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&t[i]);
		y[i]=i;
		if(t[i]==1) Set(root2,1,N,i,1);
		else Set(root1,1,N,i,1);
	}
	std::sort(y+1,y+1+n,comp);
	for(i=1;i<=n;i++)
	{
		//printf("%i ",y[i]);
		if(t[y[i]]==1) sol+=Get(root1,1,N,y[i]+1,N),Set(root2,1,N,y[i],-1);
		else sol+=Get(root2,1,N,1,y[i]-1),Set(root1,1,N,y[i],-1);
	}
	printf("%lld\n",sol);
	return 0;
}