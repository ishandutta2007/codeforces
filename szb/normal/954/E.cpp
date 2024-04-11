#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
inline void write(ll x){
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
inline void writeln(ll x){
	write(x); putchar('\n');
}

const ll N = 200005;
const ld eps = 1e-6;
ll n,T;
ll totT,totx;
ll now;
ld pos;
struct node{
	ll a,t;
	friend bool operator <(node a,node b){
		return a.t < b.t;
	}
}x[N];

signed main(){
	n = read(); T = read();
	for(ll i = 1;i <= n;++i) x[i].a = read();
	for(ll j = 1;j <= n;++j) x[j].t = read();
	sort(x+1,x+n+1);
	for(ll i = 1;i <= n;++i){
		totT += x[i].a*(x[i].t-T);
		totx += x[i].a;
	}
	if(totT < 0){
		for(int i = 1;i <= n;++i)
			if(x[i].t-T != 0){
				pos = 1.0*totT/(x[i].t-T);
				if(pos <= x[i].a){
					break;
				} else totx -= x[i].a,totT -= x[i].a*(x[i].t-T);
				pos = 0;
			}
	}else{
		for(int i = n;i >= 1;--i)
			if(x[i].t-T != 0){
				pos = 1.0*totT/(x[i].t-T);
				if(pos <= x[i].a){
					break;
				}else totx -= x[i].a,totT -= x[i].a*(x[i].t-T);
				pos = 0;
			}
	}
	printf("%.15lf\n",(double)(totx-pos));
	return 0;
}