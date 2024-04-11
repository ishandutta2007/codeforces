// author: xay5421
// created: Tue Sep 14 19:53:12 2021
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
typedef long long LL;
const int N=150005;
int n,p[N],t[N],id[N];
struct node{
	int p;
	LL l,r;
}b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	LL T=0;
	rep(i,1,n)scanf("%d",&t[i]),T+=t[i],id[i]=i;
	auto cmp=[&](auto x,auto y){return 1LL*p[x]*t[y]>1LL*p[y]*t[x];};
	sort(id+1,id+1+n,cmp);
	LL sum=0;
	for(int i=1,j;i<=n;i=j){
		LL old=sum;
		j=i;
		while(j<=n&&!cmp(id[i],id[j]))sum+=t[id[j]],++j;
		rep(k,i,j-1){
			b[id[k]]=(node){p[id[k]],old+t[id[k]],sum};
		}
	}
	sort(b+1,b+1+n,[&](auto x,auto y){return x.p<y.p;});
	auto chk=[&](auto c)->int{
		double mx=0;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&b[i].p==b[j].p)++j;
			rep(k,i,j-1){
				if(b[k].p*(1-c*b[k].r/T)<mx){
					return 0;
				}
			}
			rep(k,i,j-1)mx=max(mx,b[k].p*(1-c*b[k].l/T));
		}
		return 1;
	};
	double l=0,r=1;
	rep(_,1,25){
		double mid=(l+r)/2.;
		if(chk(mid))l=mid;
		else r=mid;
	}
	printf("%.20f\n",l);
	return 0;
}