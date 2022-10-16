#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int a[N],b[N];
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
double solve(double c,double m,double p,double v)
{
	double ret=0;
	if (c<eps && m<eps) return 1;
	if (c<eps) 
	{
		if (m<=v) return p+m*2;
		else return p+m*(1+solve(0,m-v,p+v,v));
	}
	if (m<eps)
	{
		if (c<=v) return p+c*2;
		else return p+c*(1+solve(c-v,0,p+v,v));
	}
	ret+=p;
	if (m<=v+eps) ret+=m*(1+solve(c+m/2,0,p+m/2,v));
	else ret+=m*(1+solve(c+v/2,m-v,p+v/2,v));
	if (c<=v+eps) ret+=c*(1+solve(0,m+c/2,p+c/2,v));
	else ret+=c*(1+solve(c-v,m+v/2,p+v/2,v));
	return ret;
}
double c,m,p,v;
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
		cin>>c>>m>>p>>v;
		printf("%.9lf\n",solve(c,m,p,v));

    }
}
/*
5.030718829
5.005050776521
*/