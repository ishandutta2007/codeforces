#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const int inf=1e9;

inline int _abs(int a) {
	return a<0 ? -a : a;
}
inline lli _abs(lli a) {
	return a<0 ? -a : a;
}

int main() {
	lli a,b,p=1;
	scanf("%lld%lld",&a,&b);
	for(int i=0;i<a && p<=b;p*=2,i++) ;
	printf("%lld\n",b%p);

	return 0;
}