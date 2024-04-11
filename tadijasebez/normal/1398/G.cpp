#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int mul_inv(int x){ return powmod(x,mod-2);}
void fft(int a[], int n, bool inv)
{
	for(int i=1,j=0;i<n;i++)
	{
		int k=n;do j^=k>>=1; while(~j&k);
		if(j>i) swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1)
	{
		int ang=powmod(3,(mod-1)/j);
		if(inv) ang=mul_inv(ang);
		for(int i=0;i<n/j;i++)
		{
			int cur=1;
			for(int k=i*j;k<i*j+j/2;k++)
			{
				int tmp=mul(cur,a[k+j/2]);
				a[k+j/2]=sub(a[k],tmp);
				a[k]=add(a[k],tmp);
				cur=mul(cur,ang);
			}
		}
	}
	int m=mul_inv(n);
	if(inv) for(int i=0;i<n;i++) a[i]=mul(a[i],m);
}
const int N=1<<19;
int a[N],b[N],c[N];
int can[N<<2];
int main(){
	int n,x,y;
	scanf("%i %i %i",&n,&x,&y);
	for(int i=1;i<=n+1;i++){
		int tmp;
		scanf("%i",&tmp);
		a[tmp]=1;
		b[x-tmp]=1;
	}
	fft(a,N,0);
	fft(b,N,0);
	for(int i=0;i<N;i++)a[i]=mul(a[i],b[i]);
	fft(a,N,1);
	for(int i=x+1;i<N;i++)c[i-x]=a[i]>0;
	for(int i=1;i<N;i++)if(c[i]){
		int len=i*2+y*2;
		can[len]=1;
	}
	int q;
	scanf("%i",&q);
	while(q--){
		int o,ans=-1;
		scanf("%i",&o);
		for(int i=1;i*i<=o;i++)if(o%i==0){
			if(can[i])ans=max(ans,i);
			if(can[o/i])ans=max(ans,o/i);
		}
		printf("%i ",ans);
	}
	return 0;
}