#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll maxn=800010;
ll c[]={2,0,1,7},d[]={2,0,1,6},f[10],g[10],n,Q;
struct data{	ll m[5][5];	}new_nod,tr[maxn];
char s[maxn];
ll get(char c){
	if (c=='2')	return 1;
	if (c=='0')	return 2;
	if (c=='1')	return 3;
	if (c=='7')	return 4;
	if (c=='6')	return 5;
	return 0;
}
void build(ll l,ll r,ll p){
	if (l==r){
		tr[p]=new_nod;	ll nn=get(s[l]);
		if (!nn)	For(i,0,4)	tr[p].m[i][i]=0;
		else if (nn==5)	For(i,0,4)	tr[p].m[i][i]=i>=3;
		else{
			For(i,0,4)	tr[p].m[i][i]=0;
			tr[p].m[nn-1][nn]=0;
			tr[p].m[nn-1][nn-1]=1;
		}
		/*For(i,0,4){
			For(j,0,4)	printf("%lld	",tr[p].m[i][j]);
			puts("");
		}puts("----------------------");*/
		return;
	}
	ll mid=(l+r)>>1;
	tr[p]=new_nod;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	For(i,0,4)	For(j,0,4)	For(k,0,4)	tr[p].m[i][k]=min(tr[p].m[i][k],tr[p<<1].m[i][j]+tr[p<<1|1].m[j][k]);
	/*if (p==1){
		For(i,0,4){
			For(j,0,4)	printf("%lld	",tr[p].m[i][j]);
			puts("");
		}puts("----------------------");
	}*/
}
void query(ll l,ll r,ll p,ll s,ll t){
	if (l==s&&r==t){
		g[0]=g[1]=g[2]=g[3]=g[4]=1e9;
		For(i,0,4)	For(j,0,4)	g[j]=min(g[j],f[i]+tr[p].m[i][j]);
		f[0]=g[0];	f[1]=g[1];	f[2]=g[2];	f[3]=g[3];	f[4]=g[4];
		return;
	}
	ll mid=(l+r)>>1;
	if (t<=mid)	query(l,mid,p<<1,s,t);
	else if (s>mid)	query(mid+1,r,p<<1|1,s,t);
	else	query(l,mid,p<<1,s,mid),query(mid+1,r,p<<1|1,mid+1,t);
}
int main(){
//	freopen("a.in","r",stdin);
	For(i,0,4)	For(j,0,4)	new_nod.m[i][j]=1e9;//1e9
	n=read();	Q=read();
	scanf("%s",s+1);	build(1,n,1);
	while(Q--){
		ll x=read(),y=read();
		f[0]=0;	f[1]=f[2]=f[3]=f[4]=1e9;	query(1,n,1,x,y);
		if (f[4]<1e9)	writeln(f[4]);
		else	puts("-1");
	}
}