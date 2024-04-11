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
		vector<int> a(n);
		rd(a);
		for(int i=0;i<n;i++){
			int tmp=abs(a[i]);
			if(i&1)tmp=-tmp;
			printf("%i ",tmp);
		}
		printf("\n");
	}
	return 0;
}