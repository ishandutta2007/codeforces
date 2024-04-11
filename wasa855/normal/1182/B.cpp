#include<bits/stdc++.h>
using namespace std;
int w,h;
char a[505][505];
int main()
{
	cin>>w>>h;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			cin>>a[i][j];
		}
	}
	bool found=false;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(a[i][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*')
			{
			//	printf("%d %d\n",i,j);
				a[i][j]='.';
				for(int k=i+1;k<=w;k++)
				{
					if(a[k][j]=='*')
					{
						a[k][j]='.';
					}
					else break;
				}
				for(int k=i-1;k>=1;k--)
				{
					if(a[k][j]=='*')
					{
						a[k][j]='.';
					}
					else break;
				}
				for(int k=j+1;k<=h;k++)
				{
					if(a[i][k]=='*')
					{
						a[i][k]='.';
					}
					else break;
				}
				for(int k=j-1;k>=1;k--)
				{
					if(a[i][k]=='*')
					{
						a[i][k]='.';
					}
					else break;
				}
				found=true; break;
			}
		}
		if(found) break;
	}
	if(!found)
	{
	    cout<<"NO\n";
	    return 0;
	}
//	cout<<endl;
//	for(int i=1;i<=w;i++)
//	{
//		for(int j=1;j<=h;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	}
	bool ok=true;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(a[i][j]=='*') 
			{
				ok=false;
			}
		}
	}
	if(ok) printf("YES");
	else printf("NO");
	return 0;
}