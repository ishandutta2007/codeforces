#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int getd(long long K){
	int num=1;
	while (K!=1){
		num++; K=K>>1;
	}
	return num;
}
long long num[70],A[70],B[70];
void printpath(long long k1,int d){
	if (d==0) return;
	long long id=k1-num[d];
	//cout<<k1<<" "<<d<<" "<<id<<" "<<num[d]<<endl;
	long long vid=(id-A[d]+num[d])%num[d]+num[d];
	long long tid=(id+B[d]+num[d])%num[d]+num[d];
	printf("%lld ",vid); printpath(tid/2,d-1);
}
int main(){
	num[1]=1; for (int i=2;i<=61;i++) num[i]=num[i-1]*2; //cout<<num[61]-1000000000000000000ll<<endl;
	int t; scanf("%d",&t);
	for (;t;t--){
		int k1; long long k2; scanf("%d%lld",&k1,&k2);
		if (k1==1){
			long long k3; scanf("%lld",&k3);
			int d=getd(k2); //cout<<d<<endl;
			A[d]=((A[d]+k3)%num[d]+num[d])%num[d];
		} else if (k1==2){
			long long k3; scanf("%lld",&k3);
			int d=getd(k2);// cout<<d<<endl;
			B[d]=((B[d]+k3)%num[d]+num[d])%num[d];
		} else {
			int d=getd(k2);
			long long id=k2-num[d];
			long long tid=(id+A[d]+num[d])%num[d]+num[d];
			printpath(tid,getd(tid)); printf("\n");
		}
	}
}