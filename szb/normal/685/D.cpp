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
#define maxn 200010
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
struct data{	ll x,y,z;	}p[3000010];
bool operator<(data a,data b){	return a.x<b.x;	}
long long c[300000];
ll d[300000],e[300000],z[300000],i,j,l,r,m,n,w,x,y;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%d%d",&x,&y),z[i]=y,z[n+i]=y-m;
		p[i]=(data){x-m,y,1},p[n+i]=(data){x,y,-1};
	}
	w=2*n;
	sort(z+1,z+w+1);
	w=unique(z+1,z+w+1)-z-1;
	sort(p+1,p+2*n+1);
	For(i,1,2*n){
		l=lower_bound(z+1,z+w+1,p[i].y-m)-z;
		r=lower_bound(z+1,z+w+1,p[i].y)-z;
		For(j,l+1,r){
			c[e[j]]=c[e[j]]+1LL*(z[j]-z[j-1])*(p[i].x-d[j]);
			d[j]=p[i].x;
			e[j]=e[j]+p[i].z;
		}
	}
	For(i,1,n)	printf("%I64d ",c[i]);
}