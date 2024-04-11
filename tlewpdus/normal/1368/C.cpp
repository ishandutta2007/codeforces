#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
vector<pii> vec;

int main(){
	scanf("%d",&n);
	vec.push_back({0,0});
	vec.push_back({0,1});
	vec.push_back({n+1,n+1});
	vec.push_back({n+1,n});
	for (int i=1;i<=n;i++) {
		vec.push_back({i,i-1});
		vec.push_back({i,i});
		vec.push_back({i,i+1});
	}
	printf("%d\n",(int)vec.size());
	for (pii &v : vec) printf("%d %d\n",v.first,v.second);

	return 0;
}