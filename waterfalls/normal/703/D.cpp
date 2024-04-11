#include <bits/stdc++.h>
using namespace std;

int ft[1000013];
void update(int x, int v) { while (x<=1000013) ft[x]^=v, x+=x&-x; }
int query(int x) { return x>0 ? ft[x]^query(x-(x&-x)) : 0; }

int n,q;
int a[1000013];
map<int,vector<int> > loc;
int l[1000013], r[1000013];
vector<int> need[1000013];
int ans[1000013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		loc[a[i]].push_back(i);
	}
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		scanf("%d%d",&l[i],&r[i]);
		need[l[i]].push_back(i);
	}
    for (auto& v: loc) {
		update(v.second[0],v.first);
		reverse(v.second.begin(),v.second.end());
    }
    for (int i=1;i<=n;i++) {
		for (int j: need[i]) {
			ans[j]^=query(r[j])^query(l[j]-1);
		}
		auto& v = loc[a[i]];
		v.pop_back();
		if (v.size()>0) update(v.back(),a[i]);
    }
    for (int i=1;i<=n;i++) a[i]^=a[i-1];
    for (int i=0;i<q;i++) {
		ans[i]^=a[r[i]]^a[l[i]-1];
    }
    for (int i=0;i<q;i++) printf("%d\n",ans[i]);

	return 0;
}