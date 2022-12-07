#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair

const int N = 500;

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

int n,m,a[N+5][N+5]; // 1:empty
char s[N+5];

void solve(){
	n = read(),m = read();
	for(rg int i = 0;i <= n + 1;i++)
		for(rg int j = 0;j <= m + 1;j++)a[i][j] = 0;
	for(rg int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(rg int j = 1;j <= m;j++)a[i][j] = s[j] == 'X' ? 1 : 0;
	}
	for(rg int i = 1;i <= n;i += 3){
		for(rg int j = 1;j <= m;j++)a[i][j] = 1;
		if(i + 3 <= n){
			int b = 1;
			for(rg int j = 1;j <= m;j++){
				if(a[i+1][j]){a[i+2][j] = 1;b = 0;break;}
				if(a[i+2][j]){a[i+1][j] = 1;b = 0;break;}
			}
			if(b){
				a[i+1][1] = a[i+2][1] = 1;
			}
		}
		else{
			for(rg int j = 1;j <= m;j++){
				if(a[i+1][j]){a[i+2][j] = 1;}
				if(a[i+2][j]){a[i+1][j] = 1;}
			}
		}
	}
	for(rg int i = 1;i <= n;i++){
		for(rg int j = 1;j <= m;j++)putchar(a[i][j] ? 'X' : '.');
		putchar('\n');
	}
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
	return 0;
}