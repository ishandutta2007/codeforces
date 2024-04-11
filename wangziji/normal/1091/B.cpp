#include <iostream>
#include <map>
using namespace std;
struct node
{
	int x,y;
}a[100005],b[100005];
map <pair<int,int>,int> mp;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].x >> a[i].y;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i].x >> b[i].y;
		mp[{b[i].x,b[i].y}]=1;
	}
	for(int i=1;i<=n;i++)
	{
		node ans={a[1].x+b[i].x,a[1].y+b[i].y};
		for(int j=1;j<=n;j++)
		{
			if(!mp.count({ans.x-a[j].x,ans.y-a[j].y}))
			{
				break;
			}
			if(j==n)
			{
				cout << ans.x << " " << ans.y;
				return 0;
			}
		}
	}
	return 0;
}