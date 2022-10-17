#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int b[2000020];
int a[1000020],n;
int z;
set<int>s,t;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		t.clear();
		fe(j,s)
			t.insert(*j|a[i]);
		t.insert(a[i]);
		s=t;
		fe(j,s)
			b[*j]=1;
	}
	for(int i=0;i<1<<20;i++)
		z+=b[i];
	printf("%d",z);
}