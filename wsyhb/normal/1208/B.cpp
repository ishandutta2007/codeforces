#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=2e3+5;
int a[mx];
map<int,int> M;
int main()
{
	int n,cnt=0,ans=2005;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		M[a[i]]++;
		if(M[a[i]]==2) cnt++;
	}
	if(!cnt)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool f=true;
		for(int j=i;j<=n;j++)
		{
			M[a[j]]--;
			if(M[a[j]]==1) cnt--;
			if(!cnt)
			{
				ans=min(ans,j-i+1);
				for(int k=i;k<=j;k++)
				{
					M[a[k]]++;
					if(M[a[k]]==2) cnt++;
				}
				f=false;
				break;
			}
		}
		if(f)
			for(int j=i;j<=n;j++)
			{
				M[a[j]]++;
				if(M[a[j]]==2) cnt++;
			}
	}
	printf("%d",ans);
	return 0;
}