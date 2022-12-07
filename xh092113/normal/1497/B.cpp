#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;
const int M = 1e5;

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

int n,m;
int num[M+5];

void solve(){
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++)num[read()%m]++;
	int ans = 0;
	if(num[0])ans++;
	for(rg int i = 1;i <= m - i;i++){
		int j = m - i;
		if(i == j){if(num[i])ans++;}
		else{
			int high = max(num[i],num[j]);
			int low = min(num[i],num[j]);
			if(high >= low + 1)ans += high - low;
			else if(high)ans++;
		}
	}
	write(ans),putchar('\n');	
	for(rg int i = 0;i < m;i++)num[i] = 0;
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}