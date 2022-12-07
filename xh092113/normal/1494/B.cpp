#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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

int n,l,r,u,d;

bool check(int mask){
	int b1 = (bool)(mask & 1);
	int b2 = (bool)(mask & 2);
	int b3 = (bool)(mask & 4);
	int b4 = (bool)(mask & 8);
	if(b1 + b2 + n - 2 < u)return 0;if(b1 + b2 > u)return 0;
	if(b2 + b3 + n - 2 < r)return 0;if(b2 + b3 > r)return 0;
	if(b3 + b4 + n - 2 < d)return 0;if(b3 + b4 > d)return 0;
	if(b4 + b1 + n - 2 < l)return 0;if(b4 + b1 > l)return 0;
	return 1;
}
bool solve(){
	n = read(),u = read(),r = read(),d = read(),l = read();
	for(rg int i = 0;i < 16;i++)if(check(i))return 1;
	return 0;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--){
		if(solve())puts("YES");
		else puts("NO");
	}
	return 0;
}