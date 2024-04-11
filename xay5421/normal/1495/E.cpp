// author: xay5421
// created: Thu Mar 11 10:35:24 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=5000005;
int n,m,t[N],a[N],ans[N];
int main(){
	scanf("%d%d",&n,&m);
	int lst=0;
	rep(_,1,m){
		int p,k,seed,base;
		scanf("%d%d%d%d",&p,&k,&seed,&base);
		auto rnd=[&](){
			int ret=seed;
			seed=(1LL*seed*base+233)%1000000007;
			return ret;
		};
		rep(i,lst+1,p){
			t[i]=rnd()%2+1;
			a[i]=rnd()%k+1;
		}
		lst=p;
	}
	LL x=0;
	rep(i,1,n){
		x+=t[i]==1?a[i]:-a[i];
	}
	if(x>0)rep(i,1,n)t[i]=3-t[i];
	LL mn=1e18;
	int pos=-1;
	x=0;
	rep(i,1,n){
		x+=t[i]==1?a[i]:-a[i];
		if(x<mn)mn=x,pos=i;
	}
	x=0;
	rep(i,pos+1,n){
		if(t[i]==1){
			ans[i]=a[i];
		}else{
			ans[i]=min((LL)a[i],x);
		}
		x+=t[i]==1?a[i]:-a[i];
		if(x<0)x=0;
	}
	if(t[1]==2)++x;
	if(x<0)x=0;
	rep(i,1,pos){
		if(t[i]==1){
			ans[i]=a[i];
		}else{
			ans[i]=min((LL)a[i],x);
		}
		x+=t[i]==1?a[i]:-a[i];
		if(x<0)x=0;
	}
	int res=1;
	rep(i,1,n)res=1LL*res*(((ans[i]^(1LL*i*i))+1)%1000000007)%1000000007;
	printf("%d\n",res);
	return 0;
}