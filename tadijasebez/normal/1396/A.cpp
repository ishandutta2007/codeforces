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

int main(){
	int n=ri();
	auto a=rv<ll>(n);
	if(n==1){
		printf("1 1\n");
		printf("%lld\n",-a[0]);
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		return 0;
	}
	printf("1 %i\n",n);
	for(ll&i:a){
		ll j=i%(n-1);
		if(j<0)j+=n-1;
		ll b=(ll)(n-1-j)*n;
		printf("%lld ",b);
		i+=b;
	}
	printf("\n");
	printf("1 %i\n",n-1);
	for(int i=0;i<n-1;i++)printf("%lld ",-a[i]);
	printf("\n");
	printf("2 %i\n",n);
	for(int i=1;i<n;i++){
		if(i==n-1)printf("%lld ",-a[i]);
		else printf("0 ");
	}
	printf("\n");
	return 0;
}