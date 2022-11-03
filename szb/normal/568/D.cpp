#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define pa pair<ll,int>
#define maxn 100010
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOr(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll x[maxn],y[maxn],z[maxn],X[maxn],Y[maxn],Z[maxn],id[maxn],ID[maxn],cho[maxn][2],n,K,k;
map<ll,bool>mp;
ll gcd(ll a,ll b){	return b?gcd(b,a%b):a;	}
inline ll get(){	return rand()*rand();	}
bool pd(ll t1,ll t2,ll t3){
	long double pos1=(long double)(z[t1]*y[t2]-z[t2]*y[t1])/(x[t2]*y[t1]-x[t1]*y[t2]),pos2=(long double)(x[t1]*z[t2]-z[t1]*x[t2])/(y[t1]*x[t2]-x[t1]*y[t2]);
	return	fabs(x[t3]*pos1+y[t3]*pos2+z[t3])<1e-8;
}
bool pd(ll t1,ll t2){		return (x[t1]*y[t2]-x[t2]*y[t1])==0;}
void dfs(ll k,ll n){
	if (n<=k){
		puts("YES");
		writeln(K-k+n);
		For(i,k+1,K)	printf("%lld %lld\n",cho[i][0],cho[i][1]);
		For(i,1,n)	printf("%lld %lld\n",id[i],-1LL);
		exit(0);
	}
	if (k<=0)	return;	map<ll,bool>mp;
	For(tmp,1,3*k+3){
		ll xx=1,yy=3,L=1,R=n,now=0;
		if (xx>yy)	swap(xx,yy);
		while(xx==yy||pd(xx,yy)||mp[xx*100001+yy]){	xx=get()%n+1,yy=get()%n+1;	if (xx>yy)	swap(xx,yy);if (++now>100)	return;	}
		cho[k][0]=id[xx];	cho[k][1]=id[yy];
		For(j,1,n)	if (!pd(xx,yy,j))	X[L]=x[j],Y[L]=y[j],Z[L]=z[j],ID[L]=id[j],L++;
		else	X[R]=x[j],Y[R]=y[j],Z[R]=z[j],ID[R]=id[j],R--;
		For(i,1,n)	x[i]=X[i],y[i]=Y[i],z[i]=Z[i],id[i]=ID[i];
		if ((n-R)*k>=n)	dfs(k-1,L-1);	mp[xx*100001+yy]=1;
	}
}
int main(){
	srand(time(0));
	n=read();	K=k=read();	ll tt=0;
	For(i,1,n){
		++tt;
		x[i]=read(),y[i]=read(),z[i]=read(),id[i]=tt;
		if (x[i]<0)	x[i]=-x[i],y[i]=-y[i],z[i]=-z[i];
		ll t=abs(gcd(gcd(x[i],y[i]),z[i]));
		x[i]/=t;	y[i]/=t;	z[i]/=t;
		if (mp[x[i]*100001*100001+y[i]*100001+z[i]])	i--,n--;
		mp[x[i]*100001*100001+y[i]*100001+z[i]]=1;
	}
	dfs(k,n);	puts("NO");
}