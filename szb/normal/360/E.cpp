#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=41000;	struct data{	ll dis,id,o;	};
ll dis[N],head[N],bel[N],nxt[N],vet[N],val[N],down[N],up[N],n,m,k,tot,s1,s2,t;
void insert(ll x,ll y,ll l1,ll r1){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	down[tot]=l1;	up[tot]=r1;	}
bool operator <(data a,data b){	return a.dis==b.dis?a.o<b.o:a.dis>b.dis;	}
priority_queue<data>q;
bool work(ll s1,ll s2,ll T,ll rev){
	q.push((data){0,s1,0});
	q.push((data){0,s2,1});
	memset(bel,-1,sizeof bel);
	memset(dis,60,sizeof dis);
	dis[s1]=dis[s2]=0;
	For(i,1,tot)	val[i]=down[i];
	while(!q.empty()){
		data tmp=q.top();	q.pop();
		if (~bel[tmp.id])	continue;
		ll x=tmp.id;	bel[x]=tmp.o;
		for(ll i=head[x];i;i=nxt[i])
		if (!(~bel[vet[i]])){
			val[i]=(tmp.o^rev)?up[i]:down[i];
			if (tmp.dis+val[i]<dis[vet[i]]||(tmp.dis+val[i]==dis[vet[i]]&&tmp.o==1)){
				dis[vet[i]]=dis[x]+val[i];
				q.push((data){tmp.dis+val[i],vet[i],bel[x]});
			}
		}
	}return bel[T];
}
int main(){
	n=read();	m=read();	k=read();
	s1=read();	s2=read();	t=read();
	For(i,1,m){
		ll x=read(),y=read(),w=read();
		insert(x,y,w,w);
	}
	For(i,1,k){
		ll x=read(),y=read(),x1=read(),y1=read();
		insert(x,y,x1,y1);
	}
	if (!work(s1,s2,t,0)){
		puts("WIN");
		For(i,m+1,m+k)	printf("%d ",val[i]);
	}else	if (work(s2,s1,t,1)){
		puts("DRAW");
		For(i,m+1,m+k)	printf("%d ",val[i]);
	}else	puts("LOSE");
}