#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[100005],b[100005];
vector <int> v[100005];
priority_queue <pair <int,int> > q;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,y;
		cin >> n >> x >> y; 
		while(!q.empty()) q.pop();
		for(int i=1;i<=n+1;i++) v[i].clear(),b[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			v[a[i]].push_back(i);
		}
		int s=0;
		for(int i=1;i<=n+1;i++)
			if(!v[i].size()) s=i;
		for(int i=1;i<=n+1;i++)
			q.push({v[i].size(),i});
		for(int i=1;i<=x;i++)
		{
			int x=q.top().second;
			q.pop();
			b[v[x][v[x].size()-1]]=x;
			v[x].pop_back();
			q.push({v[x].size(),x});
		}
		y-=x;
		int flag=1;
		for(int i=1;i<=y/2-1+(y%2==0);i++)
		{
			int x=q.top().second;
			q.pop();
			int y=q.top().second;
			q.pop();
			if(!v[y].size())
			{
				flag=0;
				break;
			}
			b[v[x][v[x].size()-1]]=y;
			b[v[y][v[y].size()-1]]=x;
			v[x].pop_back(),v[y].pop_back();
			q.push({v[x].size(),x});
			q.push({v[y].size(),y});
		}
		if(!flag)
		{
			puts("NO");
			continue;
		}
		flag=0;
		if((y&1)&&y>=3)
		{
			int x=q.top().second;
			q.pop();
			int y=q.top().second;
			q.pop();
			int z=q.top().second;
			q.pop();
			if(v[x].size()&&v[y].size()&&v[z].size())
			{
				b[v[y][v[y].size()-1]]=x;
				b[v[x][v[x].size()-1]]=z;
				b[v[z][v[z].size()-1]]=y;
			}
			else
			{
				if(v[y].size()>=2)
				{
					b[v[y][v[y].size()-1]]=x;
					b[v[x][v[x].size()-1]]=y;
					v[x].pop_back();
					b[v[x][v[x].size()-1]]=y;
				}
				else
				{
					puts("NO");
					continue;
				}
			}
		}
		if(y==1)
		{
			int x=q.top().second;
			q.pop();
			int y=q.top().second;
			q.pop();
			if(!v[y].size())
			{
				puts("NO");
				continue;
			}
			b[v[y][v[y].size()-1]]=x;
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			if(!b[i]) b[i]=s;
		for(int i=1;i<=n;i++)
			cout << b[i] << " ";
		puts("");
	}
	return 0;
}