#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int side[1005],val[1005];
signed main(){
	int n;
	scanf("%lld",&n);
	int A=1,B=2;
	auto ask=[&](int k,int x,int y,int z){
		printf("%lld %lld %lld %lld\n",k,x,y,z);
		fflush(stdout);
		int res;
		scanf("%lld",&res);
		return res;
	};
	rep(i,3,n){
		int t=ask(2,A,B,i);
		if(t==-1){
			B=i;
		}
	}
	int id=-1;
	rep(i,2,n)if(i!=B){
		val[i]=ask(1,A,B,i);
		if(id==-1||val[id]<val[i])id=i;
	}
	vector<int>v[2];
	rep(i,2,n)if(i!=id){
		side[i]=ask(2,A,id,i)==-1?1:2;
		if(side[i]==1)v[0].push_back(i);
		else if(side[i]==2)v[1].push_back(i);
	}
	sort(v[0].begin(),v[0].end(),[&](int x,int y){return val[x]<val[y];});
	sort(v[1].begin(),v[1].end(),[&](int x,int y){return val[x]>val[y];});
	printf("0 ");
	printf("1 ");
	for(auto&x:v[0])printf("%lld ",x);
	printf("%lld ",id);
	for(auto&x:v[1])printf("%lld ",x);
	puts("");
	fflush(stdout);
	return 0;
}