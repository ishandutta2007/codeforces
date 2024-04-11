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
const int N=125050;
const int M=500050;
int a[6][M],b[6][M],tmp[M];
int n,m,sz;
char s[N],t[N];
struct DSU
{
	int p[6];
	void init(){ for(int i=0;i<6;i++) p[i]=i;}
	DSU(){ init();}
	int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
	void Union(int x, int y){ p[Find(x)]=Find(y);}
	int Get(){ int ans=6;for(int i=0;i<6;i++) if(p[i]==i) ans--;return ans;}
} DS[N];
int main()
{
	scanf("%s %s",s,t);
	n=strlen(s);m=strlen(t);
	for(int c=0;c<6;c++) for(int i=0;i<n;i++) a[c][i]=s[i]=='a'+c;
	for(int c=0;c<6;c++) for(int i=0;i<m;i++) b[c][m-i-1]=t[i]=='a'+c;
	sz=1;while(sz<n) sz<<=1;sz<<=1;
	for(int c=0;c<6;c++) fft(a[c],sz,0),fft(b[c],sz,0);
	for(int c=0;c<6;c++) for(int d=0;d<6;d++) if(c!=d)
	{
		for(int i=0;i<sz;i++) tmp[i]=mul(a[c][i],b[d][i]);
		fft(tmp,sz,1);
		for(int i=m-1;i<n;i++) if(tmp[i]>0) DS[i-m+1].Union(c,d);
	}
	for(int i=0;i<n-m+1;i++) printf("%i ",DS[i].Get());
	return 0;
}