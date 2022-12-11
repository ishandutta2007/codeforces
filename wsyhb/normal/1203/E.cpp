#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=15e4+5;
bool M[mx];
int a[mx];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1&&!M[a[i]-1]) M[a[i]-1]=true;
		else if(!M[a[i]]) M[a[i]]=true;
		else if(!M[a[i]+1]) M[a[i]+1]=true;
	}
	for(int i=1;i<=150001;i++)
		if(M[i]) ans++;
	printf("%d",ans);
	return 0;
}