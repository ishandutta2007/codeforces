#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
const int N=105;
vector<int> E[N];
int in[N],id[N],cnt,sol[N];
bool vis[N];
string s[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,k,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		cin >> s[i];
		if(i>1)
		{
			k=min(s[i].size(),s[i-1].size());
			for(j=0;j<k;j++)
			{
				if(s[i][j]!=s[i-1][j]) break;
			}
			if(j==k)
			{
				if(s[i-1].size()>s[i].size()) return printf("Impossible\n"),0;
			}
			else
			{
				E[s[i-1][j]-'a'+1].push_back(s[i][j]-'a'+1);
				in[s[i][j]-'a'+1]++;
			}
		}
	}
	queue<int> q;
	for(i=1;i<=26;i++) if(!in[i]) q.push(i),vis[i]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		id[x]=++cnt;
		sol[cnt]=x;
		for(i=0;i<E[x].size();i++)
		{
			int y=E[x][i];
			in[y]--;
			if(!in[y]) q.push(y),vis[y]=1;
		}
	}
	for(i=1;i<=26;i++) if(!id[i]) return printf("Impossible\n"),0;
	for(i=2;i<=n;i++)
	{
		k=min(s[i].size(),s[i-1].size());
		for(j=0;j<k;j++)
		{
			if(s[i][j]!=s[i-1][j]) break;
		}
		if(j!=k)
		{
			if(id[s[i-1][j]-'a'+1]>id[s[i][j]-'a'+1]) return printf("Impossible\n"),0;
		}
	}
	for(i=1;i<=26;i++) printf("%c",sol[i]+'a'-1);
	return 0;
}