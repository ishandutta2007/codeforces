#include<stdio.h>
#include<set>
using namespace std;
int n,m,l;
char s[20][20];
set<long long>v;
struct N
{
	int x[10],y[10],d;
}q[131077];
int b,f,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
long long H(const N&_)
{
	long long w=0;
	for(int i=0;i<l;i++)
		w+=13131*w+131*_.x[i]+_.y[i];
	return w;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]>='0'&&s[i][j]<='9')
			{
				q[0].x[s[i][j]-'0'-1]=i,q[0].y[s[i][j]-'0'-1]=j;
				l=max(l,s[i][j]-'0');
			}
	v.insert(H(q[0]));
	for(b=0,f=1;b!=f;++b&=131071)
	{
		for(int i=0,j;i<4;i++)
		{
			int x=q[b].x[0]+dx[i],y=q[b].y[0]+dy[i];
			if(x<0||x>=n||y<0||y>=m)
				continue;
			for(j=0;j<l-1;j++)
				if(x==q[b].x[j]&&y==q[b].y[j])
					break;
			if(j<l-1||s[x][y]=='#')
				continue;
			if(s[x][y]=='@')
			{
				printf("%d\n",q[b].d+1);
				return 0;
			}
			q[f].x[0]=x,q[f].y[0]=y;
			for(j=1;j<l;j++)
				q[f].x[j]=q[b].x[j-1],q[f].y[j]=q[b].y[j-1];
			q[f].d=q[b].d+1;
			long long w=H(q[f]);
			if(v.count(w))
				continue;
			v.insert(w),++f&=131071;
		}
	}
	puts("-1");
}