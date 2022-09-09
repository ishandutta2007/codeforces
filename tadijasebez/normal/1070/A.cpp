#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int K=505;
const int N=5005;
pair<int,int> par[K][N];
bool was[K][N];
int main()
{
	int d,s,i;
	scanf("%i %i",&d,&s);
	queue<int> q;
	for(i=1;i<=min(9,s);i++)
	{
		q.push((i%d)*N+i);
		was[i%d][i]=1;
	}
	while(q.size())
	{
		int x=q.front()/N;
		int y=q.front()%N;
		q.pop();
		for(i=0;i<=9;i++)
		{
			int X=(x*10+i)%d;
			int Y=y+i;
			if(Y>s) continue;
			if(!was[X][Y]) q.push(X*N+Y),was[X][Y]=1,par[X][Y]=mp(x,y);
		}
	}
	if(!was[0][s]) printf("-1\n");
	else
	{
		vector<int> ans;
		int x=0,y=s;
		while(y)
		{
			int X=par[x][y].first;
			int Y=par[x][y].second;
			ans.push_back(y-Y);
			x=X;y=Y;
		}
		reverse(ans.begin(),ans.end());
		for(i:ans) printf("%i",i);
		printf("\n");
	}
	return 0;
}