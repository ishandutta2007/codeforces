#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
const int N=1050;
const int inf=1000000000;
queue< pair<int,int> > q;
set<int> hor[N],ver[N];
int DP[N][N];
char Base[N][N]; 
int Matrix[N][N];
int Query(int x1, int y1, int x2, int y2)
{
	x1--,y1--;
	return Matrix[x2][y2]+Matrix[x1][y1]-Matrix[x1][y2]-Matrix[x2][y1];
}
int k;
int GetLowerVer(int x, int y)
{
	set<int>::iterator it;
	it=ver[y].find(x);
	if(it==ver[y].begin()) return -1;
	it--;
	if(Query(*it,y,x,y)>0) return -1;
	if(x-(*it)>k) return -1;
	return *it;
}
int GetHigherVer(int x, int y)
{
	set<int>::iterator it;
	it=ver[y].find(x);
	it++;
	if(it==ver[y].end()) return -1;
	if(Query(x,y,*it,y)>0) return -1;
	if((*it)-x>k) return -1;
	return *it;
}
int GetLowerHor(int x, int y)
{
	set<int>::iterator it;
	it=hor[x].find(y);
	if(it==hor[x].begin()) return -1;
	it--;
	if(Query(x,*it,x,y)>0) return -1;
	if(y-(*it)>k) return -1;
	return *it;
}
int GetHigherHor(int x, int y)
{
	set<int>::iterator it;
	it=hor[x].find(y);
	it++;
	if(it==hor[x].end()) return -1;
	if(Query(x,y,x,*it)>0) return -1;
	if((*it)-y>k) return -1;
	return *it;
}
int main()
{
	int n,m,i,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%s",Base[i]+1);
		for(j=1;j<=m;j++)
		{
			if(Base[i][j]=='#') Matrix[i][j]=1;
			else hor[i].insert(j),ver[j].insert(i);
			Matrix[i][j]+=Matrix[i-1][j]+Matrix[i][j-1]-Matrix[i-1][j-1];
			DP[i][j]=inf;
		}
	}
	set<int>::iterator it;
	//for(i=1;i<=n;i++) for(it=hor[i].begin();it!=hor[i].end();it++) printf("%i %i\n",i,*it);
	//for(i=1;i<=m;i++) for(it=ver[i].begin();it!=ver[i].end();it++) printf("%i %i\n",*it,i);
	int x1,y1,x2,y2;
	scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
	q.push(make_pair(x1,y1));
	hor[x1].erase(y1);
	ver[y1].erase(x1);
	DP[x1][y1]=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		hor[x].insert(y);
		ver[y].insert(x);
		//printf("%i %i\n",x,y);
		int f=GetLowerVer(x,y);
		//printf("LV:%i\n",f);
		while(f>-1)
		{
			//printf("%i %i\n",f,y);
			DP[f][y]=DP[x][y]+1;
			q.push(make_pair(f,y));
			hor[f].erase(y);
			ver[y].erase(f);
			f=GetLowerVer(x,y);
		}
		f=GetHigherVer(x,y);
		//printf("HV:%i\n",f);
		while(f>-1)
		{
			//printf("%i %i\n",f,y);
			DP[f][y]=DP[x][y]+1;
			q.push(make_pair(f,y));
			hor[f].erase(y);
			ver[y].erase(f);
			f=GetHigherVer(x,y);
		}
		f=GetLowerHor(x,y);
		//printf("LH:%i\n",f);
		while(f>-1)
		{
			//printf("%i %i\n",x,f);
			DP[x][f]=DP[x][y]+1;
			q.push(make_pair(x,f));
			hor[x].erase(f);
			ver[f].erase(x);
			f=GetLowerHor(x,y);
		}
		f=GetHigherHor(x,y);
		//printf("HH:%i\n",f);
		while(f>-1)
		{
			//printf("%i %i\n",x,f);
			DP[x][f]=DP[x][y]+1;
			q.push(make_pair(x,f));
			hor[x].erase(f);
			ver[f].erase(x);
			f=GetHigherHor(x,y);
		}
		hor[x].erase(y);
		ver[y].erase(x);
	}
	if(DP[x2][y2]==inf) printf("-1\n");
	else printf("%i\n",DP[x2][y2]);
	return 0;
}