#include <bits/stdc++.h>
using namespace std;

const int SQRT = 318;

struct Query {
	int l,r,i;
	bool operator<(const Query o) const {
		if (l/SQRT!=o.l/SQRT) return l/SQRT<o.l/SQRT;
		return r<o.r;
	}
};

int n,q;
int a[100013];
Query queries[100013];
int ans[100013];

int cur = 0;
int cnt[100013];
void insert(int i) {
	if (a[i]>n) return;
	if (cnt[a[i]]==a[i]) cur-=1;
	cnt[a[i]]+=1;
	if (cnt[a[i]]==a[i]) cur+=1;
}
void erase(int i) {
	if (a[i]>n) return;
	if (cnt[a[i]]==a[i]) cur-=1;
	cnt[a[i]]-=1;
	if (cnt[a[i]]==a[i]) cur+=1;
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<q;i++) {
		scanf("%d%d",&queries[i].l,&queries[i].r);
		queries[i].l-=1;
		queries[i].r-=1;
		queries[i].i = i;
	}
	sort(queries,queries+q);
	int l = 0;
	int r = -1;
	for (int i=0;i<q;i++) {
		while (l<queries[i].l) erase(l++);
		while (l>queries[i].l) insert(--l);
		while (r<queries[i].r) insert(++r);
		while (r>queries[i].r) erase(r--);
		ans[queries[i].i] = cur;
	}
	for (int i=0;i<q;i++) printf("%d\n",ans[i]);

	return 0;
}