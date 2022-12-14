#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,fx,fy,k;
	int dx[11234],dy[11234];
	scanf("%d%d",&n,&m);
	scanf("%d%d",&fx,&fy);
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",dx+i,dy+i);
	}
	long long res=0;
	long long cx=fx,cy=fy;
	for(int i=0;i<k;i++)
	{
		long long times=1<<30;
		if(dx[i]<0)
		{
			times=min(times,(cx-1)/(-dx[i]));
		}
		else if(dx[i]>0)
		{
			times=min(times,(n-cx)/dx[i]);
		}
		if(dy[i]<0)
		{
			times=min(times,(cy-1)/(-dy[i]));
		}
		else if(dy[i]>0)
		{
			times=min(times,(m-cy)/dy[i]);
		}
		res+=times;
		cx+=dx[i]*times;
		cy+=dy[i]*times;
	}
	cout << res;
	return 0;
}