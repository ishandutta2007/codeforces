#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define ld long double

const int N = 1e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

ll n,l;
ll a[N+5];
ld t1[N+5],t2[N+5];

void solve(){
	n = read(),l = read();
	for(rg int i = 1;i <= n;i++)a[i] = read();
	a[0] = 0,a[n+1] = l;
	t1[0] = 0; for(rg int i = 1;i <= n + 1;i++)t1[i] = t1[i-1] + 1.0 * (a[i] - a[i-1]) / i;
//for(rg int i = 0;i <= n + 1;i ++)printf("%.12Lf ",t1[i]); cout<<endl;
	t2[n+1] = 0;for(rg int i = 1;i <= n + 1;i++)t2[n-i+1] = t2[n-i+2] + 1.0 * (a[n-i+2] - a[n-i+1]) / i;
//for(rg int i = 0;i <= n + 1;i ++)printf("%.12Lf ",t2[i]); cout<<endl;
	int p = 0;
	while(t1[p] < t2[p] && p <= n)p++; //its between a[p-1] & a[p]
	ld x = 1.0 * (a[p] - a[p-1] + p * t1[p-1] + (n + 2 - p) * t2[p]) / (n + 2);
	double ans = x;
	printf("%.9lf\n",ans);
//	printf("%.18Lf\n",x);	
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	
//duo ce bu qing kong, bao ling liang hang lei !!!
	int T = read();
	while(T--)solve();
	
	return 0;
}