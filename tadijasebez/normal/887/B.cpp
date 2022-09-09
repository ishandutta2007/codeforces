#include <stdio.h>
#include <set>
using namespace std;
set<int> Set;
int a[3][6];
int main()
{
	int n,i,j,k,l;
	scanf("%i",&n);
	for(i=0;i<n;i++) for(j=0;j<6;j++) scanf("%i",&a[i][j]);
	if(n==1)
	{
		for(i=0;i<6;i++) Set.insert(a[0][i]);
	}
	if(n==2)
	{
		for(i=0;i<6;i++) Set.insert(a[0][i]);
		for(i=0;i<6;i++) Set.insert(a[1][i]);
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[0][i]!=0) Set.insert(a[0][i]*10+a[1][j]);
				if(a[1][j]!=0) Set.insert(a[1][j]*10+a[0][i]);
			}
		}
	}
	if(n==3)
	{
		for(i=0;i<6;i++) Set.insert(a[0][i]);
		for(i=0;i<6;i++) Set.insert(a[1][i]);
		for(i=0;i<6;i++) Set.insert(a[2][i]);
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[0][i]!=0) Set.insert(a[0][i]*10+a[1][j]);
				if(a[1][j]!=0) Set.insert(a[1][j]*10+a[0][i]);
			}
		}
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[0][i]!=0) Set.insert(a[0][i]*10+a[2][j]);
				if(a[2][j]!=0) Set.insert(a[2][j]*10+a[0][i]);
			}
		}
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[2][i]!=0) Set.insert(a[2][i]*10+a[1][j]);
				if(a[1][j]!=0) Set.insert(a[1][j]*10+a[2][i]);
			}
		}
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				for(k=0;k<6;k++)
				{
					if(a[0][i]!=0){
						Set.insert(a[0][i]*100+a[1][j]*10+a[2][k]);
						Set.insert(a[0][i]*100+a[2][k]*10+a[1][j]);
					}
					if(a[1][j]!=0){
						Set.insert(a[1][j]*100+a[0][i]*10+a[2][k]);
						Set.insert(a[1][j]*100+a[2][k]*10+a[0][i]);
					}
					if(a[2][k]!=0){
						Set.insert(a[2][k]*100+a[0][i]*10+a[1][j]);
						Set.insert(a[2][k]*100+a[1][j]*10+a[0][i]);
					}
				}
			}
		}
	}
	int sol=0;
	for(i=1;i<1000;i++)
	{
		if(Set.count(i)) sol=i;
		else break;
	}
	printf("%i\n",sol);
	return 0;
}