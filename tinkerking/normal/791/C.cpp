#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
int v[51];
bool vis[110];

int dif(int pos)
{
	memset(vis,false,sizeof(vis));
	for (int i=pos-K+1;i<pos;i++)vis[v[i]] = true;
	for (int i=1;i<=100;i++)if (!vis[i]) return i;
}

void make(int V)
{
	printf("%c%c ",'A'+V/26,'a'+V%26);
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<K;i++)v[i] = i;
	for (int i=K;i<=N;i++)
	{
		char s[5];
		scanf("%s",s);
		if (s[0]=='Y')
			v[i] = dif(i);
		else
			v[i] = v[i-K+1];
	}
	for (int i=1;i<=N;i++)make(v[i]);
}