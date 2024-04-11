#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[1100],B[2100],n,K,p;
int check(long long lim){
	int now=1;
	for (int i=1;i<=K;i++)
		if (abs(B[i]-A[now])+abs(B[i]-p)<=lim){
			now++; if (now>n) return 1;
		}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&K,&p);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=K;i++) scanf("%d",&B[i]);
	sort(A+1,A+n+1);
	sort(B+1,B+K+1);
	long long l=0,r=2e9+10,ans=0;
	while (l<r){
		long long mid=l+r>>1;
		if (check(mid)) r=mid,ans=mid; else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}