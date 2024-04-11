#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define ll long long
const int N=100050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
int x[M],id[M],ls[M],rs[M],clock,root,a[N];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=a[ss];
		id[c]=ss;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=max(x[ls[c]],x[rs[c]]);
	if(x[c]==x[rs[c]]) id[c]=id[rs[c]];
	else id[c]=id[ls[c]];
}
pair<int,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return mp(0,0);
	if(qs<=ss && qe>=se) return mp(x[c],id[c]);
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
ll dp[N],sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	for(i=n-1;i;i--)
	{
		int id=Get(root,1,n,i+1,a[i]).second;
		int num=n-a[i];
		dp[i]+=dp[id]+num;
		dp[i]+=id-i;
		sol+=dp[i];
		//printf("%i %lld %i\n",i,dp[i],id);
	}
	printf("%lld\n",sol);
	return 0;
}