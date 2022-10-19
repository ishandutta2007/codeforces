#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int ws(int x)
{
	int ans=0;
	while(x>=1)
	{
		ans++;
		x/=10;
	}
	return ans;
}
int solve(vector<int>v1,vector<int>v2)
{
	if(v1.empty()||v2.empty())return 0;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	//for(int i=0;i<v1.size();i++)printf("%d ",v1[i]);
//	printf("\n");
	//for(int i=0;i<v2.size();i++)printf("%d ",v2[i]);
	//printf("\n");
	int maxn=max(v1[v1.size()-1],v2[v2.size()-1]);
	if(maxn>=10)maxn=10;
	else maxn=2;
	int x1=0,x2=0;
	int ans=0;
	vector<int>n1,n2;
	n1.clear();
	n2.clear();
	while(x1<v1.size()&&x2<v2.size())
	{
		if(v1[x1]==v2[x2])
		{
			x1++;
			x2++;
			continue;
		}
		if(v1[x1]<v2[x2])
		{
			if(v1[x1]>=maxn)
			{
				n1.push_back(ws(v1[x1]));
				ans++;
			}
			else
			{
				n1.push_back(v1[x1]);
			}
			x1++;
		}
		else
		{
			if(v2[x2]>=maxn)
			{
				n2.push_back(ws(v2[x2]));
				ans++;
			}
			else
			{
				n2.push_back(v2[x2]);
			}
			x2++;
		}
	}
	while(x1<v1.size())
	{
		if(v1[x1]>=maxn)
		{
			n1.push_back(ws(v1[x1]));
			ans++;
		}
		else
		{
			n1.push_back(v1[x1]);
		}
		x1++;
	}
	while(x2<v2.size())
	{
		if(v2[x2]>=maxn)
		{
			n2.push_back(ws(v2[x2]));
			ans++;
		}
		else
		{
			n2.push_back(v2[x2]);
		}
		x2++;
	}
	return ans+solve(n1,n2);
}
vector<int>v1,v2;
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		v1.clear();
		v2.clear();
		for(int i=1;i<=n;i++)
		{
			x=read();
			v1.push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			x=read();
			v2.push_back(x);
		}
		printf("%d\n",solve(v1,v2));
	}
	return 0;
}