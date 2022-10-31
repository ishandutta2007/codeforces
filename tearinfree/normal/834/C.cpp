#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;

int main() {
	int q;
	lli a,b;
	scanf("%d",&q);
	while(q--) {
		scanf("%lld%lld",&a,&b);
		if(a==1&&b==1) {
			puts("YES");
			continue;
		}
		if(a==1||b==1) {
			puts("NO");
			continue;
		}
		lli val=a*b,lo=0,up=1e6+5;
		while(up-lo>1) {
			lli md=(lo+up)>>1;
			if(md*md*md<=val) lo=md;
			else up=md;
		}
		if(lo*lo*lo==val&&a%lo==0&&b%lo==0) puts("YES");
		else puts("NO");
	}

	return 0;
}