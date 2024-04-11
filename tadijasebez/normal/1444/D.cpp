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

const int N=1005;
const int M=N*N;
bitset<M> dp[N];
bool Divide(vector<int> a,vector<int>&l,vector<int>&r){
	int sum=0;
	for(int i:a)sum+=i;
	if(sum&1)return 0;
	dp[0].reset();
	dp[0][0]=1;
	for(int i=1;i<=a.size();i++){
		dp[i]=dp[i-1]|(dp[i-1]<<a[i-1]);
	}
	if(!dp[a.size()][sum/2])return 0;
	l.clear();r.clear();
	sum/=2;
	for(int i=a.size();i>0;i--){
		if(dp[i-1][sum])l.pb(a[i-1]);
		else r.pb(a[i-1]),sum-=a[i-1];
	}
	return 1;
}
int main(){
	for(int t=ri();t--;){
		int n=ri();auto a=rv<int>(n);
		int m=ri();auto b=rv<int>(m);
		if(n==m){
			vector<int> D,U,L,R;
			bool ok=Divide(a,D,U)&&Divide(b,L,R);
			if(ok){
				if(U.size()<D.size())swap(U,D);
				if(L.size()>R.size())swap(L,R);
				sort(U.rbegin(),U.rend());
				sort(D.rbegin(),D.rend());
				sort(L.begin(),L.end());
				sort(R.begin(),R.end());
				//printf("D: ");for(int i:D)printf("%i ",i);printf("\n");
				printf("Yes\n");
				pii now={0,0};
				int i=0,j=0;
				for(int z=0;z<n;z++){
					if(i<D.size())now.first+=D[i++];
					else now.first-=U[i-D.size()],i++;
					printf("%i %i\n",now.first,now.second);
					if(j<R.size())now.second+=R[j++];
					else now.second-=L[j-R.size()],j++;
					printf("%i %i\n",now.first,now.second);
				}
			}else printf("No\n");
		}else printf("No\n");
	}
	return 0;
}