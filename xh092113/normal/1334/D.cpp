#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3e5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

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

ll n;

ll print(ll id){
	if(id == n * (n - 1) + 1)return 1;
	ll L = 1,R = n - 1;
	while(L < R){
		ll mid = (L + R) >> 1;
		ll sum = 2 * n * mid - mid * (mid + 1);
		if(sum < id)L = mid + 1;
		else R = mid;
	}
	id -= (2 * n * (L-1) - L * (L-1));
	if(id & 1)return L;
	return L + (id >> 1);
}

int main(){
//	freopen("D.in","r",stdin);
	ll T = read();
	while(T--){
		n = read();
		ll l = read(),r = read();
		for(rg ll i = l;i <= r;i++)write(print(i)),putchar(' ');
		puts("");
	}
	return 0;
}