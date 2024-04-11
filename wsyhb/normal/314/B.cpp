#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
const int max_m=100+5;
char s[max_n],t[max_m];
const int cnt_letters=26+5;
bool mark[cnt_letters];
typedef pair<int,int> P;
P pos[max_n];
int vis[max_n];
int main()
{
	int a,b;
	scanf("%d%d%s%s",&a,&b,s,t);
	int n=strlen(s),m=strlen(t);
	for(int i=0;i<n;++i)
		mark[s[i]-'a']=true;
	for(int i=0;i<m;++i)
	{
		if(!mark[t[i]-'a'])
		{
			puts("0");
			return 0;
		}
	}
	int x=1,y=0,sz=0;
	while(1)
	{
		for(int i=0;i<m;++i)
		{
			while(s[y]!=t[i])
			{
				++y;
				if(y==n)
					++x,y=0;
			}
			++y;
			if(y==n)
				++x,y=0;
		}
		--y;
		if(y==-1)
			--x,y=n-1;
		pos[++sz]=P(x,y);
		if(vis[y])
			break;
		vis[y]=sz;
		++y;
		if(y==n)
			++x,y=0;
	}
	int end_pos=vis[y];
	for(int i=1;i<=end_pos;++i)
	{
		if(pos[i].first>a)
		{
			printf("%d\n",(i-1)/b);
			return 0;
		}
	}
	int re=a-pos[end_pos].first;
	int cnt=end_pos+(sz-end_pos)*(re/(pos[sz].first-pos[end_pos].first));
	re%=pos[sz].first-pos[end_pos].first;
	x=a-re,y=pos[sz].second;
	++y;
	if(y==n)
		++x,y=0;
	while(x<=a)
	{
		bool flag=true;
		for(int i=0;i<m;++i)
		{
			while(s[y]!=t[i]&&x<=a)
			{
				++y;
				if(y==n)
					++x,y=0;
			}
			if(x>a)
			{
				flag=false;
				break;
			}
			++y;
			if(y==n)
				++x,y=0;
		}
		cnt+=flag;
	}
	printf("%d\n",cnt/b);
	return 0;
}