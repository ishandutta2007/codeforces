#include <bits/stdc++.h>
using namespace std;
const int N=2050;
char base[N][N];
int a[N][N],n,go[N][N];
bool comp(int x, int y, int i, int j)
{
    while(1)
	{
		//printf("%i %i %i %i\n",x,y,i,j);
		char nxt1='z'+1;
		if(go[x][y]) nxt1=base[go[x][y]/N][go[x][y]%N];
		//if(x<n) nxt1=min(nxt1,base[x+1][y]);
		//if(y<n) nxt1=min(nxt1,base[x][y+1]);
		char nxt2='z'+1;
		if(go[i][j]) nxt2=base[go[i][j]/N][go[i][j]%N];
		//if(i<n) nxt2=min(nxt2,base[i+1][j]);
		//if(j<n) nxt2=min(nxt2,base[i][j+1]);
		if(nxt1=='z'+1 || nxt2=='z'+1) return 0;
        if(nxt1==nxt2)
		{
			int X=go[x][y]/N,Y=go[x][y]%N;
			x=X;y=Y;
			X=go[i][j]/N,Y=go[i][j]%N;
			i=X,j=Y;
			continue;
		}
        if(nxt1<nxt2) return 1;
        if(nxt2<nxt1) return 0;
	}
}
queue<int> q[2][26];
bool Qsz(int t)
{
	for(int i=0;i<26;i++) if(q[t][i].size()) return 1;
	return 0;
}
int main()
{
	int k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%s",base[i]+1);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=max(a[i-1][j],a[i][j-1])+(base[i][j]=='a');
	q[0][base[n][n]-'a'].push(n*N+n);
	int t=0;
	while(Qsz(0) || Qsz(1))
	{
		int x,y;
		if(!Qsz(t)) t^=1;
		for(i=0;i<26;i++)
		{
			if(q[t][i].size())
			{
				x=q[t][i].front()/N;
				//printf(":D\n");
				y=q[t][i].front()%N;
				q[t][i].pop();
				break;
			}
		}
		//printf("%i %i\n",x,y);
		if(x>1 && !go[x-1][y])
		{
			q[t^1][base[x-1][y]-'a'].push((x-1)*N+y);
			go[x-1][y]=x*N+y;
		}
		//else if(x>1 && go[x-1][y])
		//{
		//	if(base[go[x-1][y]/N][go[x-1][y]%N]>base[x][y]) go[x-1][y]=x*N+y;
		//}
		if(y>1 && !go[x][y-1])
		{
			q[t^1][base[x][y-1]-'a'].push(x*N+y-1);
			go[x][y-1]=x*N+y;
		}
		//else if(y>1 && go[x][y-1])
		//{
		//	if(base[go[x][y-1]/N][go[x][y-1]%N]>base[x][y]) go[x][y-1]=x*N+y;
		//}
	}
	int mx=0;
	vector<int> work;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++)
	{
		int dist=i+j-1;
		if(dist-a[i][j]<=k) mx=max(mx,dist);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++)
	{
		int dist=i+j-1;
		if(dist-a[i][j]<=k && dist==mx) work.push_back(i*N+j);
	}
	if(!work.size())
	{
		int x=1,y=1;
		printf("%c",base[x][y]);
		while(go[x][y])
		{
			char nxt1=base[go[x][y]/N][go[x][y]%N];
			printf("%c",nxt1);
			int X=go[x][y]/N,Y=go[x][y]%N;
			x=X;y=Y;
		}
		return 0;
	}
	int x=work[0]/N,y=work[0]%N;
	for(i=1;i<work.size();i++)
	{
        int X=work[i]/N;
        int Y=work[i]%N;
        if(comp(X,Y,x,y)) x=X,y=Y;
	}
	for(i=1;i<x+y;i++) printf("a");
	while(go[x][y])
	{
		char nxt1=base[go[x][y]/N][go[x][y]%N];
		printf("%c",nxt1);
		int X=go[x][y]/N,Y=go[x][y]%N;
		x=X;y=Y;
	}
	return 0;
}