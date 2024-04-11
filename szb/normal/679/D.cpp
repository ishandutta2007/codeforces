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
#define ll int
#define maxn 510
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll q[maxn],dis[maxn][maxn],n,m;
double c[maxn],v[maxn],ans;
int main(){
	n=read();	m=read();
	For(i,1,n)	For(j,1,n)	dis[i][j]=i==j?0:n+1;
	For(i,1,m){
		ll a=read(),b=read();
		dis[a][b]=dis[b][a]=1;
	}
	For(k,1,n)	For(i,1,n)	For(j,1,n)	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	For(i,1,n){
		double now=0;
		For(j,0,n-1){
			memset(v,0,sizeof v);	double s=0;	ll u=0,tot=0;
			For(k,1,n)	if (dis[i][k]==j){
				ll sz=0;	u++;
				For(l,1,n)	sz+=dis[k][l]==1;
				For(l,1,n)	if (dis[k][l]==1)	v[l]+=1.0/sz;
			}
			For(k,1,n)	if (abs(dis[i][k]-j)<2)	q[++tot]=k;
			For(k,1,n){
				double w=0;
				For(l,1,tot)	c[dis[k][q[l]]]=max(c[dis[k][q[l]]],v[q[l]]);
				For(l,1,tot)	w+=c[dis[k][q[l]]],c[dis[k][q[l]]]=0;
				s=max(s,w);
			}
			if (u)	s=max(s,1.0);	now+=s/n;
		}ans=max(ans,now);
	}printf("%.10lf",ans);
}
/*
3 3
1 2
1 3
2 3
*/