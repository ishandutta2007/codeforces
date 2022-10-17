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
int n,k,a[100020],c;
int main()
{
	cin>>n>>k;
	if(k<0||k>n)
	{
		puts("-1");
		return 0;
	}
	fr(i,n)
		cin>>a[i];
	sort(a,a+n);
	a[n]=1e9;
	int w=a[n-k];
	for(int i=0;i<n;i++)
		if(a[i]==w)
			c++;
	if(c>1)
	{
		puts("-1");
		return 0;
	}
	printf("%d %d",w,w);
	return 0;	
}