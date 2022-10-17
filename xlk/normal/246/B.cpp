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
int n,x,s;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x),s+=x;
	printf("%d",n-(s%n!=0));
}