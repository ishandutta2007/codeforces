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
#define N 200005
int a[N];
void work()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int minn=1e10,beg=-1;
	for(int i=1;i+k<=n;i++)
	{
		if(a[i+k]-a[i]<minn)
		{
			minn=a[i+k]-a[i];beg=a[i];
		}
	}
	cout<<(beg+minn/2)<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}
//sacbknaf