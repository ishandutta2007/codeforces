#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 32000;
typedef long long ll;
vector<int>f;
vector<ll>ans;
int gcd(int x, int y) {
	return (y == 0) ? x : gcd(y, x%y);
}
int main() {
	int n; scanf("%d", &n);
	int lim = sqrt(n);
	for(int i=1;i<=lim;i++) {
		if( n % i == 0 ) {
			f.push_back(i);
			if( i*i != n ) f.push_back(n/i);
		}
	}
	for(int i=0;i<f.size();i++) {
		if( gcd(n, f[i]) != f[i] ) continue;
		ll q = 1LL*(n/f[i])*(n + 2 - f[i])/2;
		ans.push_back(q);
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%I64d ", ans[i]);
}