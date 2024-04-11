#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=500050;
char s[N];
bool cmp(pii a,pii b){
	int sz1=a.second-a.first;
	int sz2=b.second-b.first;
	if(sz1>sz2)return 1;
	if(sz2>sz1)return 0;
	return a.first<b.first;
}
ll c2(int sz){
	ll ans=0;
	for(int i=1;i<=sz;i++){
		ans+=(ll)i*(sz-i+1);
	}
	return ans;
}
int main(){
	int n=ri();
	scanf("%s",s+1);
	set<pii> one;
	auto Get=[&](pii seg){
		auto it=one.lower_bound({seg.first+1,0});
		if(it==one.begin())return (pii){-1,-1};
		it--;
		if(it->second>=seg.second)return *it;
		return (pii){-1,-1};
	};
	auto GetL=[&](int x,int sz){
		auto it=one.lower_bound({x,0});
		if(it==one.begin())return 1;
		int o=prev(it)->second;
		return o-sz+2;
	};
	auto GetR=[&](int x,int sz){
		auto it=one.upper_bound({x+1,0});
		if(it==one.end())return n;
		int o=it->first;
		return o+sz-1;
	};
	vector<pii> cand;
	auto Add=[&](int i,int j){
		cand.pb({i-j+1,i});
		for(int k=1;k<j;k++){
			cand.pb({i-j+1+k,i});
			cand.pb({i-j+1,i-k});
		}
	};
	int j=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			if(j)Add(i-1,j);
			j=0;
		}else j++;
	}
	if(j)Add(n,j);
	sort(cand.begin(),cand.end(),cmp);
	ll ans=0;
	for(pii seg:cand){
		pii par=Get(seg);
		if(par.first==-1){
			int sz=seg.second-seg.first+1;
			ans+=c2(sz);
			int l=GetL(seg.first,sz);
			int r=GetR(seg.second,sz);
			ans+=(ll)(seg.first-l+1)*(r-seg.second+1)*sz;
			ans-=sz;
			one.insert(seg);
		}else if(par.first==seg.first){
			int sz=seg.second-seg.first+1;
			int l=GetL(seg.first,sz);
			ans+=(ll)(seg.first-l)*sz;
		}else{
			int sz=seg.second-seg.first+1;
			int r=GetR(seg.second,sz);
			ans+=(ll)(r-seg.second)*sz;
		}
		//printf("%i %i %lld\n",seg.first,seg.second,ans);
	}
	printf("%lld\n",ans);
	return 0;
}