#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int id,x,y,z;
}a[100005];
inline bool cmp(node x,node y)
{
	return x.x<y.x||x.x==y.x&&x.y<y.y||x.x==y.x&&x.y==y.y&&x.z<y.z;
}
int vis[100005],n;
inline int pd(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&i!=x&&i!=y&&
		a[i].x>=min(a[x].x,a[y].x)&&
		a[i].x<=max(a[x].x,a[y].x)&&
		a[i].y>=min(a[x].y,a[y].y)&&
		a[i].y<=max(a[x].y,a[y].y)&&
		a[i].z>=min(a[x].z,a[y].z)&&
		a[i].z<=max(a[x].z,a[y].z))
			return i;
	}
	return 0;
}
int main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if(!vis[j])
			{
				int x=j,y;
				cnt=0;
				while(y=pd(i,j))
				{
					if(cnt>100)
						break;
					++cnt;
					x=y;
				}
				if(cnt>100)
					continue;
				vis[i]=vis[x]=1;
				cout << a[i].id << " " << a[x].id << endl;
				break;
			}
		}
	}
	return 0;
}