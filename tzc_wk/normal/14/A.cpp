#include <bits/stdc++.h>
using namespace std;
int n,m;
char w[53][53];
int main()
{
	int side[4]={53,0,53,0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>w[i][j];
			if(w[i][j]=='*')
			{
				if(side[0]>i)	side[0]=i;
				if(side[1]<i)	side[1]=i;
				if(side[2]>j)	side[2]=j;
				if(side[3]<j)	side[3]=j;
			}	
		}
	}
	for(int i=side[0];i<=side[1];i++)
	{
		for(int j=side[2];j<=side[3];j++)
		{
			cout<<w[i][j];
		}
		cout<<endl;
	}
	return 0;
}