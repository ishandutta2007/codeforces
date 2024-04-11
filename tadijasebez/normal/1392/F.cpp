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
const int N=1000050;
ll h[N];
int main(){
	int n=ri();
	for(int i=1;i<=n;i++)rd(h[i]);
	stack<int> stk;
	ll H=h[n];
	for(int i=n-1;i>=1;i--){
		ll now=h[i];
		while(stk.size()){
			int sz=stk.top()-i;
			if(now+sz<H){
				now+=sz;
				stk.pop();
				H--;
			}else{
				int tmp=stk.top();
				stk.pop();
				stk.push(tmp-(H-1-now));
				now+=H-1-now;
				break;
			}
		}
		if(stk.empty()){
			int sz=n-i;
			ll ans=(H-now)/(sz+1);
			H-=ans;
			now+=ans*sz;
			if(now<H-1){
				int dif=H-1-now;
				stk.push(n-dif);
			}
		}
		if(now==H)stk.push(i);
		else H--;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",H);
		if(stk.size()&&stk.top()==i){
			stk.pop();
		}else H++;
	}
	return 0;
}