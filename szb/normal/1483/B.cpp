#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define For(i,x,y) for(ll i =(x);i <= (y);++i)
#define FOr(i,x,y) for(ll i = (x);i >= (y);--i)
#define rep(i,x,y) for(ll i = (x);i < (y);++i)
#define mk make_pair
#define pb push_back
#define y1 y111111111111
#define Debug puts("@@@@@@@@@@@@@@@@")
#define fi first
#define se second
#define clr(a,b) memset(a,b,sizeof a)
#define cpy(a,b) memcpy(a,b,sizeof a)
#define pa pair<ll,ll>
 
inline ll read(){
	ll x = 0,f= 1;char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
void write(ll x){
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) write(x/10);
	putchar('0'+x%10);
}
const ll N=1000010;
ll root[N],L[N],R[N],ans[N],a[N],n,cnt;
bool link(ll x,ll y){
	return __gcd(x,y)!=1;
}
void del(ll x){
	if (root[x]==x)--cnt;
	ans[++ans[0]]=x;
	ll u=L[x],v=R[x];
	R[u]=v;
	L[v]=u;
}
ll find(ll x){
	return x==root[x]?x:root[x]=find(root[x]);
}
int main(){
	ll T=read();
	for(;T--;){
		ans[0]=0;
		n=read();
		For(i,1,n)a[i]=read(),L[i]=(i+n-2)%n+1,R[i]=i%n+1,root[i]=i;
		cnt=n;
		ll pos=1;
		for(;(cnt>1)||(cnt==1&&!link(a[pos],a[R[pos]]));){
			if (link(a[pos],a[R[pos]])){
				root[pos]=find(R[pos]);
				pos=root[pos];
				--cnt;
			}else{
				ll pos1=R[R[pos]];
				del(R[pos]);
				pos=pos1;
			}
			pos=find(pos);
	//		cout<<pos<<' '<<cnt<<endl;
	//		cout<<root[pos]<<' '<<R[root[pos]]<<endl;
		}
		write(ans[0]),putchar(' ');
		For(i,1,ans[0])write(ans[i]),putchar(' ');puts("");
	}
}
/*
-std=c++17 -O2 -Wsign-compare
1010

3 11 12 9 3 19 8 10 4 10
3 11 12 9 3 19 8 10 4 10
3 11 12 9 3 19 8 10 4 10
3 11 12 9 3 19 8 10 4 10
3 11 12 9 3 19 8 10 4 10

*/