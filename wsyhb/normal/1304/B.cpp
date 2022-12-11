#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=100+5,M=50+5;
char s[N][M];
bool mark[N];
int n,m,ans;
bool check(int x,int y)
{
	for(int i=1;i<=m;i++)
		if(s[x][i]!=s[y][m-i+1]) return false;
	return true;
}
queue<int> q;
stack<int> st;
void Print(int x)
{
	for(int i=1;i<=m;i++) printf("%c",s[x][i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!mark[i]&&!mark[j]&&check(i,j))
			{
				ans+=m<<1;
				mark[i]=mark[j]=true;
				q.push(i);
				st.push(j);
			}
	int mid=0;
	for(int i=1;i<=n;i++)
		if(!mark[i]&&check(i,i))
		{
			mid=i;
			ans+=m;
			break;
		}
	printf("%d\n",ans);
	while(q.size())
	{
		Print(q.front());
		q.pop();
	}
	if(mid) Print(mid);
	while(st.size())
	{
		Print(st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}