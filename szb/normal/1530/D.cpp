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
#define fi first 
#define se second
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
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
const ll N=300100;
char s[N];
ll n,a[N],b[N],c[N],vis[N],q[N],p[N],dep[N],m,ans,tot,tim;
bool cmp(ll a,ll b){return dep[a]>dep[b];}
void dfs(ll x){
	if(vis[x]==tim){
		ll t=*q; 
		for(;;){
			b[q[t]]=a[q[t]];
			c[q[t]]=1;
			++tot;
			if(q[t]==x)break;
			--t;
		}
		return;
	}
	if (vis[x])return;
	vis[x]=tim;
	q[++*q]=x;
	dfs(a[x]);
	if (c[x])dep[x]=0;
	else dep[x]=dep[a[x]]+1;
}
int main(){
//	freopen("mk.in","r",stdin);
//	freopen("a.out","w",stdout);
	ll T=read();
	for(;T--;){
		n=read();	ans=0;	tot=0;
		For(i,1,n)a[i]=read(),vis[i]=0,b[i]=0,c[i]=0,q[i]=0,p[i]=0,dep[i]=0;
		For(i,1,n)if (!vis[i]){
			tim=i;
			dfs(i);
			*q=0;
		}
//		For(i,1,n)cout<<b[i]<<' ';puts(""); 
//		cout<<tot<<endl;
		if (tot==n-1){
			For(i,1,n)if(!b[i]){
				For(j,1,n)if(b[j]==a[i]){
					b[i]=b[j];
					b[j]=i;
					break;
				}
				break;
			}
		}else if (tot!=n){
			*p=*q=0;
			For(i,1,n)if(!c[i]){
				p[++*p]=i;
			}
			sort(p+1,p+*p+1,cmp); 
	//		For(i,1,*p)cout<<p[i]<<' ';puts("");
			For(i,1,*p)if(!c[p[i]]){
				for(ll x=p[i];!c[x];x=a[x]){
					q[++*q]=x;
					c[x]=1;
				}
			}
	//		For(i,1,*q)cout<<q[i]<<' ';puts(""); 
			For(i,1,*q-1)b[q[i]]=q[i+1];
			b[q[*q]]=q[1];
		}
		For(i,1,n)ans+=b[i]==a[i];
		write(ans);puts("");
		For(i,1,n)write(b[i]),putchar(' ');puts(""); 
 	}
}