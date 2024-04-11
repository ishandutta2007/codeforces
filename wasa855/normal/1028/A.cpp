#include<bits/stdc++.h>
using namespace std;
char a[120][120];
int main()
{
	int m,n;
	cin>>n>>m;
	scanf("\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
	}
	int b,c,d,e;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='B')
			{
				b=i;
				while(a[i][j]=='B')
				{
					i++;
				}
				i--;
				c=i;
				d=j;
				while(a[i][j]=='B')
				{
					j++;
				}
				e=j-1;
				break;
			}
		}
	}
	printf("%d %d\n",(b+c)/2,(d+e)/2);
	return 0;
}
///////////////////////////////