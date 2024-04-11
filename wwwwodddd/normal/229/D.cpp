#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int h[5020];
int F[5020][5020];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		h[i]+=h[i-1];
	}
	for(int i=1;i<=n;i++)
	F[i][1]=i-1;
	for (int i=2;i<=n;i++)
	{
		int k=1;
		for (int j=2;j<=i;j++)
		{
			while (k<j)
			{
				if(h[i]-h[j-1]>=h[j-1]-h[k-1])
					break;
				k++;
			}
			if (k==j)
			{
				for (int _j=j;_j<=i;++_j)
					F[i][_j]=0x3f3f3f3f;
				break;
			}
			F[i][j]=F[j-1][k]+i-j;
		}
		for (int j=i-1;j>=1;--j)
			F[i][j]=min(F[i][j],F[i][j+1]);
	}
	int ans=0x3f3f3f3f;
	for (int j=1;j<=n;++j)
		ans=min(ans,F[n][j]);
	cout<<ans<<endl;
}