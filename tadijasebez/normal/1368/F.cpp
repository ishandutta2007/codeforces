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

const int N=1050;
int state[N];
int patern[N];
int main(){
	int n=ri(),sz;
	if(n<=3){
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	int mx=-100000;
	for(int i=2;i<=n;i++){
		//int all=n/i*(i-1);
		//int las=all-(i-1);
		int las=n-n/i;
		if(n%i!=0)las--;
		las-=(i-1);
		if(las>mx){
			mx=las;
			sz=i;
		}
	}
	//printf("sz:%i\n",sz);
	for(int i=1;i<=n;i++){
		if((i-1)/sz<n/sz){
			if((i-1)%sz<sz-1){
				patern[i]=1;
				//printf("%i\n",i);
			}
		}else{
			if(i!=n)patern[i]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=patern[i];
	assert(cnt==mx+sz-1);
	while(1){
		vector<int> free;
		for(int i=1;i<=n;i++){
			if(state[i]==0&&patern[i])free.pb(i);
		}
		if(free.size()<sz){
			printf("0\n");
			fflush(stdout);
			break;
		}
		printf("%i",sz);
		for(int i=0;i<sz;i++)printf(" %i",free[i]),state[free[i]]=1;
		printf("\n");
		fflush(stdout);
		int b=ri();
		for(int i=0;i<sz;i++){
			int j=i+b;
			if(j>n)j-=n;
			state[j]=0;
		}
	}
	return 0;
}