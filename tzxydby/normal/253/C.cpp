#include<bits/stdc++.h>
using namespace std;
const int N=105,M=100005;
int a[N],dis[N][M];
queue<pair<pair<int,int>,int>>q;
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,r1,c1,r2,c2,kx,ky,kdis,sum=0,cnt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[r1][c1]=0;
	q.push(make_pair(make_pair(r1,c1),0));
	while(!q.empty())
	{
		pair<pair<int,int>,int>k=q.front();
		q.pop();
		kx=k.first.first;
		ky=k.first.second;
		kdis=k.second;
		if(kx==r2&&ky==c2)
		{
			printf("%d\n",kdis);
			break;
		}
		if(ky>=2&&kdis+1<dis[kx][ky-1])
		{
			dis[kx][ky-1]=kdis+1;
			q.push(make_pair(make_pair(kx,ky-1),kdis+1));
		}
		if(ky<a[kx]&&kdis+1<dis[kx][ky+1])
		{
			dis[kx][ky+1]=kdis+1;
			q.push(make_pair(make_pair(kx,ky+1),kdis+1));
		}
		if(kx!=n&&kdis+1<dis[kx+1][min(ky,a[kx+1]+1)])
		{
			dis[kx+1][min(ky,a[kx+1]+1)]=kdis+1;
			q.push(make_pair(make_pair(kx+1,min(ky,a[kx+1]+1)),kdis+1));
		}
		if(kx!=1&&kdis+1<dis[kx-1][min(ky,a[kx-1]+1)])
		{
			dis[kx-1][min(ky,a[kx-1]+1)]=kdis+1;
			q.push(make_pair(make_pair(kx-1,min(ky,a[kx-1]+1)),kdis+1));
		}
	}
	return 0;
}
///////