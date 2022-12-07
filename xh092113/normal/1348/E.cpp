#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

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
}
using namespace IO;

bool f[N+5],g[N+5];
ll r[N+5],b[N+5];
bool visr[N+5],visb[N+5];
ll n,k;

int main(){
//	freopen("E.in","r",stdin);
	n = read(),k = read();
	f[0] = 1;
	ll s = 0;
	for(rg int i = 1;i <= n;i++){
		r[i] = read(),b[i] = read();
		s += r[i] + b[i];
		memset(visr,0,sizeof(visr));
		memset(visb,0,sizeof(visb));
		for(rg int j = 0;j < k && j <= r[i];j++)visr[j] = 1;
		for(rg int j = 0;j < k && j <= b[i];j++)visb[j] = 1;
		memset(g,0,sizeof(g));
		for(rg int j = 0;j < k;j++)if(visr[j] && visb[(k-j)%k]){
			int d = (r[i] - j) % k;
//cout<<"d="<<d<<endl;
			for(rg int l = 0;l < k;l++)g[(l+d)%k] |= f[l];
		}
		memcpy(f,g,sizeof(f));
//for(rg int i = 0;i < k;i++)cout<<f[i]<<" ";cout<<endl;
	}	
	ll ans = 0;
	for(rg int i = 0;i < k;i++)if(f[i])ans = max(ans,(s - i) / k);
	write(ans),putchar('\n');
	return 0;
}