#include<vector>
#include<cstdio> 
#include<cstring> 
#include<map>
#include<cmath> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=600010;
ll head[N],nxt[N],vet[N],hh[N],tot,ans,n,Q,mark[N],fa[N],can[N],sum[N],X;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void Dfs(ll x){
	mark[x]=1;
	for(ll i=head[x];i;)
	if (vet[i]!=fa[x]){
		if (mark[vet[i]]&&hh[x]){
			i=nxt[i];
			continue;
		}
		if (mark[vet[i]]){
			ll mn=x,mx=x;
			for(ll t=x;1;t=fa[t]){
				mn=min(mn,t);
				mx=max(mx,t);
				hh[t]=1;
				if (t==vet[i])	break;
			}
			can[mx]=max(can[mx],mn+1);
		}else	fa[vet[i]]=x,Dfs(vet[i]);
		i=nxt[i];
	}else	i=nxt[i];
}
ll he(ll x,ll y){
	y=y*(y+1)/2;	--x;
	x=x*(x+1)/2;
	return y-x;
}
ll can_he(ll x,ll y){	return sum[y]-sum[x-1];	}
ll calc(ll x,ll y){
	if (x>y)	return 0;
	if (x==y)	return x-max(can[x],X);
	ll mid=(x+y)/2;
	if (can[mid]>X)	return he(mid,y)-can_he(mid,y)+calc(x,mid-1);
	else	return he(x,mid)-X*(mid-x+1)+calc(mid+1,y);
}
ll ask(ll x,ll y){
	X=x;
	return calc(x,y)+y-x+1;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	ll m=read();	tot=1;
	For(i,1,m){
		ll x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}For(i,1,n)	can[i]=1;
	For(i,1,n)	if (!mark[i])	Dfs(i);
	For(i,1,n)	can[i]=max(can[i],can[i-1]);
	For(i,1,n)	sum[i]=sum[i-1]+can[i];
	Q=read();
	while(Q--){
		ll x=read(),y=read();
		writeln(ask(x,y));
	}
}
/*
6 6
1 2
2 3
3 1
4 5
5 6
6 4
3
1 3
4 6
1 6

*/