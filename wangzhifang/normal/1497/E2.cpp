#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
constexpr int max_n=200000,max_k=20,max_v=10000000;
int a[max_n+1],lst[max_v+1];
int dp[max_n+1][max_k+1];
void minify(int&x,const int&y){
	y<x&&(x=y);
}
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	set<int>st;
	st.insert(0);
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		for(int j=2,t; (t=j*j)<=x; ++j)
			while(!(x%t))
				x/=t;
		a[i]=x;
		if(lst[x]){
			st.insert(lst[x]);
			if(int(st.size())>k+1)
				st.erase(st.begin());
		}
		lst[x]=i;
		auto it=st.crbegin(),ed=st.crend();
		for(int l=0; l<=k; ++l)
			dp[i][l]=n;
		for(int j=0; it!=ed; ++it,++j)
			for(int l=j; l<=k; ++l)
				minify(dp[i][l],dp[*it][l-j]+1);
	}
	for(int i=1; i<=n; ++i)
		lst[a[i]]=0;
	int ans=dp[n][0];
	for(int i=1; i<=k; ++i)
		minify(ans,dp[n][i]);
	printf("%d\n",ans);
}
int main(){
	int t;
	memset(lst,0,sizeof(lst));
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}