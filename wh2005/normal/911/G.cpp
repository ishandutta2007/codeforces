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
using namespace std;
int n,q,a[200009],rt[109],tot;
struct pp{int L,R;}t[10000009];
int b[200009];
int read(){
	int f=1,w=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=w*10+ch-'0';
		ch=getchar();
	}
	return f*w;
}
void add(int &c,int l,int r,int x){
	if(!c) c=++tot;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) add(t[c].L,l,mid,x);
	if(x>mid) add(t[c].R,mid+1,r,x);
	return;
}
int merge(int u,int v){
	if(!u) return v;
	if(!v) return u;
	int cnt=++tot;
	t[cnt].L=merge(t[u].L,t[v].L);
	t[cnt].R=merge(t[u].R,t[v].R);
	return cnt;
}
void modify(int &c,int &k,int l,int r,int x,int y){
	if(!c) return ;
	if(x<=l&&r<=y){
		if(!k){
			k=c,c=0;
			return ;
		}
		k=merge(k,c);
		c=0;
		return ;
	}
	if(!k) k=++tot;
	int mid=(l+r)>>1;
	if(x<=mid) modify(t[c].L,t[k].L,l,mid,x,y);
	if(y>mid) modify(t[c].R,t[k].R,mid+1,r,x,y);
	return ;
}
void flag(int x,int c,int l,int r){
	if(!c) return ;
	if(l==r){
		b[l]=x;
		return ;
	}
	int mid=(l+r)>>1;
	flag(x,t[c].L,l,mid);
	flag(x,t[c].R,mid+1,r);
	return ;
}
int main(){
	tot=0;
	int maxn=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxn=max(a[i],maxn);
		add(rt[a[i]],1,n,i);
	}
	q=read();
	while(q--){
		int l=read(),r=read(),x=read(),y=read();
		if(x==y) continue;
		maxn=max(y,maxn);
		modify(rt[x],rt[y],1,n,l,r);
	}
	for(int i=1;i<=maxn;i++){
		flag(i,rt[i],1,n);
	}
	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}