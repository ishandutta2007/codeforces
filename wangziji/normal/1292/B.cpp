#include <iostream>
#include <cmath>
#define int long long
using namespace std;
pair <int,int> a[100005],b[100005];
inline int dis(pair<int,int> x,pair <int,int> y)
{
	return abs(x.first-y.first)+abs(x.second-y.second);
}
int cnt=0;
signed main(int argc, char** argv) {
	int x0,y0,ax,ay,bx,by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	int x,y,t;
	cin >> x >> y >> t;
	a[++cnt]={x0,y0};
	for(int i=1;i<=1000;i++)
	{
		x0=ax*x0+bx;
		y0=ay*y0+by;
		if(dis({x,y},{x0,y0})<=t)
			a[++cnt]={x0,y0};
		if(x0>=5e16||y0>=5e16)
			break;
	}
	/*for(int i=1;i<=cnt;i++)
		cout << a[i].first << " " << a[i].second << endl;*/
	int CNT=0,ans=0;
	b[++CNT]={x,y};
	for(int i=1;i<=cnt;i++)
	{
		CNT=1;
		for(int j=i;j>=1;j--)
			b[++CNT]=a[j];
		for(int j=i+1;j<=cnt;j++)
			b[++CNT]=a[j];
	//	for(int j=1;j<=CNT;j++)
	//		cout << b[j].first << " " << b[j].second << endl;
	//		cout << endl;
		int now=0;
		for(int j=2;j<=CNT;j++)
		{
			now+=dis(b[j],b[j-1]);
			if(now>t)
			{
				ans=max(ans,j-2);
				break;
			}
			if(j==CNT)
			{
				ans=CNT-1;
				cout << ans;
				return 0;
			}
		}
		//cout << endl << endl; 
		
		CNT=1;
		for(int j=i;j<=cnt;j++)
			b[++CNT]=a[j];
		for(int j=i-1;j>=1;j--)
			b[++CNT]=a[j];
		now=0;
		for(int j=2;j<=CNT;j++)
		{
			now+=dis(b[j],b[j-1]);
			if(now>t)
			{
				ans=max(ans,j-2);
				break;
			}
			if(j==CNT)
			{
				ans=CNT-1;
				cout << ans;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}