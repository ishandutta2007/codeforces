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
#define llu unsigned long long
#define maxn 510
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll seed,n,m,Q;
unsigned long long hsh[2510][2510],now;
ll get(){	return 1LL*rand()<<12|rand()<<12|rand()<<12|rand();}
void add(ll x,ll y,llu v){
	for(ll i=x;i;i-=i&-i)
	for(ll j=y;j;j-=j&-j)	hsh[i][j]^=v;
}
llu get(ll x,ll y){
	ll ans=0;
	for(ll i=x;i<=n;i+=i&-i)
	for(ll j=y;j<=m;j+=j&-j)	ans^=hsh[i][j];
	return ans;
}
int main(){
	srand(time(0));
	n=read();	m=read();	Q=read();	seed=get();
	while(Q--){
		ll opt=read(),x1=read(),y1=read(),x2=read(),y2=read();
		now=x1;	now=now*seed+x2;	now=now*seed+y1;	now=now*seed+y2;
		if (opt==1||opt==2)	add(x1-1,y1-1,now),add(x2,y2,now),add(x1-1,y2,now),add(x2,y1-1,now);
		if (opt==3)	puts(get(x1,y1)^get(x2,y2)?"No":"Yes");
	}
}
/*
5 6 5
1 2 2 4 5
1 3 3 3 3
3 4 4 1 1
2 2 2 4 5
3 1 1 4 4
*/