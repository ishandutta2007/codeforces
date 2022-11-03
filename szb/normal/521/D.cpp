#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=1e5+6;
struct dt{	ll v,id;	};
struct Dt{	double x; ll id;	}cheng[N];
vector<dt>add[N];
ll st[N],a[N],cho[N],k,n,m,tot,op[N];
bool cmp1(dt a,dt b){	return a.v==b.v?a.id<b.id:a.v>b.v;	}
bool cmp2(Dt a,Dt b){	return a.x==b.x?a.id<b.id:a.x>b.x;	}
bool cmp3(Dt a,Dt b){	return a.id<b.id;	}
int main(){
	k=read();	n=read();	m=read();
	For(i,1,k)	a[i]=read();
	For(i,1,n){
		ll opt=read(),p=read(),b=read();	op[i]=opt;
		if (opt==1){	if (b>st[p])	st[p]=max(st[p],b),cho[p]=i;	}
		else	if (opt==2)	add[p].push_back((dt){b,i});
		else	cheng[++tot]=((Dt){b,i});
	}
	For(i,1,k){
		if (st[i]>a[i])	add[i].push_back((dt){st[i]-a[i],cho[i]});
		ll sum=a[i];
		sort(add[i].begin(),add[i].end(),cmp1);
		for(ll j=0;j<add[i].size();j++)	cheng[++tot]=(Dt){1.0*(add[i][j].v+sum)/sum,add[i][j].id},sum+=add[i][j].v;
	}sort(cheng+1,cheng+tot+1,cmp2);
	writeln(min(tot,m));
	For(i,1,min(tot,m))	if (op[cheng[i].id]==1)printf("%lld ",cheng[i].id);
	For(i,1,min(tot,m))	if (op[cheng[i].id]==2)printf("%lld ",cheng[i].id);
	For(i,1,min(tot,m))	if (op[cheng[i].id]==3)printf("%lld ",cheng[i].id);

}/*
kn
1.a[i]=b
2.a[i]+=b
3.a[i]*=b
ib
m

*/