#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
	int x,y;
	int type;
	int c;
	int id;
	Node(const int t=0,const int i=0,const int xx=0,const int yy=0,const int cc=0)
	{
		type=t,id=i;
		x=xx,y=yy,c=cc;
	}
}a[1000005],tmp[1000005];
int n,q,tot,ans[1000005],top,c[1000005],c0[1000005],c1[1000005];
bool flag[1000005];
void add(int p,int v,int*c)
{
	while(p<=2*n)
	{
		c[p]+=v;
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
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	top=0;
	int now1=l,now2=mid+1;
//	printf("[%d,%d]:\n",l,r);
	while(now1<=mid||now2<=r)
	{
		while(now1<=mid&&a[now1].type==0)now1++;
		while(now2<=r&&a[now2].type!=0)now2++;
		if(now1>mid&&now2>r)break;
		if(now1>mid)tmp[++top]=a[now2++];
		else if(now2>r)tmp[++top]=a[now1++];
		else
		{
			if(a[now1].x<=a[now2].x)tmp[++top]=a[now1++];
			else tmp[++top]=a[now2++];
		}
//		printf("type=%d,id=%d,(%d,%d),c=%d\n",tmp[top].type,tmp[top].id,tmp[top].x,tmp[top].y,tmp[top].c);
		if(tmp[top].type==1)
		{
			add(1,tmp[top].c,c0);
			add(tmp[top].x+tmp[top].y+1,-tmp[top].c,c0);
		}
		else if(tmp[top].type==2)
		{
			add(1,tmp[top].c,c1);
			add(tmp[top].x-tmp[top].y+n+1,-tmp[top].c,c1);
		}
		else if(tmp[top].type==3)
		{
			add(1,tmp[top].c,c);
			add(tmp[top].y+1,-tmp[top].c,c);
		}
		else if(tmp[top].type==4)
		{
			add(tmp[top].y,tmp[top].c,c);
		}
		else if(tmp[top].type==0)
			ans[tmp[top].id]+=sum(tmp[top].y,c)+sum(tmp[top].x+tmp[top].y,c0)+sum(tmp[top].x-tmp[top].y+n,c1);
	}
	for(int i=1;i<=top;i++)
	{
		if(tmp[i].type==1)
		{
			add(1,-tmp[i].c,c0);
			add(tmp[i].x+tmp[i].y+1,tmp[i].c,c0);
		}
		else if(tmp[i].type==2)
		{
			add(1,-tmp[i].c,c1);
			add(tmp[i].x-tmp[i].y+n+1,tmp[i].c,c1);
		}
		else if(tmp[i].type==3)
		{
			add(1,-tmp[i].c,c);
			add(tmp[i].y+1,tmp[i].c,c);
		}
		else if(tmp[i].type==4)
		{
			add(tmp[i].y,-tmp[i].c,c);
		}
	}
	top=0;
	now1=l,now2=mid+1;
	while(now1<=mid||now2<=r)
	{
		if(now1>mid)tmp[++top]=a[now2++];
		else if(now2>r)tmp[++top]=a[now1++];
		else
		{
			if(a[now1].x<=a[now2].x)tmp[++top]=a[now1++];
			else tmp[++top]=a[now2++];
		}
	}
	for(int i=1;i<=top;i++)
		a[l+i-1]=tmp[i];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int dir,x,y,len;
			scanf("%d%d%d%d",&dir,&x,&y,&len);
			if(dir==1)
			{
				a[++tot]=Node(1,i,x,y+len,1);
				if(x+len+1<=n&&y-1>=1)a[++tot]=Node(1,i,x+len+1,y-1,-1);
				if(y-1>=1)a[++tot]=Node(3,i,x,y-1,-1);
				if(x+len+1<=n&&y-1>=1)a[++tot]=Node(3,i,x+len+1,y-1,1);
			}
			if(dir==2)
			{
				a[++tot]=Node(2,i,x,y-len,1);
				if(x+len+1<=n&&y+1<=n)a[++tot]=Node(2,i,x+len+1,y+1,-1);
				if(y+1<=n)a[++tot]=Node(4,i,x,y+1,-1);
				if(x+len+1<=n&&y+1<=n)a[++tot]=Node(4,i,x+len+1,y+1,1);
			}
			if(dir==3)
			{
				a[++tot]=Node(4,i,x-len,y,1);
				if(x+1<=n)a[++tot]=Node(4,i,x+1,y,-1);
				if(y+1<=n)a[++tot]=Node(2,i,x-len,y+1,-1);
				if(x+1<=n&&y+len+2<=n)a[++tot]=Node(2,i,x+1,y+len+2,1);
			}
			if(dir==4)
			{
				a[++tot]=Node(3,i,x-len,y,1);
				if(x+1<=n)a[++tot]=Node(3,i,x+1,y,-1);
				if(y-1>=1)a[++tot]=Node(1,i,x-len,y-1,-1);
				if(x+1<=n&&y-len-2>=1)a[++tot]=Node(1,i,x+1,y-len-2,1);
			}
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[++tot]=Node(0,i,x,y,0);
			flag[i]=1;
		}
	}
//	for(int i=1;i<=tot;i++)
//	{
//		printf("%d:",i);
//		printf("type=%d,id=%d,(%d,%d),c=%d\n",a[i].type,a[i].id,a[i].x,a[i].y,a[i].c);
//	}
	solve(1,tot);
	for(int i=1;i<=q;i++)
	  if(flag[i])
		printf("%d ",ans[i]);
	return 0;
}