#include<bits/stdc++.h>
using namespace std;
int a[6][6],i,j;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
		{
			cin>>a[i][j];
			if(a[i][j]) cout<<abs(i-3)+abs(j-3);
		}		
	return 0;
}