#include<bits/stdc++.h>
using namespace std;
#define N 1005
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
int a[N*2];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n*2+1);
	bool diff=true;
	for(int i=1;i<n*2;i++)
	{
		if(a[i]!=a[i+1]) diff=false;
	}
	if(diff)
	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<=n*2;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<"\n";
	return 0;
}