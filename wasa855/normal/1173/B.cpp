#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	cout<<n/2+1<<endl;
	int ans=n/2+1;
	for(int i=1;i<=ans;i++)
	{
		printf("%d %d\n",1,i);
	}
	for(int i=ans+1;i<=n;i++)
	{
		printf("%d %d\n",i+1-ans,ans);
	}
	return 0;
}
//saiufchsaufdas