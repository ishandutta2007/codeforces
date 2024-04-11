#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",x);
#define print(x) printf("%d ",x);
const int inf=0x3fffffff;
const double pi=acos(-1.);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
char s[1020][1020];
int d[1020][1020];
struct N
{
	int x,y,d,c;
	N(int x=0,int y=0,int d=0,int c=0):
		x(x),y(y),d(d),c(c){}
};
deque<N>q;
int in(int x,int y)
{
	if(x>=0&&y>=0&&x<=n&&y<=m)
		return 1;
	return 0;
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	memset(d,0x3f,sizeof d);
	for(int i=0;i<m;i++)
	{
		d[0][i]=0;
		if(s[0][i]=='#')
		{
			q.push_back(N(0,i,0,1));
		}
	}
//	int cnt=0;
	while(q.size())
	{
		N u=q.front();
		q.pop_front();
		int nx,ny,nd,nc;
		nx=u.x;
		ny=u.y;
		nd=u.d;
		nc=u.c;
		nx+=dx[nd],ny+=dy[nd];
		for(;in(nx,ny);nx+=dx[nd],ny+=dy[nd])
		{
			if(d[nx][ny]>d[u.x][u.y])
			{
				d[nx][ny]=d[u.x][u.y]+nc;
				if(s[nx][ny]=='#')
				{
					q.push_front(N(nx,ny,nd,0));
					fr(k,4)
						if(k!=nd)
						{
							q.push_back(N(nx,ny,k,1));
						}
					break;
				}
			}
			if(s[nx][ny]=='#')
				break;
		}
/*		cnt++;
		if(cnt%10000==0)
			printf("%d\n",cnt);*/
	}
	if(d[n-1][m]<0x3f3f3f3f)
		printf("%d",d[n-1][m]);
	else
		puts("-1");
/*	fr(i,n+1)
	{
		fr(j,m+1)
			printf("%d ",d[i][j]);
		puts("");
	}*/
	return 0;
}