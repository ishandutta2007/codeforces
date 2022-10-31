#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long lli;

int main() {
	lli p,k;
	scanf("%lld%lld",&p,&k);
	vector<int> ans;

	int i=0,c=0;
	while(p>0 || c!=0) {
		ans.push_back(p%k);
		ans.back() += c;
		
		if(i>100) {
			puts("-1");
			return 0;
		}
		
		c=0;
		if(i&1) {
			if(ans.back()!=0) {
				if(ans.back() == -1) {
					c = 1;
					ans.back() = k + ans.back();
				}
				else {
					c = 1;
					ans.back() = k - ans.back();
				}
			}
		}
		else {
			if(ans.back() == k) {
				ans.back() = 0;
				c = 1;
			}
		}

		p /= k;
		i++;
	}
	printf("%d\n",ans.size());
	for(auto it:ans) printf("%d ",it);
	return 0;
}