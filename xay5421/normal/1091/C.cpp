#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
int n;std::vector<ll>q;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i*i<=n;++i)if(n%i==0){q.push_back(i);if(n/i!=i)q.push_back(n/i);}
	for(int i=0;i<q.size();++i)q[i]=1ll*n*(n-q[i]+2)/2/q[i];
	std::sort(q.begin(),q.end());
	for(int i=0;i<q.size();++i)printf("%lld ",q[i]);
	return 0;
}