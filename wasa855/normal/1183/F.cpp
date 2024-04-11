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
bool used[N];
bool cmp(int x,int y)
{
	return x>y;
}
void work()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		used[a[i]]=true;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	int x;int j;
	for(j=2;j<=n;j++)
	{
		if(a[1]%a[j]!=0)
		{
			ans+=a[j];
			x=a[j];
			j++;
			break;
		}
	}
	for(;j<=n;j++)
	{
		if(a[1]%a[j]!=0&&x%a[j]!=0)
		{
			ans+=a[j];
			break;
		}
	}
	if(a[1]%2==0&&used[a[1]/2]==true&&a[1]%3==0&&used[a[1]/3]==true&&a[1]%5==0&&used[a[1]/5]==true)
	{
		ans=max(ans,a[1]/2+a[1]/3+a[1]/5);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		used[a[i]]=false;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}

//fesbhds