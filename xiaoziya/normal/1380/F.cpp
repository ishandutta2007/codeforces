#include<stdio.h>
#include<iostream>
#include<string.h>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=500005,maxt=maxn<<2,mod=998244353;
int n,m;
int a[maxn];
string s;
struct matrix{
	int len,wid;
	int a[3][3];
	matrix operator *(matrix p){
		matrix res;
		res.len=len,res.wid=p.wid,memset(res.a,0,sizeof(res.a));
		for(int i=1;i<=len;i++)
			for(int j=1;j<=p.wid;j++)
				for(int k=1;k<=wid;k++)
					res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*p.a[k][j])%mod;
		return res;
	}
}ini,t[maxt];
inline void pushup(int now){
	t[now]=t[lc(now)]*t[rc(now)];
}
inline void setval(int now,int p){
	t[now].len=t[now].wid=2;
	t[now].a[1][1]=a[p]+1,t[now].a[2][1]=a[p-1]==1? (9-a[p]):0;
	t[now].a[1][2]=1,t[now].a[2][2]=0;
}
void build(int l,int r,int now){
	if(l==r){
		setval(now,l);
		return ;
	}
	build(l,mid,lc(now)),build(mid+1,r,rc(now)),pushup(now);
}
void modify(int l,int r,int now,int p){
	if(l==r){
		setval(now,l);
		return ;
	}
	if(p<=mid)
		modify(l,mid,lc(now),p);
	else modify(mid+1,r,rc(now),p);
	pushup(now);
}
int main(){
	ini.len=1,ini.wid=2,ini.a[1][1]=ini.a[1][2]=1;
	scanf("%d%d",&n,&m),cin>>s;
	for(int i=1;i<=n;i++)
		a[i]=s[i-1]-48;
	build(1,n,1);
	for(int i=1,x,d;i<=m;i++){
		scanf("%d%d",&x,&d),a[x]=d;
		modify(1,n,1,x);
		if(x+1<=n)
			modify(1,n,1,x+1);
		printf("%d\n",(ini*t[1]).a[1][1]);
	}
	return 0;
}