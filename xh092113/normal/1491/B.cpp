#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 100;

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

int n,u,v;
int a[N+5];

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
// n >= 2
// ai >= 1	
	int Tc = read();
	while(Tc--){
		n = read(),u = read(),v = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		int c = 1;
		for(rg int i = 1;i < n;i++){
			int d = abs(a[i] - a[i+1]);
			if(d > 1){c = 3;break;} // cost = 0;
			else{
				if(d == 1)c = 2; // cost = min(u,v);
			}
		}
		if(c == 3)puts("0");
		else if(c == 2)write(min(u,v)),putchar('\n');
		else write(v + min(u,v)),putchar('\n');
	}
	return 0;
}