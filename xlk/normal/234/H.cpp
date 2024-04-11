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
int n,m,c,sa,sb;
int a[100020],ac;
int b[100020],bc;
int z[200020];
int w[200020];
int dir;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=1;i<n;i++)
		if(a[i]^a[i-1])
			ac++;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",b+i);
	for(int i=1;i<m;i++)
		if(b[i]^b[i-1])
			bc++;
	if(ac>bc)
		dir=a[0];
	else
		dir=b[0];
	while(sa<n||sb<m)
	{
		int i;
		for(i=sa;i<n;i++)
			if(a[i]==dir)
				z[c++]=i;
			else
				break;
		sa=i;
		for(i=sb;i<m;i++)
			if(b[i]==dir)
				z[c++]=n+i;
			else
				break;
		sb=i;
		dir^=1;
	}
	for(int i=0;i<c;i++)
	{
		if(z[i]<n)
			w[i]=a[z[i]];
		else
			w[i]=b[z[i]-n];
	}
	for(int i=0;i<c;i++)
		printf("%d ",z[i]+1);
	puts("");
	int ans=0;
	for(int i=0;i<c;i++)
		if(w[i]^w[i+1])
			ans++;
	printf("%d\n",ans);
	for(int i=0;i<c;i++)
		if(w[i]^w[i+1])
			printf("%d ",i+1);
	return 0;
}