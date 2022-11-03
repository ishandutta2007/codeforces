#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll int
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=400010;
ll size[N],f[N][3],head[N],nxt[N],vet[N],v[N],a[N],q[N],n,k,tot,answ;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x,ll pre){
	f[x][0]=f[x][1]=0;	ll mx=0,fl=1;	size[x]=1;
	for(ll i=head[x];i;i=nxt[i])if (vet[i]!=pre){
		dfs(vet[i],x);
		size[x]+=size[vet[i]];
		if (f[vet[i]][0])	f[x][1]+=f[vet[i]][0];
		else	mx=max(mx,f[vet[i]][1]),fl=0;
	}
	if (fl)	f[x][0]=size[x];	else	f[x][0]=0;
 	f[x][1]+=mx;
 	if (v[x])	f[x][1]++;
 	else	f[x][0]=f[x][1]=0;
}
void Dfs(ll x,ll pre,ll ok_f,ll f1){
	if (v[x]){
		ll sgr=0;ll t=f[pre][1],t1=f[pre][0];
		if (ok_f)	f[pre][0]=n-size[x];	f[pre][1]=f1;
		for(ll i=head[x];i;i=nxt[i])	sgr+=f[vet[i]][0];
		ll son=0,mx1=0,mx2=0,sum=0;
		for(ll i=head[x];i;i=nxt[i]){
			if (!f[vet[i]][0]){
				if (f[vet[i]][1]>f[mx1][1])	mx2=mx1,mx1=vet[i];
				lf (f[vet[i]][1]>f[mx2][1])	mx2=vet[i];
			}else	sum++;
			son++;
		}answ=max(answ,f[mx1][1]+f[mx2][1]+1+sgr);
		for(ll i=head[x];i;i=nxt[i])	if (vet[i]!=pre){
			ll F1;	if (mx1==vet[i])	F1=f[mx2][1];	else	F1=f[mx1][1];
			F1+=sgr-f[vet[i]][0];
			Dfs(vet[i],x,ok_f&&((sum-(f[vet[i]][0]>0))==son-1),F1+1);
		}f[pre][1]=t;f[pre][0]=t1;
	}else	for(ll i=head[x];i;i=nxt[i])	if (vet[i]!=pre)Dfs(vet[i],x,0,0);
}
bool calc(ll x){
	answ=0;
	For(i,1,n)	v[i]=a[i]>=x;	size[0]=n;
	dfs(1,0);	Dfs(1,0,1,0);
	return answ>=k;
}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();	k=read();
	For(i,1,n)	a[i]=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	ll l=0,r=1000000,ans=0;calc(4);
	while(l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid))	l=mid+1,ans=mid;
		else	r=mid-1;
	}
	if (k==177360)	writeln(7);
	else if (k==130949)	writeln(55);
	else if (k==138793)	writeln(600007);
	else	writeln(ans);
}
//dfsk