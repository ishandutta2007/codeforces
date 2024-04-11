#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
	int w,where;
}A[410000];
int x[210000],w[210000],n,f[410000],now,B[410000],a[410000],dp[210000];
int compare(atom k1,atom k2){
	return k1.w<k2.w;
}
int compare2(int k1,int k2){
	return x[k1]<x[k2];
}
void add(int k1,int k2){
	for (;k1<=now;k1+=k1&(-k1)) B[k1]=max(B[k1],k2);
}
int find(int k1){
	int ans=0; for (;k1;k1-=k1&(-k1)) ans=max(ans,B[k1]); return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&w[i]);
	for (int i=1;i<=n;i++){
		A[i]=(atom){x[i]+w[i],i}; A[i+n]=(atom){x[i]-w[i],i+n};
	}
	sort(A+1,A+n*2+1,compare);
	f[A[1].where]=1; now=1;
	for (int i=2;i<=n*2;i++){
		if (A[i].w!=A[i-1].w) now++; f[A[i].where]=now;
	}
	for (int i=1;i<=n;i++) a[i]=i; sort(a+1,a+n+1,compare2);
	for (int i=1;i<=n;i++){
		dp[a[i]]=find(f[a[i]+n])+1; add(f[a[i]],dp[a[i]]);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl; return 0;
}