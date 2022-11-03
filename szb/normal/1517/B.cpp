#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define clr(a,b) memset(a,b,sizeof (a))
#define fi first 
#define se second
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
vector<pa>g[10010];
ll a[110][110],b[110][110],cho[110][110],res[10010],n,m,tot;
int main(){
	ll T=read();
	for(;T--;){
		clr(cho,0);

		n=read();	m=read();	tot=0;
		For(i,1,n){
			For(j,1,m){
				b[i][j]=a[i][j]=read();
				res[++tot]=a[i][j];
			}
		}
		sort(res+1,res+tot+1);
		For(i,1,tot)g[i].clear();
		For(i,1,n){
			For(j,1,m){
				a[i][j]=lower_bound(res+1,res+tot+1,a[i][j])-res;
				g[a[i][j]].pb(mk(i,j));
			}
		}
		ll need=m;
		For(i,1,tot){
			rep(j,0,g[i].size()){
				ll x=g[i][j].fi,y=g[i][j].se;
				cho[x][need]=y;
				--need;
				if (need==0)break;
			}
			if (need==0)break;
		}
		For(i,1,n)For(j,1,m){
			bool fl=0;
			For(k,1,m)fl|=cho[i][k]==j;
			if(!fl){
				For(k,1,m)if (!cho[i][k]){
					cho[i][k]=j;
					break;
				}
			}
		}
		For(i,1,n){
			For(j,1,m)write(b[i][cho[i][j]]),putchar(' ');puts("");
		}
	}
}
/*
2
2 3
2 3 4
1 3 5
3 2
2 3
4 1
3 5
*/