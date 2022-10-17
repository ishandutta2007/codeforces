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
int v[1000020];
int a[1000020];
int A,B,K,n,z;
int ok(int l)
{
	for(int i=A;i<=B-l+1;i++)
		if(a[i+l-1]-a[i-1]<K)
			return 0;
	return 1;
}
int main()
{
	cin>>A>>B>>K;
	n=1000010;
	for(int i=2;i<=n;i++)
		if(!v[i])
			for(int j=i;j<=n;j+=i)
				v[j]=i;
	for(int i=2;i<=n;i++)
		a[i]=v[i]==i;
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	if(a[B]-a[A-1]<K)
		return puts("-1"),0;
	int l=0,r=n;
	ok(2);
	while(l<r-1)
	{
		int m=l+r>>1;
		if(ok(m))
			r=m;
		else
			l=m;
	}
	if(a[B]-a[A-1]<K)
		puts("-1");
	else
		printf("%d",r);
	return 0;
}