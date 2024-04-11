#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int x,y;
	bool operator < (const Node &xx) const
	{
		if(x!=xx.x)
		{
			return x>xx.x;
		}
		return y>xx.y;
	}
	bool operator == (const Node &xx) const
	{
		if(x!=xx.x)
		{
			return false;
		}
		if(y!=xx.y)
		{
			return false;
		}
		return true;
	}
};
int gcd(int x,int y)
{
	if(y==0)
	{
		return x;
	}
	return gcd(y,x%y);
}
int a[200005];
int b[200005];
Node f[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	int ans=0,ok=0;
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&b[i]==0)
		{
			ok++;
			continue;
		}
		if(b[i]==0)
		{
			ans++;
			continue;
		}
		if(a[i]!=0)
		{
			int x=abs(a[i]);
			int y=abs(b[i]);
			int t=gcd(x,y);
//			printf("%d %d %d\n",x,y,t);
			a[i]/=t;
			b[i]/=t;
			if(a[i]<0)
			{
				a[i]*=-1;
				b[i]*=-1;
			}
			tmp++;
			f[tmp].x=a[i];
			f[tmp].y=b[i];
		}
	}
	sort(f+1,f+tmp+1);
//	for(int i=1;i<=tmp;i++)
//	{
//		printf("%d %d\n",f[i].x,f[i].y);
//	}
	int xx=0;
	for(int i=1;i<=tmp;i++)
	{
		xx=1;
		while(i<=tmp&&f[i]==f[i+1])
		{
			i++;
			xx++;
		}
		if(xx>ans)
		{
			ans=xx;
		}
	}
	cout<<ans+ok<<endl;
	return 0;
}