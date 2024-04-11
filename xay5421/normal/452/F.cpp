#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int B=3,P=998244853,N=300005;
int n,a[N],t[N],T[N],pw[N],ipw[N];
void addx(int&k1,int k2){
	(k1+=k2)>=P&&(k1-=P);
}
void upd(int*t,int k1,int k2){
	for(int i=k1;i<=n;i+=i&-i)addx(t[i],k2);
}
int qry(int*t,int k1){
	int k2=0;
	for(int i=k1;i;i&=i-1)addx(k2,t[i]);
	return k2;
}
int qry(int*t,int l,int r){
	return (qry(t,r)-(l<=0?0:qry(t,l-1))+P)%P;
}
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int main(){
	pw[0]=ipw[0]=1;
	const int invB=fpow(B,P-2);
	rep(i,1,N-1)pw[i]=1LL*pw[i-1]*B%P,ipw[i]=1LL*ipw[i-1]*invB%P;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		upd(t,a[i],pw[a[i]]);
		upd(T,a[i],pw[n-a[i]+1]);
		int len=min(a[i],n-a[i]+1);
		int k1=1LL*qry(t,a[i]-len+1,a[i])*ipw[a[i]]%P;
		int k2=1LL*qry(T,a[i],a[i]+len-1)*ipw[n-a[i]+1]%P;
		if(k1!=k2){
			cerr<<i<<endl;
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}