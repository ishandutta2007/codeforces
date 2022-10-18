#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	int tmp=1;
	int ans=1;
	for(int i=m-1;i>=1;i--)
	{
		if(a[i]*2>=a[i+1])
		{
//			cout<<"ADD ";
//			printf("%d %d ",a[i]*2,a[i+1]);
			tmp++;
		}
		else
		{
//			cout<<"MUL ";
			ans=max(ans,tmp);
			tmp=1;
		}
//		printf("%d %d\n",i,tmp);
	}
	cout<<max(tmp,ans)<<endl;
	return 0;
}