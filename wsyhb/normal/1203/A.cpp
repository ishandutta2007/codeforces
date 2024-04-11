#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=200+5;
int p[mx];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",p+i);
			p[i]--;
			if(p[i]==0) x=i;
		}
		bool f1=true,f2=true,f=true;
		for(int i=x;i!=x||f;i=(i+1)%n)
		{
			f=false;
			if((p[i]+1)%n!=p[(i+1)%n])
			{
				f1=false;
				break;
			}
		}
		f=true;
		for(int i=x;i!=x||f;i=(i-1+n)%n)
		{
			f=false;
			if((p[i]+1)%n!=p[(i-1+n)%n])
			{
				f2=false;
				break;
			}
		}
		if(f1||f2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}