// author: xay5421
// created: Fri Apr 23 10:03:44 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,INF=1e9;
int n,a[N],b[N],c[N],f[N],suf[N],ans;
void sol(int l,int r){
	int w[2]={INF,INF},v[2]={0,0},u[2]={0,0};
	rep(i,l,r){
		if(w[0]>w[1])swap(w[0],w[1]),swap(v[0],v[1]),swap(u[0],u[1]);
		if(f[i]<w[0])w[0]=f[i],++u[0],v[0]+=c[i];
		else if(f[i]<w[1])w[1]=f[i],++u[1],v[1]+=c[i];
		else puts("-1"),exit(0);
	}
	if(v[0]>v[1])swap(w[0],w[1]),swap(v[0],v[1]),swap(u[0],u[1]);
	ans+=min(v[0]+u[1]-v[1],v[1]+u[0]-v[0]);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<=n&&b[i]<=n)puts("-1"),exit(0);
		if(a[i]<=n)f[a[i]]=b[i],c[a[i]]=0;
		else f[b[i]]=a[i],c[b[i]]=1;
	}
	per(i,n,1){
		suf[i]=max(suf[i+1],f[i]);
	}
	int mn=1e9;
	int lst=1;
	rep(i,1,n){
		mn=min(mn,f[i]);
		if(mn>suf[i+1]){
			sol(lst,i);
			lst=i+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}