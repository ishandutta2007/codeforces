#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a[200005], len[200005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	set<int> ids;
	set<PII> segs;
	rep(i, n) {
		int ptr = i;
		while(ptr + 1 < n && a[ptr + 1] == a[i]) ptr ++;
		ids.insert(i);
		len[i] = ptr - i + 1;
		segs.insert(MP(-len[i], i));
		i = ptr;
	}
	int ans = 0;
	while(ids.size()) {
		++ ans;
		auto it = segs.begin();
		int i = (*it).second;
		segs.erase(it);
		ids.erase(ids.find(i));
		auto nxt = ids.lower_bound(i);
		if(nxt != ids.begin() && nxt != ids.end()) {
			int l = *prev(nxt);
			int r = *nxt;
			if(a[l] == a[r]) {
				ids.erase(ids.find(r));
				segs.erase(segs.find(MP(-len[r], r)));
				segs.erase(segs.find(MP(-len[l], l)));
				len[l] += len[r];
				segs.insert(MP(-len[l], l));
			}
		}
	}
	printf("%d", ans);

	return 0;
}