#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[210000],n,m,a[210000],b[210000];
int compare(int k1,int k2){
	return x[k1]<x[k2];
}
int findrwhere(int k){
	int l=1,r=n+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (x[a[mid]]<=k){
			ans=a[mid]; l=mid+1;
		} else r=mid;
	}
	return ans;
}
int findlwhere(int k){
	int l=1,r=n+1,ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (x[a[mid]]>=k){
			ans=a[mid]; r=mid;
		} else l=mid+1;
	}
	return ans;
}
int solve(int k1,int k2,int k3){
//	cout<<"solve "<<k1<<" "<<k2<<" "<<k3<<endl;
	if (k2==0){
		int k4=findlwhere(x[k1]-k3);
		if (k1==k4) return k1;
		int dis=x[k1]-x[k4],k5=k3/dis;
		if (k5&1) return solve(k4,1,k3%dis); else return solve(k1,0,k3%dis);
	} else {
		int k4=findrwhere(x[k1]+k3);
		if (k1==k4) return k1;
		int dis=x[k4]-x[k1],k5=k3/dis;
		if (k5&1) return solve(k4,0,k3%dis); else return solve(k1,1,k3%dis);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,compare);
	for (int i=1;i<=n;i++) b[a[i]]=i;
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		int k3=findrwhere(x[k1]+k2);
		printf("%d\n",solve(k3,0,k2-(x[k3]-x[k1])));
	}
	return 0;
}