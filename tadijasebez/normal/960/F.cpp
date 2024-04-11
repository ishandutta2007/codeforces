#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long int
const int N=100050;
const int M=20*N;
int x[M],ls[M],rs[M],tsz,root[N];
int max(int a, int b){ return a>b?a:b;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int sol;
int main()
{
	int n,m,i,u,v,w;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		int ans=Get(root[u],0,N,0,w-1);
		sol=max(sol,ans+1);
		Set(root[v],0,N,w,ans+1);
	}
	printf("%i\n",sol);
	return 0;
}