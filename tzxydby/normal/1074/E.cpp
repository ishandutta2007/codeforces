#include<bits/stdc++.h>
using namespace std;
const int N=30;
struct nd{int x,y;};
nd operator+(nd a,nd b){return {a.x+b.x,a.y+b.y};}
nd operator-(nd a,nd b){return {a.x-b.x,a.y-b.y};}
nd rt(nd a){return {a.y,-a.x};}
int n,m,a[N][N];
int in(nd a){return a.x>=1&&a.x<=n&&a.y>=1&&a.y<=m;}
vector<vector<int>>ans;
void add(vector<nd>v)
{
	vector<int>c;
	for(auto x:v)
		c.push_back(a[x.x][x.y]);
	ans.push_back(c);
	int s=v.size();
	int t=a[v.back().x][v.back().y];
	for(int i=s-2;i>=0;i--)
		a[v[i+1].x][v[i+1].y]=a[v[i].x][v[i].y];
	a[v[0].x][v[0].y]=t;
}
void ch1(nd a,nd b,nd d){nd c=b+b-a,e=b+d-a,f=c+e-b;add({a,b,e,d});add({b,c,f,e});add({a,d,e,f,c,b});}
void ch(nd a,nd b){nd c=b+b-a;if(!in(c))swap(a,b);nd d=a+rt(a-b);if(!in(d))d=a-rt(a-b);ch1(a,b,d);}
void sol(int d)
{
	nd q={(d-1)/m+1,(d-1)%m+1},p;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==d)
				p={i,j};
	while(p.y>q.y)
	{
		if(p.x!=q.x) add({p,p+(nd){0,-1},p+(nd){-1,-1},p+(nd){-1,0}});
		else if(p.x!=n) add({p,p+(nd){0,-1},p+(nd){1,-1},p+(nd){1,0}});
		else ch(p,p+(nd){0,-1});
		p.y--;
	}
	while(p.y<q.y)
	{
		if(p.x!=q.x+1) add({p,p+(nd){0,1},p+(nd){-1,1},p+(nd){-1,0}});
		else if(p.x!=n) add({p,p+(nd){0,1},p+(nd){1,1},p+(nd){1,0}});
		else ch(p,p+(nd){0,1});
		p.y++;
	}
	while(p.x>q.x)
	{
		if(p.y!=m) add({p,p+(nd){-1,0},p+(nd){-1,1},p+(nd){0,1}});
		else ch(p,p+(nd){-1,0});
		p.x--;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n*m;i++)
		sol(i);
	printf("%d\n",ans.size());
	for(auto i:ans)
	{
		printf("%d ",i.size());
		for(auto j:i)
			printf("%d ",j);
		puts("");
	}
	return 0;
}