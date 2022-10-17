#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct P
{
	char s[50];
	int score;
	bool operator<(const P& b)const
	{
			return score > b.score;
	}
};
map<string,int> g;
P p[1111];
char* T[]={"noob","random","average","hardcore","pro"};
int main(void)
{
	int n;
	char s[50];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int ts=0;
		scanf("%s %d",s,&ts);
		g[string(s)]=max(g[string(s)],ts);
	}
	int cnt=0;
	for(map<string,int>::iterator it=g.begin();it!=g.end();it++)
	{
		strcpy(p[cnt].s,it->first.c_str());
		p[cnt++].score = it->second;
	}
	sort(p,p+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		int j;
		for(j=i;j<cnt;j++)
			if(p[j].score!=p[i].score)
				break;
		char* tt=NULL;
		if(i*2>cnt)
			tt=T[0];
		else if(i*5>cnt)
			tt=T[1];
		else if(i*10>cnt)
			tt=T[2];
		else if(i*100>cnt)
			tt=T[3];
		else tt=T[4];
		for(int c=i;c<j;c++)
		{
			printf("%s %s\n",p[c].s,tt);
		}
		i=j-1;
	}
	return 0;
}