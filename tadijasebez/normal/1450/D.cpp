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

const int N=300050;
int a[N];
int main(){
	for(int t=ri();t--;){
		int n=ri();
		ra(a,n);
		/*vector<int> ans(n+1,1);
		set<int> st;
		for(int i=1;i<=n;i++)st.insert(a[i]);
		if(st.size()!=n)ans[1]=0;
		int top=n,bot=2,mid,mx=n+1;
		while(top>=bot){
			mid=top+bot>>1;
			multiset<int> val;
			vector<int> cnt(n+1,0);
			for(int i=1,j=1;i<=n-mid+1;i++){
				while(j<i+mid){
					val.insert(a[j]);
					j++;
				}
				cnt[*val.begin()]++;
				val.erase(a[i]);
			}
			bool ok=1;
			for(int i=1;i<=n-mid+1;i++)if(cnt[i]==0)ok=0;
			if(!ok)bot=mid+1;
			else top=mid-1,mx=mid;
		}
		for(int i=2;i<mx;i++)ans[i]=0;
		for(int i=1;i<=n;i++)printf("%i",ans[i]);
		printf("\n");*/
		set<int> pos;
		pos.insert(0);
		pos.insert(n+1);
		vector<int> ord;
		for(int i=1;i<=n;i++)ord.pb(i);
		sort(ord.begin(),ord.end(),[&](int i,int j){return mp(a[i],i)<mp(a[j],j);});
		vector<int> mx(n+1,0),sec(n+1,0);
		int must_above=0;
		for(int z=0;z<ord.size();z++){
			int i=ord[z];
			int L=i-*(--pos.lower_bound(i))-1;
			int R=*pos.upper_bound(i)-i-1;
			if(L>0&&R>0){
				ckmx(must_above,L+R);
			}
			int now=L+R+1;
			if(mx[a[i]]<now)sec[a[i]]=mx[a[i]],mx[a[i]]=now;
			else ckmx(sec[a[i]],now);
			pos.insert(i);
		}
		int L=1,R=n;
		vector<int> ans(n+1,0);
		for(int i=1;i<=n;i++){
			R=min(R,mx[i]);
			L=max(L,sec[i]+1);
			int j=n-i+1;
			if(L<=j&&R>=j){
				if(j==1){
					ans[j]=1;
				}else{
					if(must_above<j){
						ans[j]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%i",ans[i]);
		printf("\n");
	}
	return 0;
}