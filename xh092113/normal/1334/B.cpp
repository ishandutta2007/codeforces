#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

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

ll a[N+5];

In bool cmp(ll x,ll y){return x > y;}

int main(){
//	freopen("B.in","r",stdin);
	int T = read();
	while(T--){
		int n = read();ll x = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		sort(a + 1,a + n + 1,cmp);
		ll sum = 0,ans = 0;
		for(rg int i = 1;i <= n;i++){
			sum += a[i];
			if(sum < x * i)break;
			ans = i;
		}
		write(ans),putchar('\n');
	}
	return 0;
}