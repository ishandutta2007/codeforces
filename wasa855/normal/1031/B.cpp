#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int t[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<=3;i++)
	{
		t[1]=i;
		bool ok=true;
		for(int j=2;j<=n;j++)
		{
			bool can=false;
			for(int k=0;k<=3;k++)
			{
				if((a[j-1]==(t[j-1]|k))&&(b[j-1]==(t[j-1]&k)))
				{
//					printf("%d %d %d %d\n",t[j-1],a[j-1],k,t[j-1]|k);
//					printf("%d %d %d %d\n",t[j-1],b[j-1],k,t[j-1]&k);
					t[j]=k;
					can=true;
					break;
				}
			}
			if(can==false)
			{
				ok=false;
				break;
			}
		}
		if(ok==true)
		{
			cout<<"YES\n";
			for(int j=1;j<=n;j++)
			{
				printf("%d ",t[j]);
			}
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}