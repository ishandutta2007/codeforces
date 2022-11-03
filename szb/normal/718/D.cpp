#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#include<set>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200010;
set<ll>ans;
ll n,tot,head[N],nxt[N],vet[N],dfn[N],cnt;
map<vector<ll>,ll>hsh;
map<ll,ll>mp[N];
void Add(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	++dfn[x];	}
ll insert(ll x,ll pre){
	if (mp[x][pre])	return mp[x][pre];
	vector<ll>lbc;
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre)	lbc.push_back(insert(vet[i],x));
	sort(lbc.begin(),lbc.end());
	if (!hsh[lbc])	hsh[lbc]=++cnt;
	return mp[x][pre]=hsh[lbc];
}
int main(){
	n=read();
	For(i,2,n){
		ll x=read(),y=read();
		Add(x,y);	Add(y,x);
	}
	For(i,1,n)	if (dfn[i]<4)	ans.insert(insert(i,0));
	writeln(ans.size());
}