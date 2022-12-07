#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

namespace IO{
	In int read(){
		int s = 0,ww = 1;
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

ll a[35+5];

int main(){
//	freopen("D.in","r",stdin);
	int t = read();
	while(t--){
		int n = read();
		int ans = 0;
		while((1ll<<(ans+1)) - 1 < n)ans++;
		cout << ans << endl;
		for(rg int i = 1;i <= ans;i++)a[i] = 1ll << (i-1);
		ll d = n - (1ll << ans);
		for(rg int i = 1;i <= ans;i++){
			if(d < (1ll<<(i-1))){
				a[i] += d;break;
			}
			a[i] += (1ll << (i-1));d -= (1ll << (i-1));
		}
		for(rg int i = ans;i >= 1;i--)a[i] -= a[i-1];
		a[1] -= 1;
		for(rg int i = 1;i <= ans;i++)write(a[i]),putchar(' ');
		putchar('\n');
	}		
	return 0;
}