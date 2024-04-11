#include<bits/stdc++.h>
using namespace std;
int a[5];
int ans[7];
bool used[7];
int mp[7]={0,4,8,15,16,23,42};
bool judge()
{
	if(mp[ans[1]]*mp[ans[2]]!=a[1]) return false;
	if(mp[ans[1]]*mp[ans[3]]!=a[2]) return false;
	if(mp[ans[4]]*mp[ans[5]]!=a[3]) return false;
	if(mp[ans[4]]*mp[ans[6]]!=a[4]) return false;
	return true;
}
void dfs(int dep)
{
	if(dep==7)
	{
		if(judge())
		{
			printf("! ");
			for(int i=1;i<=6;i++)
			{
				printf("%d ",mp[ans[i]]);
			}
			fflush(stdout);
			exit(0);
		}
	}
	for(int i=1;i<=6;i++)
	{
		if(used[i]==false)
		{
			used[i]=true;
			ans[dep]=i;
			dfs(dep+1);
			used[i]=false;
		}
	}
}
int main()
{
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&a[1]);
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d",&a[2]);
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d",&a[3]);
	printf("? 4 6\n");
	fflush(stdout);
	scanf("%d",&a[4]);
	dfs(1);
	return 0;
}