#include <bits/stdc++.h>
using namespace std;
map <int,bool> toes[200005];
int cc,n,cnt[200005],ord[200005];
int bfs(int x)
{
	queue <int> Qu;
	Qu.push(1);
	while(!Qu.empty())
	{
		int now=Qu.front();
		Qu.pop();
		int res=cnt[now];
		for(int i=cc;i<cc+res;i++)
		{
			if(toes[now].find(ord[i])==toes[now].end()) return -1;
		 	Qu.push(ord[i]);
		 	cnt[now]--,cnt[ord[i]]--;
		}
		cc+=res;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a]++,cnt[b]++;
		toes[a][b]=true;
		toes[b][a]=true;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&ord[i]);
	cc=2;
	if(ord[1]!=1){printf("No");return 0;}
	if(bfs(1)==-1){printf("No");return 0;} 
	else printf("Yes");
	return 0;
}