#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
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
const int N=100050;
int a[N];
int main(){
	for(int t=ri();t--;){
		int n=ri();
		ra(a,n);
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}
		vector<array<int,3>> op;
		for(int i=2;i<=n;i++){
			if(a[i]>=i){
				op.pb({i,1,1});
				a[i]-=i;
				a[1]+=i;
				break;
			}
		}
		if(a[1]==0){
			if(sum==0){
				printf("0\n");
				continue;
			}else{
				printf("-1\n");
				continue;
			}
		}
		for(int i=2;i<=n;i++){
			int need=a[i]%i;
			if(need)need=i-need;
			op.pb({1,i,need});
			a[i]+=need;
			a[1]-=need;
			op.pb({i,1,a[i]/i});
			a[1]+=a[i];
			a[i]=0;
		}
		int each=sum/n;
		for(int i=2;i<=n;i++){
			op.pb({1,i,each});
		}
		printf("%i\n",op.size());
		for(auto o:op){
			printf("%i %i %i\n",o[0],o[1],o[2]);
		}
	}
	return 0;
}