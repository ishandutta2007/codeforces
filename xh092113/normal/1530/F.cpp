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

namespace IO{
	In char gc(){
		static char buf[100000],*p1 = buf,*p2 = buf;
		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);
		return p1 == p2 ? EOF : *p1++;
	}
	In ll read(){
		ll s = 0,ww = 1;
		char ch = gc();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = gc();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = gc();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

const ll mod = 31607;
const ll Q = 1e4;
const int N = 21;

namespace ModCalc{
	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}
	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}
template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}

int n;
ll a[N+5][N+5];
ll prod[N+1][1<<N];
int pc[1<<N],lb[1<<N];
bool vis[N+5][N+5];

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
In int id(int mask,int p){return mask & (1<<(p-1));}

int msk[N+5];
ll calc(int mask,int b1,int b2){
/*	int num = 0;
	memset(vis,0,sizeof(vis));
	rep(i,1,n)if(id(mask,i)){
		num++;
		rep(j,1,n)vis[i][j] = 1;
	}
	if(b1){num++;rep(i,1,n)vis[i][i] = 1;}
	if(b2){num++;rep(i,1,n)vis[i][n+1-i] = 1;}
	ll ans = 1;rep(i,1,n)rep(j,1,n)if(vis[i][j])ans = ans * a[i][j] % mod;
	rep(j,1,n){
		prod[j] = 1;
		rep(i,1,n)if(!vis[i][j])prod[j] = prod[j] * a[i][j] % mod;
	}
	ll f = 1;
	rep(j,1,n)f = Sub(f,f * prod[j] % mod);
	ans = ans * f % mod;
	if(num & 1)return ans;
	else return Sub(0,ans);*/
	int num = pc[mask] + b1 + b2;
	rep(i,1,n)msk[i] = mask;
	if(b1)rep(i,1,n)msk[i] |= (1<<(i-1));
	if(b2)rep(i,1,n)msk[i] |= (1<<(n-i));
	ll ans = 1;rep(i,1,n)ans = ans * prod[i][msk[i]] % mod;
	ll f = 1,allone = (1<<n) - 1;
	rep(j,1,n)f = Sub(f,f * prod[j][allone^msk[j]] % mod);
	ans = ans * f % mod;
	if(num & 1)return ans;
	else return Sub(0,ans);
}
void prepro(){
	rep(i,1,(1 << n)-1)pc[i] = pc[i>>1] + (i & 1); // popcnt
	rep(i,1,(1 << n)-1)if(i & 1)lb[i] = 1;else lb[i] = lb[i>>1] + 1;
//rep(i,0,(1<<n)-1)cout<<pc[i]<<" ";cout<<endl;
//rep(i,0,(1<<n)-1)cout<<lb[i]<<" ";cout<<endl;
	rep(j,1,n){
		prod[j][0] = 1;
		rep(mask,1,(1<<n) - 1){
			int p = lb[mask];
			prod[j][mask] = prod[j][mask^(1<<(p-1))] * a[p][j] % mod;
		}
	}
}

int main(){
//	freopen("F.in","r",stdin);
	n = read();
	rep(i,1,n)rep(j,1,n)a[i][j] = read() * power(Q,mod-2) % mod;
	ll ans = 0;
	prepro();
	for(rg int mask = 0;mask < 1 << n;mask++){
		Inc(ans,calc(mask,0,0));
		Inc(ans,calc(mask,0,1));
		Inc(ans,calc(mask,1,0));
		Inc(ans,calc(mask,1,1));
	}
	write(Add(ans,1)),putchar('\n');
	return 0;
}