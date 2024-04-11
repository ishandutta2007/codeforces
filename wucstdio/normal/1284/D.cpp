#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
	int val,pos;
	bool lorr;
}a[200005];
int n,la[100005],ra[100005],lb[100005],rb[100005],c1[200005],c2[200005];
bool cmp(Node a,Node b)
{
	return a.val<b.val||(a.val==b.val&&a.lorr<b.lorr);
}
void add(int p,int*c)
{
	while(p<=2*n)
	{
		c[p]++;
		p+=p^(p&(p-1));
	}
}
int sum(int p,int*c)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
int sum(int l,int r,int*c)
{
	return sum(r,c)-sum(l-1,c);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&la[i],&ra[i],&lb[i],&rb[i]);
	for(int i=1;i<=n;i++)
	{
		a[2*i-1].val=la[i];
		a[2*i-1].lorr=0;
		a[2*i-1].pos=i;
		a[2*i].val=ra[i]+1;
		a[2*i].lorr=1;
		a[2*i].pos=i;
	}
	sort(a+1,a+2*n+1,cmp);
	int now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(i==1||a[i].val!=a[i-1].val)now++;
		if(a[i].lorr)ra[a[i].pos]=now-1;
		else la[a[i].pos]=now;
	}
	for(int i=1;i<=n;i++)
	{
		a[2*i-1].val=lb[i];
		a[2*i-1].lorr=0;
		a[2*i-1].pos=i;
		a[2*i].val=rb[i]+1;
		a[2*i].lorr=1;
		a[2*i].pos=i;
	}
	sort(a+1,a+2*n+1,cmp);
	now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(i==1||a[i].val!=a[i-1].val)now++;
		if(a[i].lorr)rb[a[i].pos]=now-1;
		else lb[a[i].pos]=now;
	}
	for(int i=1;i<=n;i++)
	{
		a[2*i-1].val=la[i];
		a[2*i-1].lorr=0;
		a[2*i-1].pos=i;
		a[2*i].val=ra[i];
		a[2*i].lorr=1;
		a[2*i].pos=i;
	}
	sort(a+1,a+2*n+1,cmp);
	now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].lorr)
		{
			add(lb[a[i].pos],c1);
			add(rb[a[i].pos],c2);
			now++;
		}
		else
		{
			if(sum(lb[a[i].pos]-1,c2)+sum(rb[a[i].pos]+1,2*n,c1)!=now)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[2*i-1].val=lb[i];
		a[2*i-1].lorr=0;
		a[2*i-1].pos=i;
		a[2*i].val=rb[i];
		a[2*i].lorr=1;
		a[2*i].pos=i;
	}
	sort(a+1,a+2*n+1,cmp);
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].lorr)
		{
			add(la[a[i].pos],c1);
			add(ra[a[i].pos],c2);
			now++;
		}
		else
		{
			if(sum(la[a[i].pos]-1,c2)+sum(ra[a[i].pos]+1,2*n,c1)!=now)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}