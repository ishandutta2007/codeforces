#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n;
struct credit{
	ll a,b,k;
	bool operator < (const credit &r) const {
		return b>r.b;
	}
}C[550];
ll dp[550] = {0};
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(C[i].a);read(C[i].b);read(C[i].k);
	}
	sort(C,C+n);
	for(ll i=0;i<n;i++){
		for(ll j=n-1;j>=0;j--){
			//cout
			dp[j+1] = max(dp[j+1],dp[j]+C[i].a-C[i].b*j);
			dp[j] = max(dp[j],dp[j]+C[i].a-C[i].b*C[i].k);
		}
		/*for(ll j=0;j<=n;j++)cout<<dp[j]<<'\t';
		cout<<endl;*/
	}
	ll ans = 0;
	for(ll j=n;j>=0;j--)ans = max(ans,dp[j]);
	cout<<ans<<endl;
	return 0;
}