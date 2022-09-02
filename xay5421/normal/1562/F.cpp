// author: xay5421
// created: Thu Aug 26 22:35:19 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=200005;
int T,n,id[N];
LL ans[N],w[N];
bool ban[N];
int p[N];
void sieve(){
	ban[0]=ban[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i])p[++*p]=i;
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	int cnt=0;
	for(int i=1,j;i<N;i=j){
		j=i+1;
		while(j<N&&ban[i]==ban[j])++j;
		if(ban[i])cnt=max(cnt,j-i);
	}
	D("mx=%d\n",cnt);
}
LL ask(int x,int y){
	printf("? %d %d\n",id[x],id[y]);
	fflush(stdout);
	LL z;
	scanf("%lld",&z);
	return z;
}
vector<int>bin[505];
int main(){
	sieve();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)id[i]=i;
		if(n<=100){
			rep(i,1,n)ans[i]=0;
			rep(i,1,n){
				rep(j,i+1,n){
					LL t=ask(i,j);
					ans[i]=__gcd(ans[i],t);
					ans[j]=__gcd(ans[j],t);
				}
			}
			if(n==3){
				vector<pair<int,int> >v{{ans[1],1},{ans[2],2},{ans[3],3}};
				sort(v.begin(),v.end());
				if((~v[0].first&1)&&(~v[1].first&1)&&(~v[2].first&1))ans[v[2].second]>>=1;
			}
			printf("! ");
			rep(i,1,n)printf("%lld%c" ,ans[i],i==n?'\n':' ');
			fflush(stdout);
			continue;
		}
		rep(i,1,n)w[i]=0;
		shuffle(id+1,id+1+n,rng);
		int pos=-1,prime=-1;
		for(int i=1,_=1;_<=500;i=i%n+1,++_){
			rep(__,1,5){
				int tmp;
				while(tmp=rng()%n+1,tmp==i);
				w[i]=__gcd(w[i],ask(i,tmp));
			}
			if(w[i]<N&&!ban[w[i]]){
				if(prime<w[i])prime=w[i],pos=i;
			}
		}
		w[pos]=prime;
		rep(i,1,n)if(i!=pos)w[i]=ask(i,pos)/prime;
		rep(i,1,n)ans[id[i]]=w[i];
		printf("! ");
		rep(i,1,n)printf("%lld%c",ans[i],i==n?'\n':' ');
		fflush(stdout);
	}
	return 0;
}