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
int n,x;
int f[100020];
int p[100020];
int w[100020];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=100000;i++)
		if(!p[i])
			for(int j=i;j<=100000;j+=i)
				p[j]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int w=0;
		for(int i=x;i!=1;i/=p[i])
			w=max(w,f[p[i]]);
		w++;
		for(int i=x;i!=1;i/=p[i])
			f[p[i]]=max(f[p[i]],w);
	}
	int w=1;
	for(int i=0;i<=100000;i++)
		w=max(w,f[i]);
	printf("%d\n",w);
}