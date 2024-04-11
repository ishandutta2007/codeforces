#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
#define max_m 300000
int prv[max_n+1],cnt[max_n+1],dp[max_n+1];
set<int>st;
vector<int>pr[max_n+1];
pair<int,int>a[max_m<<1|1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,x,l,r; i<=m; ++i){
		scanf("%d%d%d",&x,&l,&r);
		a[i*2-1]=make_pair(l,x),a[i*2]=make_pair(r+1,-x);
	}
	sort(a+1,a+m*2+1);
	memset(cnt,0,sizeof(cnt)),st.clear();
	for(int i=1; i<=n; ++i)
		pr[i].clear();
	for(int i=1; i<=m*2; ++i){
		int x=a[i].second;
		if(x>0){
			if(!cnt[x]){
				st.insert(x);
				auto it1=st.find(x);
				auto it2=it1;
				if(it1!=st.begin())
					pr[x].push_back(*--it1);
				if(++it2!=st.end())
					pr[*it2].push_back(x);
			}
			++cnt[x];
		}
		else
			if(!--cnt[-x])
				st.erase(-x);
	}
	int ans=1,t=1;
	for(int i=1; i<=n; ++i)
		if(pr[i].empty())
			dp[i]=1,prv[i]=0;
		else{
			dp[i]=0;
			for(auto j:pr[i])
				if(dp[j]>dp[i])
					dp[i]=dp[j],prv[i]=j;
			if(++dp[i]>ans)
				ans=dp[i],t=i;
		}
	printf("%d\n",n-ans);
	for(int i=n; i; --i)
		if(i==t)
			t=prv[t];
		else
			printf("%d ",i);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}