#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
LL L,R;
int sz;
vector<array<int,10> >vs[20];
void sol(LL k2,LL k3,LL k4,LL k5,array<int,10>k6,int k7){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		D("! [%lld,%lld] [%lld,%lld]\n",k2,k3,k4,k5);
		vs[k7].pb(k6);
		sz+=1;
		return;
	}
	LL pw=(k3-k2+1)/10;
	for(int i=0;i<=9;i+=1){
		if(i)k6[i]+=1;
		sol(k2+pw*i,k2+pw*(i+1)-1,k4,k5,k6,k7-(i==0));
		if(i)k6[i]-=1;
	}
}
int tt[10];
int ans;
void dfs(int k1,int k2){
	if(k1){
		per(a,18,k1){
			for(auto&x:vs[a]){
				if(tt[1]>=x[1]&&tt[2]>=x[2]&&tt[3]>=x[3]&&tt[4]>=x[4]&&tt[5]>=x[5]&&tt[6]>=x[6]&&tt[7]>=x[7]&&tt[8]>=x[8]&&tt[9]>=x[9]){
					a=-1;
					ans+=1;
					break;
				}
			}
		}
	}
	if(k1>=18){
		return;
	}
	rep(x,k2,9){
		++tt[x];
		dfs(k1+1,x);
		--tt[x];
	}
}
mt19937 rng(233);
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%lld%lld",&L,&R);
	if(R==1e18){
		if(L==1e18)puts("1"),exit(0);
		R-=1;
		vs[18].pb(array<int,10>{0,1,0,0,0,0,0,0,0,0});
	}
	sol(0,((LL)1e18)-1,L,R,array<int,10>{0},18);
	D("sz=%d\n",sz);
	rep(i,0,18)shuffle(vs[i].begin(),vs[i].end(),rng);
	dfs(0,1);
	printf("%d\n",ans);
	return 0;
}