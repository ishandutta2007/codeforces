/*
Contest: -
Problem: Codeforces 1312G
Author: tzc_wk
Time: 2020.7.22
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),nd[1000005],x[1000005];
int son[1000005][27],siz[1000005],pcnt=1,f[1000005];
struct node{
	int l,r,mn,lz;
} s[1000005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r){
		s[k].mn=0x3f3f3f3f;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
inline void pushdown(int k){
	if(s[k].lz){
		s[k<<1].mn+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mn+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
inline void modify(int k,int l,int r,int x){
	if(l>r)	return;
	if(l<=s[k].l&&s[k].r<=r){
		s[k].mn+=x;
		s[k].lz+=x;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)	modify(k<<1,l,r,x);
	else if(l>mid)	modify(k<<1|1,l,r,x);
	else	modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
inline void change(int k,int x,int v){
	if(s[k].l==s[k].r){
		s[k].mn=v;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid)	change(k<<1,x,v);
	else		change(k<<1|1,x,v);
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
inline int query(int k,int l,int r){
	if(l>r)	return 0x3f3f3f3f;
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].mn;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)	return query(k<<1,l,r);
	else if(l>mid)	return query(k<<1|1,l,r);
	else	return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
inline void dp(int x,int dep,int pre){
	f[x]=pre+1;
	if(siz[x])	f[x]=min(f[x],query(1,1,dep));
	change(1,dep,f[x]+1);
	modify(1,1,dep+1,siz[x]);
//	printf("%d %d\n",x,f[x]);
	fz(i,0,25){
		if(son[x][i]){
			dp(son[x][i],dep+1,f[x]);
		}
	}
	change(1,dep,0x3f3f3f3f);
}
signed main(){
	nd[0]=1;
	fz(i,1,n){
		char c;int x;
		cin>>x>>c;
		son[nd[x]][c-'a']=++pcnt;
		nd[i]=pcnt;
//		printf("%d\n",nd[i]);
	}
	int p=read();
	fz(i,1,p){
		x[i]=read();
		siz[nd[x[i]]]++;
	}
	build(1,1,n+2);
	dp(1,1,-1);
	fz(i,1,p)	cout<<f[nd[x[i]]]<<" ";
	return 0;
}//