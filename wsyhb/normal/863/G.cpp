#include<bits/stdc++.h>
using namespace std;
#define DirR 0
#define DirL 1
#define DirD 2
#define DirU 3
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int m,a[8],b[8];
const int max_size=1e5+5;
int w[max_size][8],g[max_size];
#define w(x,y,z) w[(y-1)*a[1]+(x-1)][z-1]
#define g(x,y) g[(y-1)*a[1]+(x-1)]
int N,M;
bool flag_even;
void init()
{
	for(int i=m+1;i<=6;++i)
		a[i]=b[i]=1;
	for(int i=1;i<=a[6];++i)
		for(int j=1;j<=a[5];++j)
			for(int k=1;k<=a[4];++k)
				for(int p=1;p<=a[3];++p)
					for(int q=1;q<=a[2];++q)
					{
						int y=(i-1)*a[5]*a[4]*a[3]*a[2]+(j-1)*a[4]*a[3]*a[2]+(k-1)*a[3]*a[2]+(p-1)*a[2]+q; 
						for(int x=1;x<=a[1];++x)
						{
							w(x,y,1)=x;
							w(x,y,2)=((i-1)*a[5]*a[4]*a[3]+(j-1)*a[4]*a[3]+(k-1)*a[3]+p)&1?q:a[2]-q+1;
							w(x,y,3)=((i-1)*a[5]*a[4]+(j-1)*a[4]+k)&1?p:a[3]-p+1;
							w(x,y,4)=((i-1)*a[5]+j)&1?k:a[4]-k+1;
							w(x,y,5)=i&1?j:a[5]-j+1;
							w(x,y,6)=i; 
						}
					}
	N=a[1],M=a[2]*a[3]*a[4]*a[5]*a[6];
}
inline void walk(int x,int y,int tx,int ty)
{
	for(int i=1;i<=m;++i)
	{
		if(w(x,y,i)!=w(tx,ty,i))
		{
			if(w(x,y,i)<w(tx,ty,i))
				printf("inc %d\n",i);
			else
				printf("dec %d\n",i);
			return;
		}
	}
}
inline void work_LU_H(int lx,int rx,int ly,int ry)
{
	for(int i=lx;i<=rx;i+=2)
	{
		for(int j=ly;j<ry;++j)
			g(i,j)=DirR;
		g(i,ry)=DirD;
	}
	for(int i=lx+1;i<=rx;i+=2)
	{
		for(int j=ry;j>ly;--j)
			g(i,j)=DirL;
		g(i,ly)=DirD;
	}
}
inline void work_LU_V(int lx,int rx,int ly,int ry)
{
	for(int j=ly;j<=ry;j+=2)
	{
		for(int i=lx;i<rx;++i)
			g(i,j)=DirD;
		g(rx,j)=DirR;
	}
	for(int j=ly+1;j<=ry;j+=2)
	{
		for(int i=rx;i>lx;--i)
			g(i,j)=DirU;
		g(lx,j)=DirR;
	}
}
inline void work_RU_H(int lx,int rx,int ly,int ry)
{
	for(int i=lx;i<=rx;i+=2)
	{
		for(int j=ry;j>ly;--j)
			g(i,j)=DirL;
		g(i,ly)=DirD;
	}
	for(int i=lx+1;i<=rx;i+=2)
	{
		for(int j=ly;j<ry;++j)
			g(i,j)=DirR;
		g(i,ry)=DirD; 
	}
}
inline void work_RU_V(int lx,int rx,int ly,int ry)
{
	for(int j=ry;j>=ly;j-=2)
	{
		for(int i=lx;i<rx;++i)
			g(i,j)=DirD;
		g(rx,j)=DirL;
	}
	for(int j=ry-1;j>=ly;j-=2)
	{
		for(int i=rx;i>lx;--i)
			g(i,j)=DirU;
		g(lx,j)=DirL; 
	}
}
inline void work_LD_H(int lx,int rx,int ly,int ry)
{
	for(int i=rx;i>=lx;i-=2)
	{
		for(int j=ly;j<ry;++j)
			g(i,j)=DirR;
		g(i,ry)=DirU;
	}
	for(int i=rx-1;i>=lx;i-=2)
	{
		for(int j=ry;j>ly;--j)
			g(i,j)=DirL;
		g(i,ly)=DirU;
	}
}
inline void work_LD_V(int lx,int rx,int ly,int ry)
{
	for(int j=ly;j<=ry;j+=2)
	{
		for(int i=rx;i>lx;--i)
			g(i,j)=DirU;
		g(lx,j)=DirR;
	}
	for(int j=ly+1;j<=ry;j+=2)
	{
		for(int i=lx;i<rx;++i)
			g(i,j)=DirD;
		g(rx,j)=DirR;
	}
}
inline void work_RD_H(int lx,int rx,int ly,int ry)
{
	for(int i=rx;i>=lx;i-=2)
	{
		for(int j=ry;j>ly;--j)
			g(i,j)=DirL;
		g(i,ly)=DirU;
	}
	for(int i=rx-1;i>=lx;i-=2)
	{
		for(int j=ly;j<ry;++j)
			g(i,j)=DirR;
		g(i,ry)=DirU;
	}
}
inline void work_RD_V(int lx,int rx,int ly,int ry)
{
	for(int j=ry;j>=ly;j-=2)
	{
		for(int i=rx;i>lx;--i)
			g(i,j)=DirU;
		g(lx,j)=DirL; 
	}
	for(int j=ry-1;j>=ly;j-=2)
	{
		for(int i=lx;i<rx;++i)
			g(i,j)=DirD;
		g(rx,j)=DirL;
	}
}
void work()
{
	if(m==1)
	{
		if(a[1]==2)
		{
			puts("Cycle");
			if(b[1]==1)
			{
				puts("inc 1");
				puts("dec 1");
			}
			else
			{
				puts("dec 1");
				puts("inc 1");
			}
		}
		else if(b[1]==1)
		{
			puts("Path");
			for(int i=1;i<=a[1]-1;++i)
				puts("inc 1");
		}
		else if(b[1]==a[1])
		{
			puts("Path");
			for(int i=1;i<=a[1]-1;++i)
				puts("dec 1");
		}
		else
			puts("No");
		return;
	}
	init();
	int x=b[1],y=-1;
	for(int i=1;i<=M;++i)
	{
		if(w(x,i,2)==b[2]&&w(x,i,3)==b[3]&&w(x,i,4)==b[4]&&w(x,i,5)==b[5]&&w(x,i,6)==b[6])
		{
			y=i;
			break;
		}
	}
	if(flag_even)
	{
		puts("Cycle");
		if(M&1)
		{
			g(1,1)=DirR;
			work_LU_H(1,N,2,M);
			g(N,2)=DirL;
			for(int i=N;i>=2;--i)
				g(i,1)=DirU;
		}
		else
		{
			g(1,1)=DirD;
			work_LU_V(2,N,1,M);
			g(2,M)=DirU;
			for(int i=M;i>=2;--i)
				g(1,i)=DirL;
		}
		for(int i=1;i<=N*M;++i)
		{
			int tx=x+dx[g(x,y)],ty=y+dy[g(x,y)];
			walk(x,y,tx,ty);
			x=tx,y=ty;
		}
	}
	else
	{
		if((x^y)&1)
		{
			puts("No");
			return;
		}
		puts("Path");
		if(x==1)
		{
			work_RU_H(1,N-1,1,y);
			g(N-1,y)=DirR;
			work_LD_V(1,N-1,y+1,M);
			g(N-1,M)=DirD;
			for(int i=M;i>=2;--i)
				g(N,i)=DirL;
		}
		else if(x==N)
		{
			work_RD_H(2,N,1,y);
			g(2,y)=DirR;
			work_LU_V(2,N,y+1,M);
			g(2,M)=DirU;
			for(int i=M;i>=2;--i)
				g(1,i)=DirL;
		}
		else if(y==1)
		{
			work_LD_V(1,x,1,M-1);
			g(x,M-1)=DirD;
			work_RU_H(x+1,N,1,M-1);
			g(N,M-1)=DirR;
			for(int i=N;i>=2;--i)
				g(i,M)=DirU;
		}
		else if(y==M)
		{
			work_RD_V(1,x,2,M);
			g(x,2)=DirD;
			work_LU_H(x+1,N,2,M);
			g(N,2)=DirL;
			for(int i=N;i>=2;--i)
				g(i,1)=DirU;
		}
		else if(x&1)
		{
			for(int i=x;i>=2;--i)
				g(i,y)=DirU;
			g(1,y)=DirL;
			work_RU_H(1,x,1,y-1);
			g(x,1)=DirD;
			work_LU_V(x+1,N,1,y);
			g(N,y)=DirR;
			work_LD_V(1,N,y+1,M);
		}
		else
		{
			work_RD_V(1,x,1,y);
			g(x,1)=DirD;
			work_LU_H(x+1,N,1,y);
			g(N,y)=DirR;
			work_LD_V(1,N,y+1,M);
		}
		for(int i=1;i<=N*M-1;++i)
		{
			int tx=x+dx[g(x,y)],ty=y+dy[g(x,y)];
			walk(x,y,tx,ty);
			x=tx,y=ty;
		}
	}
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",a+i);
		flag_even|=!(a[i]&1);
	}
	for(int i=1;i<=m;++i)
		scanf("%d",b+i);
	work();
	return 0;
}