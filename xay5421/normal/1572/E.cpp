// author: xay5421
// created: Mon Sep 20 21:27:30 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=205;
int n,K,x[N],y[N];
struct node{
	LL area;
	int cnt;
	bool operator<(const node&k)const{
		return cnt!=k.cnt?cnt<k.cnt:area<k.area;
	}
}f[N][N];
LL cross(LL a,LL b,LL c,LL d){
	return a*d-b*c;
}
bool chk(LL mid){
	rep(i,1,n)rep(j,i+2,n){
		f[i][j]=(node){(LL)1e18,(int)-1e9};
	}
	rep(len,3,n){
		rep(i,1,n){
			int j=i+len-1;
			if(j>n)break;
			rep(k,i+1,j-1){
				node cur=(node){f[i][k].area+f[k][j].area+cross(x[k]-x[i],y[k]-y[i],x[j]-x[i],y[j]-y[i]),f[i][k].cnt+f[k][j].cnt};
				if(cur.area>=mid){
					cur.area=0,++cur.cnt;
				}
				f[i][j]=max(f[i][j],cur);
			}
		}
	}
	return f[1][n].cnt>=K;
}
int main(){
	scanf("%d%d",&n,&K),++K;
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	LL l=0,r=1e18,ans=0;
	chk(11);
	while(l<=r){
		LL mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}