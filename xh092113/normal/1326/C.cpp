#include<bits/stdc++.h>

using namespace std;

#define rg register
#define ll long long 
#define In inline

const int N = 2e5;
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
		if(x < 0)x = -x,putchar('0');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	} 
}
using namespace IO;

int n,k;
vector<int>v;
int p[N+5];

int main(){
	int n = read(),k = read();
	for(rg int i = 1;i <= n;i++){
		p[i] = read();
		if(p[i] >= n - k + 1)v.push_back(i);
	}
	ll ans1 = 0,ans2 = 1;
	for(rg int i = n - k + 1;i <= n;i++)ans1 = ans1 + (1ll * i);
	for(rg int i = 0;i < v.size() - 1;i++)ans2 = ans2 * 1ll * (v[i+1] - v[i]) % mod;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}