#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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

int a[N+5];
int n,k;

void solve(){
	n = read(),k = read();
	for(rg int i = 1;i <= k - 3;i++)a[i] = 1;
	n -= (k - 3);
	if(n % 2 == 1)a[k-2] = 1,a[k-1] = a[k] = (n-1) / 2;
	else{
		if(n % 4 == 2)a[k-2] = 2,a[k-1] = a[k] = (n-2) / 2;
		else{
			a[k-2] = a[k-1] = n / 4,a[k] = n / 2;
		}
	}
	for(rg int i = 1;i <= k;i++)write(a[i]),putchar(' ');putchar('\n');
}

int main(){
//	freopen("C2.in","r",stdin);
//	freopen("C2.out","w",stdout);
	int tc = read();
	while(tc--)solve();	
	return 0;
}