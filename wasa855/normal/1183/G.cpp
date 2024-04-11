#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int c1[N],c2[N];
int a[N];
bool cmp(int x,int y)
{
	return c1[x]+c2[x]>c1[y]+c2[y];
}
void work()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		c1[i]=c2[i]=0;
	}
	int x,y;
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read();
		if(y==1) c2[x]++;
		else c1[x]++;
		a[i]=i;
	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++)
//	{
//		printf("%lld %lld\n",c1[a[i]],c2[a[i]]);
//	}
	sort(a+1,a+n+1,cmp);
//	cout<<'\n';
//	for(int i=1;i<=n;i++)
//	{
//		printf("%lld %lld\n",c1[a[i]],c2[a[i]]);
//	}
	priority_queue<int> q;
	int cur=1;
	int ans=0,sum=0;
	for(int i=n;i>=1;i--)
	{
		while(c1[a[cur]]+c2[a[cur]]>=i&&cur<=n)
		{
			q.push(c2[a[cur]]);
			cur++;
		}
		if(q.empty()) continue;
		int x=q.top();
		q.pop();
		ans+=i;
		sum+=min(i,x);
	}
	printf("%lld %lld\n",ans,sum);
}
signed main()
{
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}