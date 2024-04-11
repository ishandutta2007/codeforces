#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+10;
long long A[N],B[N];
int x[N];
int n;
void addin(int l,int r,int k,int b){
	A[l]+=b; B[l]+=k;
	A[r+1]-=b; B[r+1]-=k;
}
void add(int l,int r,int where,int w){
	if (l>r) return;
	int wherel=(l+where-1)%n+1,wherer=(r+where-1)%n+1;
	int wl=abs(wherel-w),wr=abs(wherer-w);
	if (wl<=wr) addin(l,r,wl-l,1);
	else addin(l,r,wl+l,-1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++){
		int k1=n-i,k2=(x[i]-i+n)%n;
		if (k1>k2) swap(k1,k2);
		add(0,k1,i,x[i]);
		add(k1+1,k2,i,x[i]);
		add(k2+1,n-1,i,x[i]);
	}
	for (int i=1;i<=n;i++) A[i]+=A[i-1],B[i]+=B[i-1];
	long long ans=1e18;
	int where=0;
	for (int i=0;i<n;i++){
		long long w=1ll*A[i]*i+B[i];
		if (w<ans) ans=w,where=i;
	}
	cout<<ans<<" "<<where<<endl;
	return 0;
}