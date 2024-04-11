#include<bits/stdc++.h>
using namespace std;

const int N=1<<18|5;
int n,m,Q,l[N],r[N];
int mn[N*2],mns[N*2],tg[N*2];
char s[N];
void build(int k,int l,int r){
	mns[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void add(int k,int v){
	mn[k]+=v;
	tg[k]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	add(k*2,tg[k]);
	add(k*2+1,tg[k]);
	tg[k]=0;
}
void pushup(int k){
	mn[k]=min(mn[k*2],mn[k*2+1]);
	mns[k]=(mn[k]==mn[k*2]?mns[k*2]:0)+(mn[k]==mn[k*2+1]?mns[k*2+1]:0); 
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y) return add(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k);
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=(1<<n);i<<=1)
		for (int j=1,k=i;j<=(1<<n);j+=i,k+=i)
			l[++m]=j,r[m]=k;
	build(1,1,1<<n);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++){
		if (s[i]=='1') change(1,1,1<<n,l[i],(l[i]+r[i])/2,1);
		if (s[i]=='0') change(1,1,1<<n,(l[i]+r[i])/2+1,r[i],1);
	}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x;
		char c[5];
		scanf("%d%s",&x,c+1);
		
		if (s[x]=='1')
			change(1,1,1<<n,l[x],(l[x]+r[x])/2,-1);
		if (s[x]=='0')
			change(1,1,1<<n,(l[x]+r[x])/2+1,r[x],-1);
		s[x]=c[1];
		
		if (s[x]=='1')
			change(1,1,1<<n,l[x],(l[x]+r[x])/2,1);
		if (s[x]=='0')
			change(1,1,1<<n,(l[x]+r[x])/2+1,r[x],1);
		cout<<mns[1]<<endl;
	}
}