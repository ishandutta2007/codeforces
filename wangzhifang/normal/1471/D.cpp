#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
#define max_ai 1000000
int a[max_n+1],ans[max_n+1];
int ton[max_ai+1];
il void test(){
	int n,q;
	scanf("%d",&n);
	unordered_set<int>st;
	st.clear();
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		for(int j=sqrt(a[i]); j>1; --j)
			while(!(a[i]%(j*j)))
				a[i]/=j*j;
//		printf("%d\n",a[i]);
		st.insert(a[i]);
		++ton[a[i]];
	}
//	puts("fdsa");
	int cnt=0,d=1;
	vector<int>v;
	v.clear();
	for(int i:st){
		if(i!=1&&!(ton[i]&1))
			v.push_back(i);
		ton[i]>d&&(d=ton[i]);
	}
	ans[0]=d;
//	puts("asdf");
	if(!v.empty()){
		for(int j:v){
			(ton[1]+=ton[j])>=d&&(d=ton[1]);
			ton[j]=0;
		}
		ans[cnt=1]=d;
	}
	for(int i:st)
		ton[i]=0;
	ton[1]=0;
	scanf("%d",&q);
	for(ll w; q; --q){
		scanf("%lld",&w);
		printf("%d\n",ans[w>cnt?cnt:w]);
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}