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

const int N=1050;
char s[N];
int cnt[26];
bool sieve[N],good[N];
vector<int> primes;
int main(){
	rd(s+1);
	int n=strlen(s+1);
	primes.pb(1);
	for(int i=2;i<=n;i++){
		if(!sieve[i]){
			if(i*2>n)primes.pb(i);
			for(int j=i*2;j<=n;j+=i){
				sieve[j]=true;
			}
		}
	}
	for(int i:primes)good[i]=true;
	for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
	int mx=0,mxi=0;
	for(int i=0;i<26;i++){
		ckmx(mx,cnt[i]);
		if(mx==cnt[i])mxi=i;
	}
	if(mx+primes.size()<n)printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<=n;i++)if(!good[i]){
			s[i]='a'+mxi;
			cnt[mxi]--;
		}
		for(int i=1;i<=n;i++)if(good[i]){
			for(int j=0;j<26;j++)if(cnt[j]>0){
				cnt[j]--;
				s[i]='a'+j;
				break;
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}