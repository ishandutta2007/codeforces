#include<bits/stdc++.h>
using namespace std;
queue<int> v1[30];
queue<int> v2[30];
struct Node
{
	int x;
	int y;
};
int ans=0;
Node res[150005];
void print(int x,int y)
{
	ans++;
	res[ans].x=x;
	res[ans].y=y;
}
int main()
{
	int n;
	cin>>n;
	char xx;
	for(int i=1;i<=n;i++)
	{
		cin>>xx;
		if(xx=='?')
		{
			v1[27].push(i);
		}
		else
		{
			v1[xx-'a'+1].push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>xx;
		if(xx=='?')
		{
			v2[27].push(i);
		}
		else
		{
			v2[xx-'a'+1].push(i);
		}
	}
	for(int i=1;i<=26;i++)
	{
//		printf("%d %d %d\n",i,v1[i].size(),v2[i].size());
		while(v1[i].size()!=0&&v2[i].size()!=0)
		{
			print(v1[i].front(),v2[i].front());
			v1[i].pop();
			v2[i].pop();
		}
	}
	int x=v1[27].size();
	for(int i=1;i<=26;i++)
	{
		if(x==0)
		{
			break;
		}
		while(v2[i].size()!=0)
		{
			print(v1[27].front(),v2[i].front());
			v1[27].pop();
			v2[i].pop();
			x--;
			if(x==0)
			{
				break;
			}
		}
	}
	x=v2[27].size();
	for(int i=1;i<=26;i++)
	{
		if(x==0)
		{
			break;
		}
		while(v1[i].size()!=0)
		{
			print(v1[i].front(),v2[27].front());
			v1[i].pop();
			v2[27].pop();
			x--;
			if(x==0)
			{
				break;
			}
		}
	}
	while(v1[27].size()!=0&&v2[27].size()!=0)
	{
		print(v1[27].front(),v2[27].front());
		v1[27].pop();
		v2[27].pop();
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		printf("%d %d\n",res[i].x,res[i].y);
	}
	return 0;
}