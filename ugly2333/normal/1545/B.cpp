//CF1545B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,a[N],k,t,l,r;
int f[N],g[N];
char s[N];
int C(int x,int y){
	if(y<0||x<y)
		return 0;
	return mul(f[x],mul(g[y],g[x-y]));
}
int F(int x,int y){
	return C(x+y-1,y-1);
}
int main()
{
	int T,i,x,ans;
	n=1e5+15;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;i++)
			a[i]=s[i]-'0';
		l=n+1,r=0;
		for(i=1;i<n;i++)
			if(a[i]&&a[i+1])
				l=min(l,i),r=max(r,i+1);
		if(l>n){
			printf("1\n");
			continue;
		}
		k=0,t=0;
		x=0;
		for(i=1;i<=n;i++){
			if(!a[i]){
				k++;
				if(i%2!=x%2)
					t++;
				else
					t+=2;
				x=i;
			}
		}
		if(!k){
			printf("1\n");
			continue;
		}
		ans=F((n-t)/2,k+1);
		printf("%d\n",ans);
	}
	return 0;
}