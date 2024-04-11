// author: xay5421
// created: Sun Mar 21 23:16:38 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int T,cnt;
LL tar;
int ask(LL x){
	++cnt;
#ifdef xay5421
	if(x<=99999999999808LL)return 1;
	else return 0;
#else
	printf("? %lld\n",x);
	fflush(stdout);
	string s;
	cin>>s;
	if(s[0]=='L')return 1;
	else return 0;
#endif
}
int main(){
	scanf("%d",&T);
	while(T--){
		if(ask(1)==0){
			puts("! 0");
			fflush(stdout);
			continue;
		}else{
			LL lb=1,rb=1e14;
			LL now=2,bs=lb;
			while(lb<rb){
				LL mid=(lb+rb+1)>>1;
				if(now>=(105-cnt)*rb);
				else if(now>=rb*5)mid=lb+0.4*(rb-lb+1);
				else mid=lb+0.3*(rb-lb+1);
				mid=max(mid,lb+1);
				mid=min(mid,rb);
				mid=min(mid,now);
				mid=max(mid,lb);
				if(ask(mid)){
					lb=mid;
					bs=max(bs,lb);
					now+=mid;
				}else{
					rb=mid-1;
					now-=mid;
				}
			}
			if(lb==rb){
				printf("! %lld\n",lb);
				fflush(stdout);
			}
		}
		D("cnt=%d\n",cnt);
		cnt=0;
	}
	return 0;
}