#include <bits/stdc++.h>
using namespace std;

int n;
int a[1013];
vector<int> comp;
int has[1013];

int id(int x) {
	auto it = lower_bound(comp.begin(),comp.end(),x);
	if (it==comp.end() || *it!=x) return comp.size();
	return it-comp.begin();
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		comp.push_back(a[i]);
	}
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (int i=0;i<n;i++) has[id(a[i])]+=1;
	int ans = has[id(0)];
	for (int a: comp) {
		for (int b: comp) {
			if (a || b) {
				int i = a;
				int j = b;
				int ind = id(i);
				vector<int> changes = {ind};
				has[ind]-=1;
				int cur = 1;
				while (true) {
					int k = i+j;
					i = j;
					j = k;
					ind = id(i);
					if (!has[ind]) break;
					has[ind]-=1;
					changes.push_back(ind);
					cur+=1;
				}
				ans = max(ans,cur);
				for (int x: changes) has[x]+=1;
			}
		}
	}
	printf("%d\n",ans);

    return 0;
}