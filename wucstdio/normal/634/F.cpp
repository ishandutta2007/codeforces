#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	int x,y;
}a[3005];
int h,w,n,k,p1[15],p2[15],pre[3005],nxt[3005],num[3005];
ll ans;
bool cmp(Point a,Point b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d%d%d%d",&h,&w,&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int l=1;l<=h;l++)
	{
		for(int i=1;i<=w;i++)num[i]=0;
		for(int i=1;i<=n;i++)
		  if(a[i].x>=l)
		    num[a[i].y]++;
		for(int i=1;i<=w+1;i++)
		{
			if(num[i-1])pre[i]=i-1;
			else pre[i]=pre[i-1];
		}
		nxt[w+1]=w+1;
		for(int i=w;i>=1;i--)
		{
			if(num[i+1])nxt[i]=i+1;
			else nxt[i]=nxt[i+1];
		}
		int tot=0;
		for(int i=1;i<=w;i++)
		{
			int now=num[i];
			int j=i;
			while(j<=w&&now<k)
			{
				j=nxt[j];
				now+=num[j];
			}
			tot+=w+1-j;
		}
		int now=n;
		for(int r=h;r>=l;r--)
		{
			while(a[now].x>r)
			{
				num[a[now].y]--;
				int p=a[now].y;
				int s=min(k,num[a[now].y]);
				for(int i=0;i<=s;i++)p1[i]=p;
				while(p&&s<k)
				{
					p=pre[p];
					int ss=min(k,s+num[p]);
					for(int i=s+1;i<=ss;i++)p1[i]=p;
					s=ss;
				}
				while(s<k)p1[++s]=p;
				p=a[now].y,s=0;
				p2[0]=p;
				while(p<=w&&s<k)
				{
					p=nxt[p];
					int ss=min(k,s+num[p]);
					for(int i=s+1;i<=ss;i++)p2[i]=p;
					s=ss;
				}
				while(s<k)p2[++s]=p;
				for(int i=0;i<k;i++)tot-=(p1[i]-p1[i+1])*(p2[k-i]-p2[k-i-1]);
				if(num[a[now].y]==0)
				{
					pre[nxt[a[now].y]]=pre[a[now].y];
					nxt[pre[a[now].y]]=nxt[a[now].y];
				}
				now--;
			}
//			printf("%d %d %d\n",l,r,tot);
//			for(int i=1;i<=w;i++)printf("%d ",num[i]);
//			printf("\n");
//			for(int i=1;i<=w;i++)printf("%d ",pre[i]);
//			printf("\n");
//			for(int i=1;i<=w;i++)printf("%d ",nxt[i]);
//			printf("\n");
			ans+=tot;
		}
	}
	printf("%lld\n",ans);
	return 0;
}