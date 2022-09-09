#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
const int N=5005;
const int M=2*N;
int dp[N][N],sol[N][N];
int a[N];
int ls[M],rs[M],rmq[M],tsz,root;
void init(){ for(int i=1;i<=tsz;i++) ls[i]=rs[i]=rmq[i]=0;tsz=0;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	ckmax(rmq[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return rmq[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main()
{
	int n,i,j,q,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i][1]=a[i];
	for(j=2;j<=n;j++)
	{
		for(i=1;i<=n-j+1;i++) dp[i][j]=dp[i][j-1]^dp[i+1][j-1];
	}
	for(i=n;i>=1;i--)
	{
		init();
		int sz=n-i+1;
		for(j=1;j<=n-i+1;j++)
		{
			//Set(root,1,sz,j,dp[i][j]);
		}
		for(j=1;j<=n-i+1;j++)
		{
			sol[i][j]=max(sol[i+1][j-1],sol[i][j-1]);
			ckmax(sol[i][j],dp[i][j]);
			//printf("%i ",sol[i][j]);
		}
		//printf("\n");
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		printf("%i\n",sol[l][r-l+1]);
	}
	return 0;
}