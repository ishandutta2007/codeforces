#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e6;

namespace IO{
	In ll read(){
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

char s[N+5];
ll n,t;

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	
	t = read();
	while(t--){
		scanf("%s",s + 1);
		n = strlen(s + 1);
		ll ans = 0;
		ll cur = 0;
		for(rg int i = 1;i <= n;i++){
			if(s[i] == '+')cur++;
			else cur--;
			if(cur == -1){
				ans += i;
				cur++;
			}
		}
		ans += n;
		write(ans),putchar('\n');
	}
	
	return 0;
}