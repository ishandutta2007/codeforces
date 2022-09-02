#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define SZ(x) ((int)(x).size())
#define PB push_back
using namespace std;
typedef long long LL;
int Query(LL x){
	printf("? %lld\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
LL Guess(LL n){
	LL cur,o;
	auto fun=[&](LL l,LL r){
		vector<LL>v;
		while(l<=r){
			LL mid=(l+r)>>1;
			v.PB(mid);
			l=mid+1;
		}
		cur=1;
		o=1;
		reverse(v.begin(),v.end());
		rep(i,0,SZ(v)-1){
			cur+=v[i]*o;
			o=-o;
			assert(1<=cur&&cur<=n);
		}
		Query(cur);
	};
	LL L=1,R=n-1,ans=n;
	fun(L,R);
	while(L<=R){
		LL mid=(L+R)>>1;
		cur+=mid*o;
		o=-o;
		if(Query(cur)){
			R=mid-1,ans=mid;
		}else L=mid+1;
	}
	assert(R+1==L);
	return ans;
}
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		LL n;scanf("%lld",&n);
		printf("= %lld\n",Guess(n));
		fflush(stdout);
	}
}