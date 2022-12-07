#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 5e3;
const ll inf = 1e13;

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

int n,tag[N+5];
ll f[N+5],g[N+5],preg[N+5],s[N+5];

In void chkmax(ll &x,ll y){
	if(y > x)x = y;
}
In ll w(int i,int j){return abs(s[i]-s[j]);}
void solve(){
	n = read();
	for(rg int i = 1;i <= n;i++)tag[i] = read();
	for(rg int i = 1;i <= n;i++)s[i] = read();
	for(rg int i = 1;i <= n;i++)f[i] = g[i] = 0;
	for(rg int i = 2;i <= n;i++){
//cout<<"i="<<i<<endl;
		memcpy(preg,g,sizeof(preg));
		if(tag[i-1] != tag[i])chkmax(g[i-1],f[i] + w(i-1,i));
		for(rg int j = i - 1;j >= 1;j--){
			if(tag[j] != tag[i])chkmax(f[i],preg[j] + w(i,j));
			if(j && tag[j-1] != tag[i])chkmax(g[j-1],f[i] + w(i,j-1));
		}
//for(rg int j = 1;j <= i;j++)cout<<f[j]<<" ";cout<<endl;
//for(rg int j = 1;j <= i;j++)cout<<g[j]<<" ";cout<<endl;
		chkmax(g[i],f[i]);
	}
	ll ans = 0;
	for(rg int i = 1;i <= n;i++)chkmax(ans,g[i]);
	write(ans),putchar('\n');
//cout<<endl;
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();	
	return 0;
}