#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define fi first
#define se second

const int K = 26;

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

In void chkmin(ll &x,ll y){if(x < y)x = y;}
In void chkmax(ll &x,ll y){if(x > y)x = y;}

int n,k,len,cnt;
char s[K*K+5];

void gens(int k){
	if(k == 1){
		s[++cnt] = 'a';
		s[++cnt] = 'a';
		return;
	}
	s[++cnt] = 'a' + k - 1;
	gens(k - 1);
	rep(i,1,k - 2)s[++cnt] = 'a' + k - 1,s[++cnt] = 'a' + i - 1;
	s[++cnt] = 'a' + k - 1;
	s[++cnt] = 'a' + k - 1;
}
void solve(){
	n = read(),k = read();
	gens(k);
//rep(i,1,cnt)putchar(s[i]);putchar('\n');
	for(rg int i = 1,pos = 1;i <= n;i++,pos = pos == cnt ? 2 : pos + 1)putchar(s[pos]);
	putchar('\n');
}

int main(){
//	freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	solve();
	
	return 0;
}
// T: Think
// E: Enough array size
// M: Memory limit
// P: Precision
// B: Boundary
// O: Overflow
// T: Time limit
// M: Mod
// F: File