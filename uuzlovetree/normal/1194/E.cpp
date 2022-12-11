#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
struct Line
{
	int x,y,xx,yy;
	Line(int X=0,int Y=0,int XX=0,int YY=0):x(X),y(Y),xx(XX),yy(YY){}
};
int n,m;
Line a[5005],b[5005];
bool cmp1(Line A,Line B)
{
	return A.y<B.y;
}
bool cmp2(Line A,Line B)
{
	return A.x<B.x;
}
int c[10005];
void add(int x,int v)
{
	for(;x<=10003;x+=x&(-x))c[x]+=v;
}
int get(int x)
{
	int ans=0;
	for(;x;x-=x&(-x))ans+=c[x];
	return ans; 
}
struct node
{
	int y,pos;
	node(int Y=0,int POS=0):y(Y),pos(POS){} 
};
bool operator < (node A,node B)
{
	return A.y>B.y;
}
int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		if(x>xx)swap(x,xx);
		if(y>yy)swap(y,yy);
		x+=5002,y+=5002,xx+=5002,yy+=5002;
		if(y==yy)a[++n]=Line(x,y,xx,yy);
		else b[++m]=Line(x,y,xx,yy);
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1,cmp2);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		priority_queue<node> pq;
		memset(c,0,sizeof(c));
		for(int k=1;k<=m;++k)
			if(a[i].x<=b[k].x&&b[k].x<=a[i].xx&&b[k].y<=a[i].y&&a[i].y<=b[k].yy)
			{
				add(b[k].x,1);
				pq.push(node(b[k].yy,b[k].x));
			}
		for(int j=i+1;j<=n;++j)
		{
			int l=a[j].x,r=a[j].xx;
			while(!pq.empty()&&pq.top().y<a[j].y)
			{
				add(pq.top().pos,-1);
				pq.pop();
			}
			int res=get(r)-get(l-1);
			ans+=1ll*res*(res-1)/2;
		}
	}
	cout<<ans<<endl;
}