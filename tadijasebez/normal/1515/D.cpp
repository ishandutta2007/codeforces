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

int main(){
	for(int t=ri();t--;){
		int n,l,r;
		rd(n,l,r);
		vector<int> cnt_l(n,0),cnt_r(n,0);
		for(int i=0;i<n;i++){
			int x=ri()-1;
			if(i<l)cnt_l[x]++;
			else cnt_r[x]++;
		}
		vector<int> odd_l,odd_r;
		for(int i=0;i<n;i++){
			int mn=min(cnt_l[i],cnt_r[i]);
			cnt_l[i]-=mn;
			cnt_r[i]-=mn;
			if(cnt_l[i]%2==1)odd_l.pb(i);
			if(cnt_r[i]%2==1)odd_r.pb(i);
		}
		int ans=0;
		while(odd_l.size()&&odd_r.size()){
			cnt_l[odd_l.back()]--;
			odd_l.pop_back();
			cnt_r[odd_r.back()]--;
			odd_r.pop_back();
			ans++;
		}
		for(int i=0;i<n;i++){
			while(odd_l.size()&&cnt_r[i]>0){
				cnt_l[odd_l.back()]--;
				odd_l.pop_back();
				cnt_r[i]--;
				ans++;
			}
			while(odd_r.size()&&cnt_l[i]>0){
				cnt_r[odd_r.back()]--;
				odd_r.pop_back();
				cnt_l[i]--;
				ans++;
			}
		}
		int ost=0;
		for(int i=0;i<n;i++){
			ans+=cnt_l[i]/2;
			cnt_l[i]%=2;
			ost+=cnt_l[i];

			ans+=cnt_r[i]/2;
			cnt_r[i]%=2;
			ost+=cnt_r[i];
		}
		ans+=ost;
		printf("%i\n",ans);
	}
	return 0;
}