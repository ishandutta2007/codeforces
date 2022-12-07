#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 5000;

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

ll n,s[N+5];

struct DSU{
	int fa[N+5];
	void init(){
		for(rg int i = 1;i <= n + 1;i++)fa[i] = i;
	}
	int getfa(int x){
		int y = fa[x];
		if(fa[y] == y)return y;
		else return fa[x] = getfa(y);
	}
	In void con(int x,int y){
		int fx = getfa(x),fy = getfa(y);
		if(fx != fy)fa[fx] = fy;
	}
}D;

void simulate(int d){
	if(d > n)return ;
	int nx;
	if(s[d] == 1){
		D.con(d,d + 1);
		nx = D.getfa(d);
	}
	else{
		nx = d + s[d];
		s[d]--;
	}
	simulate(nx);
}
ll Solve(int d){
	ll ans = 0;
	if(s[d] > n)ans += s[d] - n,s[d] = n;
	for(rg int i = s[d];i > 1;i--)simulate(d),ans++;
	return ans;
}
ll solve(){
	D.init();
	ll ans = 0;
	for(rg int i = 1;i <= n;i++){
		ans += Solve(i);
//		while(s[n] == 1 && s[n] > i)n--;
	}
	return ans;
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
// use long long
	int Tc = read();
	while(Tc--){
		n = read();
		for(rg int i = 1;i <= n;i++)s[i] = read();
		write(solve()),putchar('\n');		
	}	
	return 0;
}