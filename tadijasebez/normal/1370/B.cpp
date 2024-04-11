#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> a(2*n);
		rd(a);
		vector<int> v[2];
		for(int i=0;i<2*n;i++)v[a[i]&1].pb(i+1);
		vector<pii> ans;
		for(int j=0;j<2;j++)
			for(int i=1;i<v[j].size();i+=2)
				ans.pb({v[j][i-1],v[j][i]});
		if(ans.size()==n)ans.pop_back();
		for(pii p:ans)printf("%i %i\n",p.first,p.second);
	}
	return 0;
}