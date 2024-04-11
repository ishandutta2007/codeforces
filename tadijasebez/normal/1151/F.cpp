#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=105;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
int dvd(int x, int y){ return mul(x,inv(y));}
struct Matrix
{
	int a[N][N];
	Matrix(){}
	Matrix operator * (Matrix b)
	{
		Matrix ans;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				ans.a[i][j]=0;
				for(int k=0;k<N;k++)
				{
					ans.a[i][j]=add(ans.a[i][j],mul(a[i][k],b.a[k][j]));
				}
			}
		return ans;
	}
};
int a[N],b[N],p[N];
int Get(int x){ return dvd(mul(x,x-1),2);}
int main()
{
    int n,k,i,j,cnt=0;
    scanf("%i %i",&n,&k);
    for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt+=a[i];
    Matrix base;
    int all=inv(Get(n));
    //int swsm=add(Get(cnt),Get(n-cnt));
    for(i=0;i<=cnt;i++) for(j=0;j<=cnt;j++)
	{
		if(i==j) base.a[i][j]=mul(all,add(Get(cnt),add(Get(n-cnt),add(mul(i,cnt-i),mul(cnt-i,max(n-2*cnt+i,0))))));
		else if(j==i+1) base.a[i][j]=mul(all,mul(cnt-i,cnt-i));
		else if(j==i-1) base.a[i][j]=mul(all,mul(i,max(n-cnt-(cnt-i),0)));
		else base.a[i][j]=0;
	}
	//for(i=0;i<=cnt;i++) for(j=0;j<=cnt;j++) printf("%i%c",base.a[i][j],j==cnt?'\n':' ');
	Matrix ans;
    for(i=0;i<=cnt;i++) ans.a[i][i]=1;
    for(;k;k>>=1,base=base*base) if(k&1) ans=ans*base;
    //for(i=0;i<=cnt;i++) for(j=0;j<=cnt;j++) printf("%i%c",ans.a[i][j],j==cnt?'\n':' ');
    int o=0;
    for(i=n;i>=n-cnt+1;i--) o+=a[i];
    p[o]=1;
    for(i=0;i<=cnt;i++) for(j=0;j<=cnt;j++)
	{
		b[i]=add(b[i],mul(ans.a[j][i],p[j]));
	}
	printf("%i\n",b[cnt]);
	//for(i=0;i<=cnt;i++) printf("%i ",b[i]);printf("\n");
	//for(i=0;i<=cnt;i++) printf("%i ",p[i]);printf("\n");
	return 0;
}