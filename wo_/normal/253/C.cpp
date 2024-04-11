#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

int inf=10000000;

int a[110];
int ca[110];

int vals[120];
int vln;

int sr,sc,tr,tc;
int csc,ctc;

int dis[110][110];

priority_queue<PP,vector<PP>,greater<PP> > que;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	scanf("%d%d%d%d",&sr,&sc,&tr,&tc);
	sr--;tr--;
	for(int i=0;i<N;i++)
	{
		vals[i]=a[i]+1;
	}
	vals[N]=tc;vals[N+1]=sc;vals[N+2]=1;
	sort(vals,vals+N+3);
	vln=unique(vals,vals+N+3)-vals;
	for(int i=0;i<N;i++) ca[i]=lower_bound(vals,vals+vln,a[i]+1)-vals;
	ctc=lower_bound(vals,vals+vln,tc)-vals;
	csc=lower_bound(vals,vals+vln,sc)-vals;
	for(int i=0;i<N;i++) for(int j=0;j<vln;j++) dis[i][j]=inf;
	dis[sr][csc]=0;
	que.push(PP(0,P(sr,csc)));
	while(!que.empty())
	{
		PP pp=que.top();
		que.pop();
		int t=pp.first,r=pp.second.first,c=pp.second.second;
		if(dis[r][c]<t) continue;
		dis[r][c]=t;
		if(r!=0)
		{
			int nc;
			if(ca[r-1]>=c) nc=c;
			else nc=ca[r-1];
			int nt=t+1;
			if(dis[r-1][nc]<=nt){}
			else
			{
				dis[r-1][nc]=nt;
				que.push(PP(nt,P(r-1,nc)));
			}
		}
		if(r!=N-1)
		{
			int nc;
			if(ca[r+1]>=c) nc=c;
			else nc=ca[r+1];
			int nt=t+1;
			if(dis[r+1][nc]<=nt){}
			else
			{
				dis[r+1][nc]=nt;
				que.push(PP(nt,P(r+1,nc)));
			}
		}
		if(ca[r]>c)
		{
			int nt=t+vals[c+1]-vals[c];
			if(dis[r][c+1]<=nt){}
			else
			{
				dis[r][c+1]=nt;
				que.push(PP(nt,P(r,c+1)));
			}
		}
		if(c>0)
		{
			int nt=t+vals[c]-vals[c-1];
			if(dis[r][c-1]<=nt){}
			else
			{
				dis[r][c-1]=nt;
				que.push(PP(nt,P(r,c-1)));
			}
		}
	}
	printf("%d\n",dis[tr][ctc]);
	return 0;
}