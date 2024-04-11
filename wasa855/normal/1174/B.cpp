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
#define N 100005
int a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	bool diff=true;
	for(int i=1;i<n;i++)
	{
		if(a[i]%2!=a[i+1]%2) diff=false;
	}
	if(diff==true)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		cout<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<"\n";
	return 0;
}