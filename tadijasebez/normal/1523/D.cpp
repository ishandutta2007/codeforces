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

const int N=200050;
ll a[N];
int b[N];
char s[70];
int cnt[1<<15];
char best[70];
int main(){
	int n,m,p;
	rd(n,m,p);
	for(int i=1;i<=n;i++){
		rd(s);
		for(int j=0;j<m;j++){
			if(s[j]=='1'){
				a[i]|=((ll)1<<j);
			}
		}
	}
	for(int i=0;i<m;i++)best[i]='0';
	int ans=0;
	mt19937 rng(time(0));
	while(clock()<2*CLOCKS_PER_SEC){
	//for(int t=0;t<10;t++){
		int k=rng()%n+1;
		//printf("k: %i\n",k);
		vector<int> bits;
		for(int j=0;j<m;j++){
			if(a[k]>>j&1)
				bits.pb(j);
		}
		int l=bits.size();
		for(int i=0;i<1<<l;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
			for(int j=0;j<bits.size();j++){
				if(!(a[i]>>bits[j]&1)){
					b[i]|=1<<j;
				}
			}
			cnt[b[i]]++;
			//printf("%i\n",b[i]);
		}
		for(int j=0;j<l;j++){
			for(int i=0;i<1<<l;i++){
				if(!(i>>j&1))cnt[i|(1<<j)]+=cnt[i];
			}
		}
		for(int i=0;i<1<<l;i++){
			if(cnt[i]>=(n+1)/2){
				ckmx(ans,l-__builtin_popcount(i));
				if(ans==l-__builtin_popcount(i)){
					for(int j=0;j<m;j++)best[j]='0';
					for(int j=0;j<l;j++){
						if(!(i>>j&1)){
							best[bits[j]]='1';
						}
					}
				}
			}
		}
	}
	//printf("%i\n",ans);
	printf("%s\n",best);
	return 0;
}