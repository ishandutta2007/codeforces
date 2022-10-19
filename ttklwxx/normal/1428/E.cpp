#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
inline int f(int x,int y)
{
	return (y-x%y)*(x/y)*(x/y)+x%y*(x/y+1)*(x/y+1);
}
struct sth
{
	int x,y;
};
bool operator<(sth a,sth b)
{
	return f(a.x,a.y+1)-f(a.x,a.y)>f(b.x,b.y+1)-f(b.x,b.y);
}
//struct node{int x,y;bool operator < (const node&w)const{return f(x,y+1)-f(x,y)>f(w.x,w.y+1)-f(w.x,w.y);}};
priority_queue<struct sth>q;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
signed main()
{
	int n,m,x,y,ans=0;
	n=read();
	m=read();
	m=m-n;
	for(int i=1;i<=n;i++)cin>>x,ans+=x*x,q.push((struct sth){x,1});
	for(int i=1;i<=m;i++)
	{
		x=q.top().x;
		y=q.top().y;
		q.pop();
		ans=ans-f(x,y)+f(x,y+1);
		q.push((struct sth){x,y+1});
	}
	printf("%lld\n",ans);
	return 0; 
}