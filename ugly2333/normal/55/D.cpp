//CF55D
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
const int N = 55;
const int M = 2520;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int lcm(int x,int y){
	if(!x||!y)
		return x+y;
	return x*y/gcd(x,y);
}
int n,c[M+11],d[N],p[N][N];
LL f[M][N],g[M][N];
void go(LL x){
	LL t=x;
	int o,e=1;
	while(t){
		o=t%10;
		e=lcm(e,o);
		t/=10;
	}
	g[x%M][c[e]]++;
}
void solve(LL x){
	int i,j,k;
	if(x<=9){
		memset(f,0,sizeof(f));
		for(i=0;i<=x;i=i+1)
			f[i][c[i]]++;
		return;
	}
	solve((x-9)/10);
	memset(g,0,sizeof(g));
	for(i=0;i<M;i=i+1)
		for(j=0;j<n;j=j+1)
			for(k=0;k<=9;k=k+1)
				g[(i*10+k)%M][p[j][k]]+=f[i][j];
	while(x%10!=9){
		go(x);
		x--;
	}
	memset(f,0,sizeof(f));
	for(i=0;i<M;i=i+1)
		for(j=0;j<n;j=j+1)
			f[i][j]+=g[i][j];
}
int main()
{
	int T,i,j,x;
	LL l,r,s;
	for(i=0;i<(1<<10);i=i+4){
		x=1;
		for(j=2;j<=9;j=j+1)
			if(i&(1<<j))
				x=lcm(x,j);
		c[x]=1;
	}
	c[0]=1;
	for(i=0;i<=M;i=i+1)
		if(c[i])
			c[i]=n,d[n]=i,n++;
	for(i=0;i<n;i=i+1)
		for(j=0;j<=9;j=j+1)
			p[i][j]=c[lcm(d[i],j)];
	cin>>T;
	while(T--){
		cin>>l>>r;
		s=0;
		solve(r);
		for(i=0;i<M;i=i+1)
			for(j=0;j<n;j=j+1)
				if(!d[j]||i%d[j]==0)
					s+=f[i][j];
		solve(l-1);
		for(i=0;i<M;i=i+1)
			for(j=0;j<n;j=j+1)
				if(!d[j]||i%d[j]==0)
					s-=f[i][j];
		cout<<s<<endl;
	}
	return 0;
}