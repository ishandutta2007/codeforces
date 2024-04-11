#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double Pi=acos(-1.0);
struct Complex
{
	double x,y;
	Complex(double xx=0,double yy=0){x=xx,y=yy;}
	Complex operator+(Complex b){return Complex(x+b.x,y+b.y);}
	Complex operator-(Complex b){return Complex(x-b.x,y-b.y);}
	Complex operator*(double d){return Complex(x*d,y*d);}
	Complex operator/(double d){return Complex(x/d,y/d);}
	Complex operator*(Complex b){return Complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[1000005],B[1000005];
struct Edge
{
	int to;
	int nxt;
	double cost;
}e[205];
int n,m,t,edgenum,head[105];
double x,f[55][60005],g[105][60005],p[105][40005],dis[105][105];
int limit,L,R[1000005];
void add(int u,int v,double c)
{
	e[++edgenum].cost=c;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void FFT(Complex*A,int type)
{
	for(int i=0;i<limit;i++)
	  if(i<R[i])swap(A[i],A[R[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		Complex Wn(cos(Pi/mid),sin(Pi/mid));
		for(int R=mid<<1,j=0;j<limit;j+=R)
		{
			Complex w(1,0);
			for(int k=0;k<mid;k++,w=w*Wn)
			{
				Complex x=A[j+k];
				Complex y=A[j+mid+k]*w;
				A[j+k]=x+y;
				A[j+mid+k]=x-y;
			}
		}
	}
	if(type==-1)
	{
		for(int i=0;i<limit;i++)A[i]=A[i]/limit;
		for(int i=1;i<(limit>>1);i++)swap(A[i],A[limit-i]);
	}
}
void solve(int l,int r)
{
	if(l>t)return;
	if(l==r)
	{
//		printf("solve(%d,%d):\n",l,r);
		if(l==2*t)return;
//		printf("f:");
		for(int i=1;i<n;i++)
		{
			f[i][l]=1e18;
			for(int hd=head[i];hd;hd=e[hd].nxt)
			  f[i][l]=min(f[i][l],g[hd][l]+e[hd].cost);
//			printf("%lf ",f[i][l]);
		}
//		printf("\n");
		return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
//	printf("solve(%d,%d):\n",l,r);
//	printf("g:\n");
	for(int i=1;i<=m;i++)
	{
		int v=e[i].to;
//		printf("%d,to=%d:\n",i,v);
//		for(int j=mid+1;j<=r;j++)printf("%lf ",f[v][j]);
//		printf("\n");
//		for(int j=1;j<=t;j++)printf("%lf ",p[i][j]);
//		printf("\n");
		limit=1,L=0;
		while(limit<r-l+r-mid)limit<<=1,L++;
		for(int j=0;j<limit;j++)
		{
			R[j]=(R[j>>1]>>1)|((j&1)<<(L-1));
			A[j]=B[j]=Complex(0,0);
		}
		for(int j=mid+1;j<=r;j++)
		  A[j-mid-1]=Complex(f[v][j],0);
		for(int j=1;j<=r-l;j++)
		  B[r-l-j]=Complex(p[i][j],0);
//		printf("A:");
//		for(int j=0;j<limit;j++)printf("%lf ",A[j].x);
//		printf("\n");
//		printf("B:");
//		for(int j=0;j<limit;j++)printf("%lf ",B[j].x);
//		printf("\n");
		FFT(A,1);
		FFT(B,1);
		for(int j=0;j<limit;j++)A[j]=A[j]*B[j];
		FFT(A,-1);
//		printf("C:");
//		for(int j=0;j<limit;j++)printf("%lf ",A[j].x);
//		printf("\n");
		for(int j=l;j<=mid;j++)
		  g[i][j]+=A[j-mid+r-l-1].x;
//		for(int j=l;j<=mid;j++)printf("%lf ",g[i][j]);
//		printf("\n");
	}
	solve(l,mid);
}
int main()
{
	scanf("%d%d%d%lf",&n,&m,&t,&x);
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    dis[i][j]=dis[j][i]=1e18;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		double c;
		scanf("%d%d%lf",&a,&b,&c);
		add(a,b,c);
		dis[a][b]=min(dis[a][b],c);
		for(int j=1;j<=t;j++)
		{
			scanf("%lf",&p[i][j]);
			p[i][j]/=100000;
		}
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
	  for(int j=t+1;j<=2*t;j++)
	    f[i][j]=dis[i][n]+x;
	solve(0,2*t);
	printf("%.12lf\n",f[1][0]);
	return 0;
}