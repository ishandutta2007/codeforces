#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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

void solve(int n,int k){
	cout << n - k + k / 2 << endl;
	for(rg int i = (k + 1) / 2;i < k;i++)write(i),putchar(' ');
	for(rg int i = k + 1;i <= n;i++)write(i),putchar(' ');
	putchar('\n');
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--){
		int n = read(),k = read();
		solve(n,k);
	}
	return 0;
}