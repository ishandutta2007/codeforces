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
int n;
int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
		printf("%d ",n-i);
}