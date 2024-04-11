#include<cstdio>
#include<utility>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

set<int> unv;

P es[1000100];

int m;
int con[500500];

int cnt=0;
int head[500500],nxt[500500];
int sz[500500];
queue<int> que;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		es[i]=P(a,b);
	}
	sort(es,es+M);
	for(int i=1;i<=N;i++) unv.insert(i);
	while(!unv.empty())
	{
		int v=*unv.begin();
		m=0;
		con[m]=v;
		m++;
		que.push(v);
		unv.erase(v);
		while(!que.empty())
		{
			int v=que.front();
			que.pop();
			set<int>::iterator it=unv.begin();
			for(;it!=unv.end();)
			{
				int nv=*it;
				P e=P(min(nv,v),max(nv,v));
				if(!binary_search(es,es+M,e))
				{
					que.push(nv);
					//unv.erase(nv);
					unv.erase(it++);
					con[m]=nv;
					m++;
					//it=unv.upper_bound(nv);
				}
				else it++;
			}
		}/*
		printf("%d",m);
		for(int i=0;i<m;i++)
		{
			printf(" %d",con[i]);
		}
		printf("\n");*/
		head[cnt]=con[0];
		sz[cnt]=m;
		for(int i=0;i<m-1;i++)
		{
			nxt[con[i]]=con[i+1];
		}
		nxt[con[m-1]]=-1;
		cnt++;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d",sz[i]);
		for(int j=head[i];j!=-1;j=nxt[j])
		{
			printf(" %d",j);
		}
		printf("\n");
	}
	return 0;
}