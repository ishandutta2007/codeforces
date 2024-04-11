// author: xay5421
// created: Sat Jun 12 21:23:16 2021
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
int n,p,q,num[135];
unsigned coef[135];
int main(){
	scanf("%d%d%d",&n,&p,&q);
	rep(i,0,p){
		if(i){
			num[i]=n-i+1;
			int rem=i;
			per(j,i,1){
				int t=__gcd(num[j],rem);
				num[j]/=t,rem/=t;
				if(rem==1)break;
			}
		}
		coef[i]=1;
		rep(j,1,i)coef[i]*=num[j];
	}
	unsigned ans=0;
	rep(d,1,q){
		unsigned res=0,pw=1;
		rep(i,0,p)if(i<n){
			if(i)pw=pw*d;
			res+=pw*coef[i];
		}
		ans^=res*d;
	}
	printf("%u\n",ans);
	return 0;
}