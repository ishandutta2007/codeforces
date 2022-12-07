#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;
const ll mod = 998244353;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

ll v10[N+5];
ll ans[N+5];

int main(){
//	freopen("E.in","r",stdin);
	int n = read();
	v10[0] = 1;
	for(rg int i = 1;i <= n;i++)v10[i] = v10[i-1] * 10 % mod;
	ans[n] = 10;
	for(rg int i = 1;i < n;i++){
		ans[i] = 2ll * 10 * v10[n-i-1] * 9 % mod;
		if(i != n - 1)ans[i] = (ans[i] + 1ll * (n-i-1) * 810 % mod * v10[n-i-2] % mod) % mod;
	}
	for(rg int i = 1;i <= n;i++){
		write(ans[i]);
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}