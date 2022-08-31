#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[210000],x[210000],n,y[210000];
int compare(int k1,int k2){
	return x[k1]+k1<x[k2]+k2;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,compare);
	for (int i=1;i<=n;i++) y[i]=x[a[i]]+a[i]-i;
	for (int i=1;i<n;i++) if (y[i]>y[i+1]){
		printf(":(\n"); return 0;
	}
	for (int i=1;i<=n;i++) printf("%d ",y[i]); printf("\n");
	return 0;
}