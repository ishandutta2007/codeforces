#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int f[100020];
long long d[100020];
int n,k,x,y;
long long ans;
int F(int x)
{
	if(f[x]==x)
		return x;
	int fx=F(f[x]);
	d[x]=d[f[x]]+d[x];
	return f[x]=fx;
}
int main()
{
	scanf("%d",&n);
	fo(i,n)
		f[i]=i;
	fo(i,n)
	{
		scanf("%d",&k);
		fo(j,k)
		{
			scanf("%d %d",&x,&y);
			int fx=F(x);
//			cout << "FVCK  " << d[x]+y << endl;
			ans=(ans+d[x]+y)%1000000007;
			d[fx]=(d[x]+y)%1000000007;
			f[fx]=i;
		}
	}
	printf("%d",(int)(ans+1000000007)%1000000007);
	return 0;
}