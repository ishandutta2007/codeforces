#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
ll x, y, n, i, px, py, c[MN];
struct w{ll x, y, id;}a[MN];

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].id = i;
	}
	sort(a+1,a+n+1,[](w i,w j){return (i.x*i.x+i.y*i.y)>(j.x*j.x+j.y*j.y);});
idk:
	x = y = 0;
	for(i=1;i<=n;i++){
		ll A=sq(x+a[i].x)+sq(y+a[i].y);
		ll B=sq(x-a[i].x)+sq(y-a[i].y);
		if(rand()%100>A/(double)(A+B)*100){
			c[a[i].id] = 1;
			x+=a[i].x; y+=a[i].y;
		}
		else{
			c[a[i].id] = -1;
			x-=a[i].x; y-=a[i].y;
		}
	}
	if(sq(x)+sq(y)>sq(1.5*1e6)) goto idk;
	for(i=1;i<=n;i++)
		printf("%lld ",c[i]);
	getchar(); getchar();
}