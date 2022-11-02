#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define ls(x) x<<1
#define rs(x) x<<1|1
int read(){
	char ch=getchar();int p=1,w=0;
	while(ch>'9'||ch<'0'){ch=getchar();if(ch=='-') p=-1;}
	while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
	return p*w;
}
int d[1000009],low[1000009],pri[1000009],tot,maxn;
bool f[1000009];
int max(int x,int y){return x>y?x:y;}
void init(){
	memset(f,0,sizeof(f));
	f[1]=1,low[1]=1,d[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!f[i]) pri[++tot]=i,low[i]=2,d[i]=2;
		for(int j=1;j<=tot&&i*pri[j]<=maxn;j++){
			f[i*pri[j]]=1,low[i*pri[j]]=2,d[i*pri[j]]=d[i]*2;
			if(i%pri[j]==0){
				low[i*pri[j]]=low[i]+1,d[i*pri[j]]=d[i]/low[i]*low[i*pri[j]];
				break;
			}
		}
	}
}
int n,m,a[300009];
struct segment{ll sum;int mx;}t[1200009];
void build(int c,int l,int r){
	if(l==r){t[c].sum=a[l],t[c].mx=a[l];return ;}
	int mid=(l+r)>>1;
	build(ls(c),l,mid);
	build(rs(c),mid+1,r);
	t[c].sum=t[ls(c)].sum+t[rs(c)].sum;
	t[c].mx=max(t[ls(c)].mx,t[rs(c)].mx);
	return ;
}
void modify(int c,int l,int r,int x,int y){
	if(t[c].mx<=2) return ;
	if(l==r){t[c].sum=d[t[c].sum],t[c].mx=t[c].sum;return ;}
	int mid=(l+r)>>1;
	if(x<=mid) modify(ls(c),l,mid,x,y);
	if(y>mid) modify(rs(c),mid+1,r,x,y);
	t[c].sum=t[ls(c)].sum+t[rs(c)].sum;
	t[c].mx=max(t[ls(c)].mx,t[rs(c)].mx);
	return ;
}
ll query(int c,int l,int r,int x,int y){
	 if(t[c].mx==1){
	 	int L=l>x?l:x,R=r<y?r:y;
	 	return (R-L+1);
	 }
	if(x<=l&&r<=y) return t[c].sum;
	int mid=(l+r)>>1;ll ans=0;
	if(x<=mid) ans+=query(ls(c),l,mid,x,y);
	if(y>mid) ans+=query(rs(c),mid+1,r,x,y);
	return ans;
}
int main(){
	n=read(),m=read(),maxn=0;
	for(register int i=1;i<=n;i++) a[i]=read(),maxn=max(a[i],maxn);
	init();
	build(1,1,n);
	while(m--){
		int c=read(),l=read(),r=read();
		if(c==1) modify(1,1,n,l,r);
		if(c==2){printf("%lld\n",query(1,1,n,l,r));}
	}
	return 0;
}
//12