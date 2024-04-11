#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,k,c;
vector<int>e[N];
char s[N];
void add(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	c=n,k=0;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='W')
			k++;
	for(int i=1;i<=k*3;i++)
		e[n+i].clear();
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='W')
		{
			add(i,c+1);
			add(c+1,c+2);
			add(c+1,c+3);
			c+=3;
		}
	}
	if(c==1)
	{
		puts("Draw");
		return;
	}
	int t=0,r=0;
	for(int i=1;i<=c;i++)
	{
		if(e[i].size()>=4)
		{
			puts("White");
			return;
		}
		if(e[i].size()==1)
			t++,r+=e[e[i][0]].size()==2;
	}
	if(t==2)
		puts("Draw");
	else if(t==3)
		puts(r>=2?"White":"Draw");
	else if(t==4)
		puts(r>=1||(c&1)?"White":"Draw");
	else
		puts("White");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}