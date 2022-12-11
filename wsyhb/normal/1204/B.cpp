#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int a[25],s[25];
int main()
{
	a[1]=1;
	for(int i=2;i<=20;i++) a[i]=a[i-1]*2;
	for(int i=1;i<=20;i++) s[i]=s[i-1]+a[i];
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	printf("%d %d\n",s[l]+n-l,s[r]+(n-r)*a[r]);
	return 0;
}