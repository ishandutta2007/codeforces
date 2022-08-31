#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[310000],n,ans[310000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	int tot=0;
	for (int i=1;i<=n;i++) tot=max(tot,A[i]);
	ans[n-1]=tot;
	for (int i=1;i<n;i++){
		int num=max(A[i],A[i+1]);
		int l=i-1,r=n-i-1;
		ans[abs(l-r)]=max(ans[abs(l-r)],num);
	}
	for (int i=2;i<n;i++){
		int num=min(max(A[i-1],A[i+1]),A[i]);
		int l=i-2,r=n-i-1;
		ans[abs(l-r)]=max(ans[abs(l-r)],num);
	}
	for (int i=3;i<=n;i++) ans[i]=max(ans[i],ans[i-2]);
	for (int i=0;i<n;i++) printf("%d ",ans[i]);
}