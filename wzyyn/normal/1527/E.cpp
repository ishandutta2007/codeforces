#include<bits/stdc++.h>
using namespace std;

const int N=35005;
int n,a[N],pre[N],la[N];
int f[N],g[N],k;
int tg[N*4],t[N*4];
void build(int k,int l,int r){
	t[k]=1<<30;
	tg[k]=0;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v;
		t[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	t[k]=tg[k]+min(t[k*2],t[k*2+1]);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=la[a[i]];
		la[a[i]]=i;
	}
	f[0]=0;
	for (int i=1;i<=n;i++)
		f[i]=1<<30;
	for (int i=1;i<=k;i++){
		build(1,0,n);
		for (int j=1;j<=n;j++){
			change(1,0,n,j-1,j-1,-(1<<30)+f[j-1]);
			if (pre[j])	change(1,0,n,0,pre[j]-1,j-pre[j]);
			g[j]=t[1];
			//cout<<j<<' '<<g[j]<<' '<<f[j]<<' '<<pre[j]<<endl;
		}
		memcpy(f,g,sizeof(f));
	}
	cout<<f[n]<<endl;
}