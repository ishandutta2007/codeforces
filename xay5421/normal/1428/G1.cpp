// author: xay5421
// created: Tue Oct 26 23:20:24 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=1000005;
int K,F[10];
LL dp[N];
void ps(int w,LL p){
	per(i,1000000,w){
		dp[i]=max(dp[i],dp[i-w]+p);
	}
}
void push(int w,int p){
	int rem=min(K,1000000/w);
	for(int i=1;i<rem;i<<=1){
		rem-=i;
		ps(w*i,1LL*p*i);
	}
	ps(w*rem,1LL*p*rem);
}
int main(){
	scanf("%d",&K),K=(K-1)*3;
	rep(i,0,5)scanf("%d",&F[i]);
	rep(i,0,999999){
		int x=i;
		rep(j,0,5){
			dp[i]+=1LL*F[j]*((x%10)%3==0?(x%10)/3:0);
			x/=10;
		}
	}
	int pw=1;
	rep(i,0,5)push(pw*3,F[i]),pw*=10;
	int Q;
	scanf("%d",&Q);
	while(Q--){int x;scanf("%d",&x),printf("%lld\n",dp[x]);}
	return 0;
}