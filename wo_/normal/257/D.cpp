#include<cstdio>
#include<vector>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

typedef pair<int,int> P;

int a[100100];

multiset<P,greater<P> > se;
//vector<int> ids[30300];
int ids[300300];
bool res[300300];
bool islast[300300];

int c=1;
void dfs()
{
	if(se.size()==1)
	{
		P p=*se.begin();
		res[p.second]=true;
		islast[p.second]=true;
		return;
	}
	else if(se.size()==2)
	{
		multiset<P,greater<P> >::iterator it=se.begin();
		res[(*it).second]=true;
		islast[(*it).second]=true;
		it++;
		islast[(*it).second]=true;
		res[(*it).second]=false;
		return;
	}
	P p[3];
	multiset<P,greater<P> > ::iterator it=se.begin();
	for(int i=0;i<3;i++)
	{
		p[i]=*it;
		it++;
	}
	it=se.begin();
	for(int i=0;i<3;i++)
	{
		se.erase(it++);
	}
	int tmp=p[0].first-p[2].first-p[1].first;
	if(tmp<0)
	{
		/*ids[c].push_back(-p[0].second);
		ids[c].push_back(-p[1].second);
		ids[c].push_back(p[2].second);*/
		ids[p[0].second]=-c;
		ids[p[1].second]=c;
		ids[p[2].second]=c;
		se.insert(P(-tmp,c));
	}
	else
	{
		/*ids[c].push_back(p[0].second);
		ids[c].push_back(p[1].second);
		ids[c].push_back(-p[2].second);*/
		ids[p[0].second]=c;
		ids[p[1].second]=-c;
		ids[p[2].second]=-c;
		se.insert(P(tmp,c));
	}
	c++;
	dfs();
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		se.insert(P(a[i],i));
	}
	memset(islast,false,sizeof(islast));
	c=N+1;
	dfs();
	for(int i=c-1;i>=1;i--)
	{
		if(islast[i]) continue;
		if(ids[i]<0)
		{
			int id=-ids[i];
			res[i]=!res[id];
		}
		else
		{
			int id=ids[i];
			res[i]=res[id];
		}
	}
	for(int i=1;i<=N;i++)
	{
		printf("%c",res[i]?'+':'-');
	}
	printf("\n");
	return 0;
}