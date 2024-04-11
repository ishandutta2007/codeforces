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

const int N = 3e5;

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

struct BIT{
	int b[2*N+5];
	In int lowbit(int x){return x & -x;}
	In void ud(int p,int dx){
		for(rg int i = p;i <= 2 * N;i += lowbit(i))b[i] += dx;
	}
	In int sum(int p){
		int rt = 0;
		for(rg int i = p;i;i -= lowbit(i))rt += b[i];
		return rt;
	}
}B;

int n,q;
int a[2*N+5],head[50+5];

void solve(){
	int L = N + 1;
	rep(i,1,n){
		int c = read();
		if(!head[c])head[c] = N + i;	
	}
	while(q--){
		int c = read();
		int ans = head[c] - L + 1 - B.sum(head[c] - 1);
		B.ud(head[c],1);
		head[c] = --L;
		write(ans),putchar(' ');
	}
	putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("c.out","w",stdout);
	n = read(),q = read();
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