#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<set>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
set<int>b[100020];
vector<ii>a[100020];
int d[100020];
int v[200020];
priority_queue<ii>q;
int n,m,x,y,z;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(ii(y,z));
		a[y].push_back(ii(x,z));
	}
	for(int i=1;i<=n;i++)
	{
		for(scanf("%d",&x);x--;)
		{
			scanf("%d",&y);
			b[i].insert(y);
		}
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(ii(0,1));
	while(q.size())
	{
		ii u=q.top();
		q.pop();
		if(v[u.Y])
			continue;
		v[u.Y]=1;
		int w=-u.X;
		while(b[u.Y].count(w))
			w++;
		fe(i,a[u.Y])
			if(d[i->X]>w+i->Y)
			{
				d[i->X]=w+i->Y;
				q.push(ii(-d[i->X],i->X));
			}
	}
	printf("%d",d[n]<0x3f3f3f3f?d[n]:-1);
	return 0;
}