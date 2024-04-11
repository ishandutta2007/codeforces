#include <stdio.h>
#include <queue>
using namespace std;
#define ll long long
queue<int> q[31];
int stk[31];
const int N=200050;
const int inf=1e9+7;
int l[N],r[N],L[N],R[N],S[N],a[N],c;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	S[++c]=0;
	a[0]=inf;
	for(i=1;i<=n;i++) 
	{
		scanf("%i",&a[i]);
		while(a[i]>=a[S[c]])
		{
			R[S[c]]=i;
			c--;
		}
		L[i]=S[c];
		S[++c]=i;
	}
	while(c) R[S[c]]=n+1,c--;
	for(i=1;i<=n;i++) for(j=0;j<31;j++) if((a[i]>>j)&1) q[j].push(i);
	for(i=1;i<=n;i++)
	{
		r[i]=n+1;
		for(j=0;j<31;j++)
		{
			if((a[i]>>j)&1) q[j].pop();
			else
			{
				if(!q[j].empty()) r[i]=min(r[i],q[j].front());
			}
		}
		for(j=0;j<31;j++)
		{ 
			if((a[i]>>j)&1) stk[j]=i;
			else l[i]=max(l[i],stk[j]);
		}
	}
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		//printf("%i: %i %i %i %i\n",i,L[i],l[i],r[i],R[i]);
		if(l[i]>L[i])
		{
			sol+=(ll)(l[i]-L[i])*(R[i]-i);
			if(R[i]>r[i])
			{
				sol+=(ll)(R[i]-r[i])*(i-l[i]);
			}
		}
		else if(R[i]>r[i])
		{
			sol+=(ll)(R[i]-r[i])*(i-L[i]);
		}
	}
	printf("%lld\n",sol);
	return 0;
}