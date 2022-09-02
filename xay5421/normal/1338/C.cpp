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
int T;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	const int a[]={0,2,3,1};
	scanf("%d",&T);
	while(T--){
		LL n;
		scanf("%lld",&n);
		LL n_=(n-1)%3+1;
		n=(n-1)/3+1;
		
		LL l=0,tt=1,w1=1,w2=2;
		while(n>tt){
			l+=2;
			tt+=1LL<<l;
			w1=1LL<<l;
			w2=1LL<<(l+1);
		}
		tt-=1LL<<l;
		n-=tt+1;
		w1+=n;
		while(l>=0){
			w2+=(LL)a[(n>>l)&3]<<l;
			l-=2;
		}
		if(n_==1)printf("%lld\n",w1);
		else if(n_==2)printf("%lld\n",w2);
		else printf("%lld\n",w1^w2);
	}
	return 0;
}