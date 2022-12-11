#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=1e5+5;
int a[max_n];
double lt[max_n],rt[max_n];
const double eps=1e-7;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l;
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		a[n+1]=l;
		lt[0]=lt[n+1]=rt[0]=rt[n+1]=0;
		for(int i=1;i<=n;++i)
			lt[i]=lt[i-1]+1.0*(a[i]-a[i-1])/i;
		for(int i=n;i>=1;--i)
			rt[i]=rt[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
		double L=0,R=l,mid,res;
		while(R-L>eps)
		{
			mid=(L+R)*0.5;
			int x=upper_bound(a+1,a+n+2,mid)-a;
			double time_l=lt[x-1]+(mid-a[x-1])/x;
			double time_r=rt[x]+(a[x]-mid)/(n-x+2);
			if(time_l-time_r>eps) R=mid-eps;
			else L=mid+eps,res=time_l;
		}
		printf("%.10lf\n",res);
	}
	return 0;
}
/*
1
2 1000000000
413470354 982876160
*/