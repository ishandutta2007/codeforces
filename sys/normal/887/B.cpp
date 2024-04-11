#include <bits/stdc++.h>
using namespace std;
int ans[5],n,num[6][9],vis[6][13];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=6;j++)
		{
			scanf("%d",&num[i][j]);
			vis[i][num[i][j]]=true;
		}
	for(int i=1;i<=n;i++)
		sort(num[i]+1,num[i]+7);
	while(1)
	{
		ans[1]++;
		if(ans[1]==10) ans[2]++,ans[1]=0;
		if(ans[2]==10) ans[3]++,ans[2]=0;
		if(!ans[3]&&!ans[2])
			if(vis[1][ans[1]]||vis[2][ans[1]]||vis[3][ans[1]]) continue;
		if(!ans[3])
		{
			if(vis[1][ans[1]]&&vis[2][ans[2]]) continue;
			if(vis[1][ans[2]]&&vis[2][ans[1]]) continue;
			if(vis[1][ans[2]]&&vis[3][ans[1]]) continue;
			if(vis[1][ans[1]]&&vis[3][ans[2]]) continue;
			if(vis[3][ans[2]]&&vis[2][ans[1]]) continue;
			if(vis[3][ans[1]]&&vis[2][ans[2]]) continue;
		}
		if(vis[1][ans[1]]&&vis[2][ans[2]]&&vis[3][ans[3]]) continue;
		if(vis[1][ans[1]]&&vis[3][ans[2]]&&vis[2][ans[3]]) continue;
		if(vis[2][ans[1]]&&vis[1][ans[2]]&&vis[3][ans[3]]) continue;
		if(vis[2][ans[1]]&&vis[3][ans[2]]&&vis[1][ans[3]]) continue;
		if(vis[3][ans[1]]&&vis[1][ans[2]]&&vis[2][ans[3]]) continue;
		if(vis[3][ans[1]]&&vis[2][ans[2]]&&vis[1][ans[3]]) continue;
		int num=ans[3]*100+ans[2]*10+ans[1];
		printf("%d",num-1);
		return 0;
	}
}