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
bool cmp(int x,int y)
{
	return x>y;
}
void work()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=n;i++) a[read()]++;
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	cout<<"\n";
	for(int i=2;i<=n;i++)
	{
		a[i]=min(a[i],a[i-1]-1);
		if(a[i]==0) break;
		ans+=a[i];
	}
	cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}