#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,m;
char mapp[2333][2333];
int dist[4][2333][2333];
typedef int arr[2333][2333];
template <class T,int siz>
struct fdeque
{
	T st[siz+3]; int head,tail,fsiz;
	void clr() {head=tail=fsiz=0;}
	bool empty() {return fsiz==0;}
	int size() {return fsiz;}
	T front() {return st[head];}
	T back() {return st[(tail-1+siz)%siz];}
	void push_back(T x) {st[tail]=x; tail=(tail+1)%siz; ++fsiz;}
	void push_front(T x) {head=(head-1+siz)%siz; st[head]=x; ++fsiz;}
	void pop_front() {if(fsiz) {head=(head+1)%siz; --fsiz;}}
	void pop_back() {if(fsiz) {tail=(tail-1+siz)%siz; --fsiz;}}
};
typedef pair<int,int> pii;
fdeque<pii,2333333> s;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void gd(int c,arr& arrr)
{
	s.clr();
	memset(arrr,-1,sizeof(arrr));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mapp[i][j]==c)
			{
				arrr[i][j]=0;
				s.push_back(make_pair(i,j));
			}
		}
	}
	while(!s.empty())
	{
		pii f=s.front();
		s.pop_front();
		int x=f.first,y=f.second;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&mapp[xx][yy]!='#');else continue;
			int curd=arrr[x][y]+(mapp[xx][yy]=='.');
			if(arrr[xx][yy]==-1||arrr[xx][yy]>curd)
			{
				arrr[xx][yy]=curd;
				s.push_back(make_pair(xx,yy));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",mapp[i]);
	for(int i='1';i<='3';i++) gd(i,dist[i-'0']);
	int ans=2000000001;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dist[1][i][j]>=0&&dist[2][i][j]>=0&&dist[3][i][j]>=0);
			else continue;
			int hh=dist[1][i][j]+dist[2][i][j]+dist[3][i][j];
			if(mapp[i][j]=='.') hh-=2;
			ans=min(ans,hh);
		}
	}
	if(ans<2000000000) cout<<ans<<"\n";
	else cout<<-1<<"\n";
}