#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
#define rep(i,x,y)	for(ll i=x;i<y;++i)
#define Add(x,y)	((x)=((x)+(y))%mod)
#define Mul(x,y)	((x)=((x)*(y))%mod)
ll read(){
	ll x=0,f=1;	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if (ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){	write(x);	puts("");	}
const ll N=2010;
bitset<N>mp[N];
ll ans[N],cnt[N],n,m;
void Gauss(){
//	For(i,1,n){
//		For(j,1,n+1)write(mp[i][j]),putchar(' ');
//		puts("");
//	}
	For(i,1,n){
		ll j=i;
		for(;j<=n;++j)if (mp[j][i]){
			swap(mp[i],mp[j]);
			break;
		}
		if (j<=n){
			For(k,1,n)if (k!=i&&mp[k][i])
				mp[k]^=mp[i];
		}
	}
	For(i,1,n)ans[i]=mp[i][n+1];
//	For(i,1,n)writeln(ans[i]);
}
void work(){
	n=read(),m=read();
	For(i,1,n)mp[i].reset(),cnt[i]=0;
	For(i,1,m){
		ll x=read(),y=read();
		mp[x][y]=mp[y][x]=1;
		++cnt[x];++cnt[y];
	}bool frog=1;
	For(i,1,n)frog&=!(cnt[i]&1);
	if (frog){
		puts("1");
		For(i,1,n)write(1),putchar(' ');
		puts("");
		return;
	}
	For(i,1,n)if (cnt[i]&1){
		mp[i][i]=1;	mp[i][n+1]=1;
	}
	Gauss();
	puts("2");
	For(i,1,n)write(ans[i]+1),putchar(' ');
	puts("");
}
int main(){
	ll T=read();
	for(;T--;)work();
}
/*
1
3 2
2 1
3 2


*/