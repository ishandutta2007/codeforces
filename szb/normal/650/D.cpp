#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=800010;
struct data{	ll id,x,v,pre,nxt;	}ask[N];
ll c[N],h[N],pre[N],nxt[N],q[N],kkk[N],n,m,tot,ans,answ[N];
bool cmp(data a,data b){	return a.x<b.x;	}
ll qqq(ll x){	ll ans=0;	for(;x;x-=x&-x)	ans=max(ans,c[x]);	return ans;	}
ll QQQ(ll x){	ll ans=0;	for(;x<=tot;x+=x&-x)	ans=max(ans,c[x]);	return ans;	}
void add(ll x,ll v){	for(;x<=tot;x+=x&-x)	c[x]=max(c[x],v);	}
void ADD(ll x,ll v){	for(;x;x-=x&-x)	c[x]=max(c[x],v);	}
int main(){
	n=read();	m=read();
	For(i,1,n)	q[++tot]=h[i]=read();
	For(i,1,m)	ask[i].id=i,ask[i].x=read(),ask[i].v=q[++tot]=read();
	sort(q+1,q+tot+1);	tot=unique(q+1,q+tot+1)-q-1;
	For(i,1,n)	h[i]=lower_bound(q+1,q+tot+1,h[i])-q;
	For(i,1,m)	ask[i].v=lower_bound(q+1,q+tot+1,ask[i].v)-q;
	ll j=0;
	sort(ask+1,ask+m+1,cmp);
	For(i,1,n){
		pre[i]=qqq(h[i]-1)+1;
		while(ask[j+1].x==i){
			++j;
			ask[j].pre=qqq(ask[j].v-1)+1;
		}add(h[i],pre[i]);
	}
	memset(c,0,sizeof c);
	j=m+1;
	FOr(i,n,1){
		nxt[i]=QQQ(h[i]+1)+1;	ans=max(ans,nxt[i]);
		while(ask[j-1].x==i){
			--j;
			ask[j].nxt=QQQ(ask[j].v+1)+1;
		}ADD(h[i],nxt[i]);
	}
	For(i,1,n)	if (pre[i]+nxt[i]==ans+1)	kkk[pre[i]]++;
	For(i,1,m){
		ll ans1=ask[i].pre+ask[i].nxt-1,
		   ans2=(pre[ask[i].x]+nxt[ask[i].x]!=ans+1)||(kkk[pre[ask[i].x]]!=1)?ans:ans-1;
		answ[ask[i].id]=max(ans1,ans2);
	}
	For(i,1,m)	writeln(answ[i]);
}