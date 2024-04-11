#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_c=100000;
vector<int>a[max_c+1],b[max_c+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j){
			int x;
			scanf("%d",&x);
			a[x].push_back(i),b[x].push_back(j);
		}
	ll ans=0;
	for(int i=1; i<=max_c; ++i)
		if(a[i].size()>1){
			sort(a[i].begin(),a[i].end());
			sort(b[i].begin(),b[i].end());
			for(int j=1,ed=a[i].size(); j<ed; ++j)
				ans+=j*ll(ed-j)*(a[i][j]-a[i][j-1]+b[i][j]-b[i][j-1]);
		}
	printf("%lld\n",ans);
}
int main(){
	test();
//	int t;
//	scanf("%d",&t);
//	for(; t; test(),--t);
	return 0;
}