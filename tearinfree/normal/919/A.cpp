#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>

using namespace std;
typedef long long lli;

int n,m;

int main(){
	double ans=1e9;
	int n,m;
	double a,b;
	scanf("%d%d",&n,&m);
	while(n--) {
		scanf("%lf%lf",&a,&b);
		ans=min(ans,a/b*m);
	}
	printf("%.7lf\n",ans);
	return 0;
}