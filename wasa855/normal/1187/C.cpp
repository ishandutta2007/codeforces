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
struct Node
{
	int t;
	int l,r;
};
Node a[N];
int t[N];
bool cmp(Node a,Node b)
{
	return a.t>b.t;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		a[i].t=read(),a[i].l=read(),a[i].r=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(a[i].t==1)
		{
			for(int j=a[i].l;j<a[i].r;j++)
			{
				t[j]=1;
			}
		}
		else
		{
			bool des=false,ok=false;
			for(int j=a[i].l;j<a[i].r;j++)
			{
				if(t[j]!=1)
				{
					ok=true;
				}
				if(t[j]==-1) des=true;
			}
			if(des==true) continue;
			if(ok==false)
			{
				cout<<"NO\n";
				return 0;
			}
			for(int j=a[i].l;j<a[i].r;j++)
			{
				if(t[j]==0)
				{
					t[j]=-1;
					break;
				}
			}
		}
	}
	cout<<"YES\n";
	int x=2005;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",x);
		x+=t[i];
	}
	return 0;
}