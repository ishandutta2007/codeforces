#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=i;
		int res=1;
		while(tmp<n&&a[tmp+1]==a[tmp])
		{
			tmp++;
			res++;
		}
		b[++cnt]=res;
		i=tmp;
	}
//	cout<<cnt<<endl;
//	for(int i=1;i<=cnt;i++)
//	{
//		printf("%d ",b[i]);
//	}
//	cout<<"\n";
	int ans=0;
	for(int i=1;i<cnt;i++)
	{
		ans=max(ans,min(b[i],b[i+1])*2);
	}
	cout<<ans<<endl;
	return 0;
}