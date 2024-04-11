#include <iostream>
#include <cmath>
#define int long long
using namespace std;
struct node
{
	int first,second;
};
inline int d(node a,node b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
node a[500005];
signed main(int argc, char** argv) {
	int n,x,y;
	cin >> n >> x >> y;
	for(int i=1;i<=n;i++)
		cin >> a[i].first >> a[i].second;
	int ans=0,px,py;
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			if(i==x&&j==y) continue;
			int t=0;
			for(int k=1;k<=n;k++)
			{
				if(d({x,y},a[k])==d({x,y},{i,j})+d({i,j},a[k]))
					++t;
			}
			if(t>ans)
			{
				ans=t;
				px=i,py=j;
			}
		}
	}
	cout << ans << endl << px << " " << py << endl;
	return 0;
}