#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const double pi=acos(-1);
struct comp
{
	double x,y;
	comp(){x=y=0;}
	comp(double _x,double _y){x=_x,y=_y;}
	inline comp operator+(const comp c){return comp(x+c.x,y+c.y);}
	inline comp operator-(const comp c){return comp(x-c.x,y-c.y);}
	inline comp operator*(const comp c){return comp(x*c.x-y*c.y,x*c.y+y*c.x);}
}a[N],b[N],p[N];
int r[N],n,m,k,x=1,y,c[N],ans;
char s[N],t[N];
void fft(int n,comp *a,int v)
{
	for(int i=0;i<n;i++)
		if(i<r[i])
			swap(a[i],a[r[i]]);
	for(int m=1;m<n;m<<=1)
	{
		comp x(cos(pi/m),v*sin(pi/m));
		for(int j=0;j<n;j+=m<<1)
		{
			comp y(1,0);
			for(int k=0;k<m;k++)
			{
				comp t=y*a[j+m+k];
				a[j+m+k]=a[j+k]-t;
				a[j+k]=a[j+k]+t;
				y=y*x;
			}
		}
	}
}
void sol(char q)
{
	int l=-1e9;
	for(int i=0;i<x;i++)
		a[i]=comp(0,0),b[i]=comp(0,0);
	for(int i=0;i<n;i++)
	{
		if(s[i]==q)
			l=i;
		if((i-l)<=k)
			a[i]=comp(1,0);
	}
	l=1e9;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==q)
			l=i;
		if((l-i)<=k)
			a[i]=comp(1,0);
	}
	for(int i=0;i<m;i++)
		if(t[i]==q)
			b[m-i-1]=comp(1,0);
	fft(x,a,1);
	fft(x,b,1);
	for(int i=0;i<x;i++)
		a[i]=a[i]*b[i];
	fft(x,a,-1);
	for(int i=0;i<n;i++)
		c[i]+=int(a[i].x/x+0.5);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s,t);
	while(x<=n+m)
		x*=2,y++;
	for(int i=0;i<x;i++)
		r[i]=(r[i>>1]>>1)|((i&1)<<(y-1));
	sol('A'),sol('C'),sol('G'),sol('T');
	for(int i=0;i<n;i++)
		if(c[i]==m)
			ans++;
	printf("%d\n",ans);
	return 0;
}