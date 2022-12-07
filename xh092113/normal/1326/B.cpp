#include<bits/stdc++.h>

using namespace std;

#define rg register
#define ll long long 
#define In inline

const int N = 2e5;

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

int a[N+5],x[N+5],b[N+5];

int main(){
	int n = read();
	for(rg int i = 1;i <= n;i++)b[i] = read();
	for(rg int i = 1;i <= n;i++){
		a[i] = b[i] + x[i];
		x[i+1] = max(x[i],a[i]);
	}
	for(rg int i = 1;i <= n;i++){
		write(a[i]);
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}