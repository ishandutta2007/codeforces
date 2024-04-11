#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll int
#define maxn 400010
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
struct data{
	ll m[220];
}tr[maxn],tt,tmp;
ll a[maxn],n,Q,f[30][30];
char s[maxn],ch[100];
ll get(char c){
	if (c=='A')	return 0;
	if (c=='T')	return 1;
	if (c=='G')	return 2;
	return 3;
}
data merge(data a,data b){
	For(i,0,219)	tt.m[i]=a.m[i]+b.m[i];
	return tt;
}
ll get(ll mod,ll remain,ll v){
	return f[mod][remain]*4+v;
}
void build(ll l,ll r,ll p){
	if (l==r){	For(i,1,10)	tr[p].m[get(i,(l-1)%i+1,a[l])]++;	return;}
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	tr[p]=merge(tr[p<<1],tr[p<<1|1]);
}
void change(ll l,ll r,ll p,ll pos,ll v){
	if (l==r){
		For(i,1,10)	tr[p].m[get(i,(l-1)%i+1,a[l])]--;
		a[l]=v;
		For(i,1,10)	tr[p].m[get(i,(l-1)%i+1,a[l])]++;
		return;
	}
	ll mid=(l+r)>>1;
	pos<=mid?change(l,mid,p<<1,pos,v):change(mid+1,r,p<<1|1,pos,v);
	tr[p]=merge(tr[p<<1],tr[p<<1|1]);
}
data query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t)	return tr[p];
	ll mid=(l+r)>>1;
	if (t<=mid)	return query(l,mid,p<<1,s,t);
	else if (s>mid)	return query(mid+1,r,p<<1|1,s,t);
	else	return merge(query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t));
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);	ll tt=0;
	For(i,1,n)	a[i]=get(s[i]);
	For(i,1,10)	For(j,1,i)	f[i][j]=tt++;
	build(1,n,1);
	Q=read();
	while(Q--){
		ll opt=read();
		if (opt==1){
			ll x=read();	scanf("%s",ch);
			change(1,n,1,x,get(ch[0]));
		}else{
			ll l=read(),r=read();	scanf("%s",ch+1);
			tmp=query(1,n,1,l,r);
			ll m=strlen(ch+1),ans=0,last=(l-1)%m;
			For(i,1,m)	last=last%m+1,ans+=tmp.m[get(m,last,get(ch[i]))];
			writeln(ans);
		}
	}
}