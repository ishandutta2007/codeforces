#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=525000;
const int mo=1000000000;
int tg[M],s1[M],s2[M];
int f[N],sum[N],n,q;
void chg(int k,int l,int r,int v){
	tg[k]=(tg[k]+v)%mo;
	s1[k]=(s1[k]+1ll*v*sum[r-l])%mo;
	s2[k]=(s2[k]+1ll*v*(sum[r-l+1]+mo-1))%mo;
}
void pushdown(int k,int l,int r){
	if (!tg[k]) return;
	int mid=(l+r)/2;
	chg(k*2,l,mid,tg[k]);
	chg(k*2+1,mid+1,r,tg[k]);
	tg[k]=0;
}
int move(int s1,int s2,int k){
	if (k==-1) return s1;
	return (1ll*s1*(k==0?0:f[k-1])+1ll*s2*f[k])%mo;
}
void pushup(int k,int l,int r){
	int mid=(l+r)/2,kk=mid-l;
	s1[k]=(move(s1[k*2+1],s2[k*2+1],kk)+s1[k*2])%mo;
	s2[k]=(move(s1[k*2+1],s2[k*2+1],kk+1)+s2[k*2])%mo;
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		s1[k]=s2[k]=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k,l,r);
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	pushup(k,l,r);
}
void add(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		chg(k,l,r,v);
		return;
	}
	int mid=(l+r)/2;
	pushdown(k,l,r);
	if (x<=mid) add(k*2,l,mid,x,y,v);
	if (y>mid) add(k*2+1,mid+1,r,x,y,v);
	pushup(k,l,r);
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return move(s1[k],s2[k],l-x-1);
	int mid=(l+r)/2,ans=0;
	pushdown(k,l,r);
	if (x<=mid) ans+=ask(k*2,l,mid,x,y);
	if (y>mid) ans+=ask(k*2+1,mid+1,r,x,y);
	return ans%mo;
}
int main(){
	f[0]=f[1]=sum[0]=1; sum[1]=2;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%mo;
		sum[i]=(sum[i-1]+f[i])%mo;
	}
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		change(1,1,n,i,x);
	}
	while (q--){
		int tp,x,y,k;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,x,y);
		else if (tp==2) printf("%d\n",ask(1,1,n,x,y));
		else scanf("%d",&k),add(1,1,n,x,y,k);
	}
}