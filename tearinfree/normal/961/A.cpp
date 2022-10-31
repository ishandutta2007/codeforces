#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>

using namespace std;
typedef pair<int,int> pii;
typedef long long lli;
typedef pair<lli,lli> pll;


int cnt[1001],n,m;
int main() {
	scanf("%d%d",&n,&m);
	int ans=0,c=0;
	for(int i=0;i<m;i++) {
		int val;
		scanf("%d",&val);
		cnt[val] ++ ;
		if(cnt[val] == 1) c++;

		if(c==n) {
			ans++;
			for(int j=1;j<=n;j++) {
				cnt[j]--;
				if(cnt[j] == 0) c--;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}