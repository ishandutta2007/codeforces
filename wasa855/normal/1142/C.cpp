#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool ne=0;
	while(!isdigit(ch)){if(ch=='-') ne=1;ch=getchar();}
	int ans=0; while(isdigit(ch)){ans=ans*10+ch-48; ch=getchar();}
	if(!ne) return ans;
	return -ans;
}
#define N 200005
struct Vector
{
	int x,y;
	int operator * (const Vector &v) const
	{
		return x*v.y-y*v.x;
	}
	Vector operator - (const Vector &v) const
	{
		return (Vector){x-v.x,y-v.y};
	}
};
Vector a[N];
int st[N],tp;
bool cmp(Vector x,Vector y)
{
	if(x.x==y.x) return x.y>y.y;
	return x.x<y.x;
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]=(Vector){x,y-x*x};
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].x==a[i-1].x) continue;
		while(tp>=2&((a[st[tp]]-a[st[tp-1]])*(a[i]-a[st[tp]])>=0)) tp--;
		st[++tp]=i;
	}
	cout<<tp-1<<endl;
	return 0;
}