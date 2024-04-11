#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef cs int& ci;
typedef long long ll;
constexpr int max_n=1000;
int par[max_n+1],siz[max_n+1];
int find(int&x){
	return par[x]?x=find(par[x]):x;
}
multiset<int>st;
il void test(){
	int n,d;
	scanf("%d%d",&n,&d);
	memset(par,0,sizeof(par));
	st.clear();
	for(int i=1; i<=n; ++i)
		par[i]=0,siz[i]=1,st.insert(1);
	int cnt=0;
	for(int i=1,x,y; i<=d; ++i){
		scanf("%d%d",&x,&y);
		find(x);
		find(y);
		if(x==y)
			++cnt;
		else{
			st.erase(st.find(siz[x]));
			st.erase(st.find(siz[y]));
			par[x]=y,siz[y]+=siz[x];
			st.insert(siz[y]);
		}
		int ans=0;
		multiset<int>::reverse_iterator it=st.rbegin();
		for(int i=cnt+1; i; --i){
			ans+=*it;
			++it;
		}
		printf("%d\n",ans-1);
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}