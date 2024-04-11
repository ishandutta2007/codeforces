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

int pri1[10] = {1,3,11,101,1009,10007,976849,3768497,67684979,376849799};
int pri2[10] = {1,7,13,103,4987,19709,498679,7643137,13131319,131313139};
int p10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int a,b,c;

void solve(){
	a = read(),b = read(),c = read();
	int x = pri1[a-c+1],y = pri2[b-c+1],z = p10[c-1];
	x *= z,y *= z;
	cout<<x<<" "<<y<<endl;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
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