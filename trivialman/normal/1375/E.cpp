#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 1000000007;
const int INF = 1e9;
const int N = 1005;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, a[N];
vector<ar2> small;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>n;
	rep(i,1,n) cin>>a[i];
	vector<ar2> ans;
	
	rep(i,1,n){
		small.clear();
		rep(j,i+1,n) if(a[j]<a[i]) {
			small.PB({-a[j],-j});
		}
		sort(small.begin(),small.end());
		
		for(auto x:small)
			ans.PB({i, -x[1]});
	}
	
	printf("%d\n",ans.size());
	for(auto x:ans)
		printf("%d %d\n",x[0],x[1]);
	return 0;
}