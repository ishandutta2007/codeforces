#include <bits/stdc++.h>
#define MP make_pair 
using namespace std;

typedef long long LL;

int N;
int K[2];
int S[2][7010];
int v[2][7010];//1 win -1 lose 0 ??
int cnt[2][7010];
bool vis[2][7010];
queue<pair<int,int>>q;

int pre(int X,int step)
{
	X-=step;
	if (X<=0) X+=N;
	return X;
}

void print(int V)
{
	if (V==0) printf("Loop ");
	else if (V==1) printf("Win ");
	else printf("Lose ");
}

int main()
{
	scanf("%d",&N);
	for (int i=0;i<2;i++)
	{
		scanf("%d",&K[i]);
		for (int j=1;j<=K[i];j++)
			scanf("%d",&S[i][j]);
	}
	memset(v,0,sizeof(v));
	memset(vis,false,sizeof(vis));
	vis[0][1] = vis[1][1] = true; 
	v[0][1] = v[1][1] = -1;
	q.push(MP(0,1));
	q.push(MP(1,1));
	while(!q.empty())
	{
		int nowpl = q.front().first, nowpos = q.front().second, nowv = v[nowpl][nowpos];
		q.pop();
		int nextpl = nowpl^1, nextpos;
		for (int i=1;i<=K[nextpl];i++)
		{
			nextpos = pre(nowpos,S[nextpl][i]);
			if (vis[nextpl][nextpos]) continue;
			//printf("%d %d-->%d %d %d %d\n",nowpl,nowpos,nextpl,nextpos,S[nextpl][i],nowv);
			if (nowv==-1)
			{
				v[nextpl][nextpos] = 1;
				vis[nextpl][nextpos] = true;
				q.push(MP(nextpl,nextpos));
			}
			else if (nowv==1)
			{
				if (++cnt[nextpl][nextpos] == K[nextpl])
				{
					v[nextpl][nextpos] = -1;
					vis[nextpl][nextpos] = true;
					q.push(MP(nextpl,nextpos));
				}
			}
		}
	}
	
	for (int i=2;i<=N;i++)print(v[0][i]);
	puts("");
	for (int i=2;i<=N;i++)print(v[1][i]);
}