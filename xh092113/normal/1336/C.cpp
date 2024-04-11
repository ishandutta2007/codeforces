#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3000;
const ll mod = 998244353;

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
}
using namespace IO;

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;
	}
	In ll Add(ll x,ll y){
		Inc(x,y);return x;
	}
	In ll Sub(ll x,ll y){
		Dec(x,y);return x;
	}
}
using namespace ModCalc;

char s[N+5],t[N+5];
int n,m;
ll f[N+5][N+5],g[N+5][N+5];
ll v[N+5];

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	scanf("%s",s + 1);n = strlen(s + 1);
	scanf("%s",t + 1);m = strlen(t + 1);
	for(rg int i = 1;i <= n;i++)if(s[i] == t[1])f[1][i] = n - i + 1;
	for(rg int i = 2;i <= m;i++){
		ll sum = 0;
		for(rg int j = n;j >= 1;j--){
			if(s[j] == t[i])f[i][j] = sum;
			Inc(sum,f[i-1][j]);
		}
	}
/*for(rg int i = 1;i <= m;i++){
	for(rg int j = 1;j <= n;j++)cout<<f[i][j]<<" ";cout<<endl;
}*/	
	v[0] = 1;
	for(rg int i = 1;i <= N;i++)v[i] = v[i-1] * 2 % mod;
	ll ans1 = 0;
	for(rg int x = 2;x <= n;x++)Inc(ans1,v[x-1] * f[m][x] % mod);
//cout<<ans1<<endl;
	for(rg int i = 1;i <= m;i++)if(t[i] == s[1])g[i][i] = 2;
	for(rg int i = 2;i <= m;i++){
		for(rg int l = 1;l + i - 1 <= m;l++){
			int r = l + i - 1;
			if(t[l] == s[i])Inc(g[l][r],g[l+1][r]);
			if(t[r] == s[i])Inc(g[l][r],g[l][r-1]);
		}
	}
/*for(rg int i = 1;i <= m;i++){
	for(rg int j = i;j <= m;j++)cout<<g[i][j]<<" ";cout<<endl;
}*/
	ll ans2 = g[1][m] * (n - m + 1) % mod;
	for(rg int i = 2;i <= m;i++)
		for(rg int j = m - i + 3;j <= n;j++)Inc(ans2,g[i][m] * f[i-1][j] % mod);
	write(Add(ans1,ans2));putchar('\n');
 	return 0;
}