#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m,k;
int a[1<<20];
int cnt[1<<20];
pair<pair<int,int>,int> queries[100013];
ll ans[100013];

ll cur = 0;
void insert(int i) {
	cur+=cnt[a[i]^k];
	cnt[a[i]]+=1;
}
void remove(int i) {
	cnt[a[i]]-=1;
	cur-=cnt[a[i]^k];
}

const int SQRT = 1e3;
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	if (a.A.A/SQRT!=b.A.A/SQRT) return a.A.A/SQRT<b.A.A/SQRT;
	return a.A.B/SQRT<b.A.B/SQRT;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for (int i=0;i<m;i++) {
		scanf("%d%d",&queries[i].A.A,&queries[i].A.B);
		queries[i].A.A-=1;
		queries[i].B = i;
	}
	sort(queries,queries+m,comp);
	int l = 1, r = 0;
	for (int i=0;i<m;i++) {
		auto q = queries[i];
		while (l>q.A.A) insert(--l);
		while (l<q.A.A) remove(l++);
		while (r>q.A.B) remove (r--);
		while (r<q.A.B) insert(++r);
		ans[q.B] = cur;
	}
	for (int i=0;i<m;i++) printf("%lld\n",ans[i]);

	return 0;
}