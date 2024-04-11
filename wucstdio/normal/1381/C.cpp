#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int t,n,x,y,a[100005],b[100005],num[100005];
vector<int>pos[100005];
priority_queue<pair<int,int> >q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		while(!q.empty()) q.pop();
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n+1;i++)num[i]=a[i]=0,pos[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			num[b[i]]++;
			pos[b[i]].push_back(i);
		}
		int val=0;
		for(int i=1;i<=n+1;i++)
		{
			if(!num[i])val=i;
			else q.push(make_pair(num[i],i));
		}
		int tot=n;
		while(tot>n-x)
		{
			int p=q.top().second;
			q.pop();
			num[p]--;
			a[pos[p].back()]=p;
			pos[p].pop_back();
			tot--;
			q.push(make_pair(num[p],p));
		}
		while(!q.empty()&&q.top().first*2>tot)
		{
			int p=q.top().second;
			q.pop();
			num[p]--;
			pos[p].pop_back();
			tot--;
			q.push(make_pair(num[p],p));
			if(tot<y-x)break;
		}
		if(tot<y-x)
		{
			printf("NO\n");
			continue;
		}
		while(tot&&tot!=3)
		{
			int p1=q.top().second;
			q.pop();
			int p2=q.top().second;
			q.pop();
			num[p1]--;
			num[p2]--;
			a[pos[p1].back()]=p2;
			a[pos[p2].back()]=p1;
			pos[p1].pop_back();
			pos[p2].pop_back();
			if(num[p1])q.push(make_pair(num[p1],p1));
			if(num[p2])q.push(make_pair(num[p2],p2));
			tot-=2;
		}
		if(tot==3)
		{
			int p1=q.top().second;
			q.pop();
			int p2=q.top().second;
			q.pop();
			int p3=q.top().second;
			q.pop();
			num[p1]--;
			num[p2]--;
			num[p3]--;
			a[pos[p1].back()]=p2;
			a[pos[p2].back()]=p3;
			a[pos[p3].back()]=p1;
			pos[p1].pop_back();
			pos[p2].pop_back();
			pos[p3].pop_back();
			tot-=3;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				a[i]=val;
				cnt++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=val&&a[i]!=b[i]&&cnt<n-y)
			{
				a[i]=val;
				cnt++;
			}
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}