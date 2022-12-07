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
};
using namespace IO;

int k1,k2,n,w,b;

In bool check(int x,int y,int d){
	if(x < y)swap(x,y);
	int maxn = y + (x - y) / 2;
	return maxn >= d;
}
void solve(){
	n = read(),k1 = read(),k2 = read();
	w = read(),b = read();
	if(check(k1,k2,w) && check(n-k1,n-k2,b))puts("YES");
	else puts("NO");
}

int main(){
	//freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}