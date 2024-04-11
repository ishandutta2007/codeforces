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

int n,arr[200001];
set<pii> tr;

int tt[200001];
void upd(int cur,int val) {
	while(cur<=n) {
		tt[cur] += val;
		cur += cur & -cur;
	}
}
int find(int cur) {
	int res=0;
	while(cur) {
		res += tt[cur];
		cur -= cur & -cur;
	}
	return res;
}
int sum(int l,int r) {
	return find(r) - find(l-1);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);

	for(int i=1;i<=n;i++) tr.insert(pii(arr[i],i)),upd(i,1);
	
	lli ans=0;
	int c=n;
	for(int i=1;i<=n;i++) {
		auto it = tr.find(pii(arr[i],i));
		if(it!=tr.end()) {
			tr.erase(it);
			upd(i,-1);
		}
		while(!tr.empty() && tr.begin()->first < i) {
			upd(tr.begin()->second, -1);
			tr.erase(tr.begin());
		}
		ans += sum(i, min(arr[i],n));
	}
	printf("%lld\n",ans);
	
	return 0;
}