#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long LL;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace PR{
	LL add(LL k1,LL k2,LL P){(k1+=k2)>=P&&(k1-=P);return k1;}
	LL mul(LL k1,LL k2,LL P){
		LL k3=0;
		for(;k2;k2>>=1,k1=add(k1,k1,P))if(k2&1)k3=add(k3,k1,P);
		return k3;
	}
	LL fpow(LL k1,LL k2,LL P){
		k1%=P;
		LL k3=1;
		for(;k2;k2>>=1,k1=mul(k1,k1,P))if(k2&1)k3=mul(k3,k1,P);
		return k3;
	}
	const int N=11,p[N]={2,3,5,7,11,13,17,19,23,29,61};
	bool chk(LL P,LL n){
		if(P%n==0||fpow(n,P-1,P)!=1)return 0;
		LL k=P-1;
		while(~k&1){
			k>>=1;
			LL t=fpow(n,k,P);
			if(t!=1&&t!=P-1)return 0;
			if(t==P-1)return 1;
		}
		return 1;
	}
	bool isp(LL n){
		for(int i=0;i<N;++i){
			if(n==p[i])return 1;
			if(!chk(n,p[i]))return 0;
		}
		return 1;
	}
	vector<LL>d;
	void report(LL x){
		d.push_back(x);
	}
	void work(LL n){
		if(n==1)return;
		if(isp(n)){
			report(n);
			return;
		}
		while(1){
			LL c=rng()%n,x=rng()%n,y=x,i=1,k=2;
			if(c==0||c==2)continue;
			do{
				LL d=__gcd(abs(x-y),n);
				if(d!=1&&d!=n){
					work(d),work(n/d);
					return;
				}
				if(++i==k)y=x,k<<=1;
				x=(mul(x,x,n)+c)%n;
			}while(x!=y);
		}
	}
	vector<pair<LL,int> >sol(LL n){
		d.clear();
		work(n);
		sort(d.begin(),d.end());
		vector<pair<LL,int> >res;
		for(int i=0,j;i<SZ(d);i=j){
			j=i+1;
			while(j<SZ(d)&&d[i]==d[j])++j;
			res.emplace_back(d[i],j-i);
		}
		return res;
	}
}
int fpow(int k1,int k2,int P){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int inv(LL x,int P){
	x=(x%P+P)%P;
	return fpow(x,P-2,P);
}
struct solver{
	vector<LL>dis;
	vector<pair<LL,int> >res;
	int I;
	void init(LL K){
		res=PR::sol(K);
		if(SZ(res)==2){
			I=inv(res[1].X,res[0].X);
		}
		if(SZ(res)>2){
			int n=res[0].X;
			dis.assign(n,INFLL);
			vector<bool>vis(n,0);
			dis[0]=0;
			priority_queue<pair<int,int> >q;
			auto push=[&](int k1){
				q.emplace(-dis[k1],k1);
			};
			push(0);
			while(SZ(q)){
				int k1=q.top().Y;
				q.pop();
				if(vis[k1])continue;
				vis[k1]=1;
				for(auto x:res)if(dis[k1]+x.X<dis[(k1+x.X)%n]){
					dis[(k1+x.X)%n]=dis[k1]+x.X;
					push((k1+x.X)%n);
				}
			}
		}
	}
	bool chk(LL n,LL K){
		if(SZ(dis))return dis[n%res[0].X]<=n;
		if(SZ(res)==1)return n%K==0;
		LL a=res[0].X,b=res[1].X;
		LL t=PR::mul(I,n,a);
		return n/b>=t;
	}
};
int T;
LL n,K;
map<LL,solver>mp;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&K);
		if(K==1){
			puts("NO");
			continue;
		}
		if(!mp.count(K)){
			mp[K].init(K);
		}
		puts(mp[K].chk(n,K)?"YES":"NO");
	}
	return 0;
}