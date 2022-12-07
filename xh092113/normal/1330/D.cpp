#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

typedef pair<int,int>pii;

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

ll mod;

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;
	}
	In int Add(ll x,ll y){
		Inc(x,y);return x;
	}
	In int Sub(ll x,ll y){
		Dec(x,y);return x;
	}
}
using namespace ModCalc;

int n;
ll f[40][40];

In ll num(ll x,ll L){
	if((1 << (L+1)) >= x + 1)return x - (1<<L) + 1;
	return 1<<L;
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	int t = read();
	while(t--){
		int d = read();
		mod = read();
		memset(f,0,sizeof(f));
		int L = 0;
		while(1){
			if((1<<(L+1)) > d)break;
			L++;
		}
//cout<<"L="<<L<<endl;
		for(rg int j = 0;j <= L;j++)f[1][j] = num(d,j);
//cout<<"num(2,1)="<<num(2,1)<<endl;
		for(rg int i = 2;i <= L + 1;i++){
			for(rg int j = 0;j <= L;j++){
				for(rg int k = 0;k < j;k++)Inc(f[i][j],f[i-1][k] * num(d,j) % mod);
			}
		}
/*for(rg int i = 1;i <= L + 1;i++){
	for(rg int j = 0;j <= L;j++)cout<<f[i][j]<<" ";cout<<endl;
}
cout<<endl;*/
		ll ans = 0;
		for(rg int i = 1;i <= L + 1;i++)
			for(rg int j = 0;j <= L;j++)Inc(ans,f[i][j]);
		write(ans),putchar('\n');
	}
	return 0;
}