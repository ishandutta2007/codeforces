#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int num[120];
int Rev(int x)
{
	int t=0;
	while(x>0)
	{
		num[t++]=x%10;x/=10;
	}
	int sum=0;
	for(int i=0;i<t;i++)
	{
		sum*=10;
		sum+=num[i];
	}
	return sum;
}
struct Np
{
	int x,y;
}q[1500000];
bool cmp(const Np &x,const Np &y)
{
	if(x.y==y.y)return x.x>y.x;
	return x.y<y.y;
}
struct D
{
	int x,y;
	double va;
}d[150000];
const double eps=1e-13;
double Ab(double x)
{if(x<0.0)return -x;return x;}
bool Eq(double x,double y)
{
	if(Ab(x-y)<eps)return true;
	return false;
}
bool cmp2(const D &x,const D &y)
{
	if(Eq(x.va,y.va))return x.x>y.x;
	return x.va<y.va;
}
int Cal(int x,int y)
{
	int t=0;
	int gs=max(x,y);int i;
	for(i=1;i<=gs;i++)
	{
		d[i-1].x=i;
		d[i-1].y=Rev(i);
		d[i-1].va=(double)i/(double)Rev(i);
	}
	sort(d,d+gs,cmp2);
//	for(i=0;i<gs;i++)printf("%d %d %d %.3f\n",i,d[i].x,d[i].y,d[i].va);
	for(i=0;i<gs;i++)
	{
		if(d[i].x>x)continue;
		int nx,ny;
		int tx,ty;
		nx=d[i].x;
		ny=d[i].y;
		int lo,up,mid;
		lo=0;up=gs;
		while(lo+1<up)
		{
			mid=(lo+up)/2;
			if(d[i].va*d[mid].va>1.0+eps)up=mid;
			else lo=mid;
		}
	//	printf("%d %d %d %d %d %d\n",i,nx,ny,lo,d[lo].x,d[lo].y);
		for(int j=lo;j>=0;j--)
		{
			tx=d[j].x;
			ty=d[j].y;
			if(tx>y||d[i].va*d[j].va>1.0+eps)break;			
			else 
			{
				if((LL)tx*(LL)nx==(LL)ny*(LL)ty)
				{
					q[t].x=nx;
					q[t].y=tx;
					t++;
				}
				else break;
			}
		}
	}
	sort(q,q+t,cmp);
	return t;
}
int tree[150000];
int N;
void init()
{
	for(int i=1;i<=N;i++)tree[i]=0;
}
int read(int k)
{
	int sum=0;
	while(k)
	{
		sum+=tree[k];
		k-=k&-k;
	}
	return sum;
}
void update(int k,int v)
{
	while(k<=N)
	{
		tree[k]+=v;
		k+=k&-k;
	}
}
int n,m,w,i,x,y,po;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&w))
	{
		int num=Cal(n,m);N=n;
		init();po=n;x=n+1;y=m+1;
	//	printf("%d\n",num);
	//	for(i=0;i<num;i++)printf("%d %d  ",q[i].x,q[i].y);puts("");
		for(i=0;i<num;i++)
		{
			update(q[i].x,1);//puts("OK");
		//	printf("%d %d\n",i,po);
			while(po>=1&&read(po)>=w)
			{
				if((LL)x*(LL)y>(LL)q[i].y*(LL)po)
				{
					x=po;y=q[i].y;
				}
				po--;
			}
		}
		if(x==n+1&&y==m+1)puts("-1");
		else printf("%d %d\n",x,y);
	}
}