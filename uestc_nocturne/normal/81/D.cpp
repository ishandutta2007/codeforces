#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j;
int out[1200],po;
struct Node
{
	int va,id;
}q[120];
bool cmp(Node x,Node y)
{return x.va>y.va;}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(out,0,sizeof(out));
		for(i=0;i<m;i++)
		{
			scanf("%d",&q[i].va);
			q[i].id=i+1;
		}
		bool can=true;
		sort(q,q+m,cmp);int now=0;
		for(i=1;i<=n;)
		{
		//	printf("JS: %d %d\n",i,now);
			if(now==m){can=false;break;}
			if(q[now].va>0&&(n%2==0||out[i%n+1]!=q[now].id))
			{
				out[i]=q[now].id;
				q[now].va--;
				i+=2;
			}
			else
			{
				now++;
			}
		}
		now=0;
		for(i=2;i<=n;)
		{
		//	printf("OS: %d %d\n",i,now);
			if(now==m){can=false;break;}
			if(q[now].va>0&&out[i%n+1]!=q[now].id&&out[(i-2+n)%n+1]!=q[now].id)
			{
				out[i]=q[now].id;
				q[now].va--;
				i+=2;
			}
			else
			{
				now++;
			}
		}
		for(i=1;i<=n;i++)if(out[i]==0)can=false;
		if(!can){puts("-1");continue;}
		for(i=1;i<n;i++)printf("%d ",out[i]);printf("%d\n",out[n]);
	}
}