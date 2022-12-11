#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
char s[mx],t[mx];
int f1[mx],f2[mx];
int main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1),l,r,ans=-1;
	bool f=true;
	for(int i=1,j=1;i<=n;i++)
		if(s[i]==t[j])
		{
			if(f) l=i,f=false;
			if(j==m)
			{
				r=i;
				break;
			}
			j++;
		}
	ans=max(l-1,n-r);
	f=true;
	for(int i=n,j=m;i>=1;i--)
		if(s[i]==t[j])
		{
			if(f) r=i,f=false;
			if(j==1)
			{
				l=i;
				break;
			}
			j--;
		}
	ans=max(ans,max(l-1,n-r));
	for(int i=1,j=1;i<=n;i++)
		if(s[i]==t[j])
		{
			f1[j++]=i;
			if(j>m) break;
		}
	for(int i=n,j=m;i>=1;i--)
		if(s[i]==t[j])
		{
			f2[j--]=i;
			if(j<1) break;
		}
	for(int i=0;i<=m;i++)
		ans=max(ans,f2[i+1]-f1[i]-1);
	printf("%d",ans);
	return 0;
}