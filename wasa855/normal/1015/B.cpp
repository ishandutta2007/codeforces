#include<bits/stdc++.h>
using namespace std;
string a,b;
int m;
int sum[30];
int limit;
int ans[100005];
void dfs(int dep,string now)
{
	if(now==b)
	{
		cout<<dep-1<<"\n";
		for(int i=1;i<dep;i++)
		{
			printf("%d ",ans[i]);
		}
		exit(0);
	}
	if(dep==limit)
	{
		return ;
	}
	for(int i=0;i<m-1;i++)
	{
		swap(now[i],now[i+1]);
		ans[dep]=i+1;
		dfs(dep+1,now);
		swap(now[i],now[i+1]);
	}
}
int main()
{
	cin>>m;
	cin>>a>>b;
	for(int i=0;i<m;i++)
	{
		sum[a[i]-'a']++;
	}
	for(int i=0;i<m;i++)
	{
		sum[b[i]-'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(sum[i]!=0)
		{
			cout<<"-1\n";
			return 0;
		}
	}
//	cout<<"ZHI\n";
	int s=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]!=b[i])
		{
			int j=i;
			for(;;j++)
			{
				if(a[j]==b[i])
				{
					break;
				}
			}
			for(int k=j-1;k>=i;k--)
			{
				ans[++s]=k+1;
				swap(a[k],a[k+1]);
			}
		}
	}
	cout<<s<<endl;
	for(int i=1;i<=s;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}