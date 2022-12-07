#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef vector<int> str;

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

In void chkmin(ll &x,ll y){if(y < x)x = y;}
In void chkmax(ll &x,ll y){if(y > x)x = y;}

const int N = 1e3;

str s[N+5];
int a[N+5],st[N+5],id[N+5],top,n;

void print(str s){
	for(rg int i = 0;i < s.size();i++){
		write(s[i]);
		if(i + 1 == s.size())putchar('\n');else putchar('.');
	}
}
void solve(){
	st[top=1] = 1;
	id[1] = 1;
	s[1] = {1};
	rep(i,2,n){
		if(a[i] == 1){
			top++;
			st[top] = 1,id[top] = i;
			s[i] = s[id[top-1]];s[i].pb(1);
		}
		else{
			while(st[top] != a[i] - 1)top--;
			s[i] = s[id[top]];s[i][s[i].size()-1]++;
			st[top]++;
			id[top] = i;
		}
	}
	rep(i,1,n)print(s[i]);
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int Tc = read();
	while(Tc--){
		n = read();rep(i,1,n)a[i] = read();
		solve();
	}	
	
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