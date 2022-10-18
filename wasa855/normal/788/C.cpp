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
#define N 1005
int a[N*N];
bool h[N];
map<int,int> f;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		h[a[i]]=true;
	}
	n=0;
	for(int i=0;i<=1000;i++)
	{
		if(h[i]==true) a[++n]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]-=k;
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	cout<<"\n";
	queue<int> q;
	q.push(0);
	f[0]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			int x=t+a[i];
			if(x<-2000||x>2000) continue;
			if(f[x]==0)
			{
				f[x]=f[t]+1;
				q.push(x);
			}
			if(x==0)
			{
				cout<<f[x]<<endl;
				return 0;
			}
		}
	}
	cout<<"-1\n";
	return 0;
}