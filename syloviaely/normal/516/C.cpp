#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long long x[210000],y[210000],d[210000],ans,w[2100000];
int n,m,h[210000],A[2100000],B[2100000];
struct atom{
	int k1,k2;
};
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		A[k1]=k2; B[k1]=k2; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	if (x[A[k1*2]]<=x[A[k1*2+1]]) A[k1]=A[k1*2+1]; else A[k1]=A[k1*2]; 
	if (y[B[k1*2]]<=y[B[k1*2+1]]) B[k1]=B[k1*2+1]; else B[k1]=B[k1*2];
	w[k1]=max(x[A[k1*2+1]]+y[B[k1*2]],max(w[k1*2],w[k1*2+1]));
}
atom findans(int k1,int k2,int k3,int k4,int k5){
	if (k2>=k4&&k3<=k5){
		ans=max(ans,w[k1]); return (atom){A[k1],B[k1]};
	}
	int mid=k2+k3>>1;
	if (mid>=k5) return findans(k1*2,k2,mid,k4,k5);
	if (mid<k4) return findans(k1*2+1,mid+1,k3,k4,k5);
	atom k6=findans(k1*2,k2,mid,k4,k5),k7=findans(k1*2+1,mid+1,k3,k4,k5);
	ans=max(ans,x[k7.k1]+y[k6.k2]);
	atom k8;
	if (x[k6.k1]<x[k7.k1]) k8.k1=k7.k1; else k8.k1=k6.k1;
	if (y[k6.k2]<y[k7.k2]) k8.k2=k7.k2; else k8.k2=k6.k2;
	return k8;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&d[i+1]);
	for (int i=n+2;i<=n*2;i++) d[i]=d[i-n];
    for (int i=1;i<=n;i++) scanf("%d",&h[i]);
    for (int i=1;i<=n*2;i++) d[i]+=d[i-1];
    for (int i=n+1;i<=n*2;i++) h[i]=h[i-n];
    for (int i=1;i<=n*2;i++) x[i]=d[i]+h[i]*2;
    for (int i=1;i<=n*2;i++) y[i]=h[i]*2-d[i];
    buildtree(1,1,n*2);
    for (;m;m--){
    	int l,r; scanf("%d%d",&l,&r); ans=0; int k1,k2;
    	if (l>r){
			k1=r+1; k2=l-1;
		} else {
			k1=r+1; k2=l-1+n;
		}
		findans(1,1,n*2,k1,k2);
		printf("%I64d\n",ans);
	}
    return 0;
}