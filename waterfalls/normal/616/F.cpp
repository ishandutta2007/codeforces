#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MP make_pair
#define A first
#define B second

int n,len;
char t[600013];
int id[600013];
int e[100013], c[100013];

pair<pair<int,int>,int> cur[600013];
int last[600013], where[600013];
int suffix[600013], lcp[600013];
void makeSA() {
	for (int i=0;i<len;i++) {
		last[i] = t[i];
		cur[i].B = where[i] = i;
	}
	for (int k=1;k<len;k*=2) {
		for (int i=0;i<len;i++) {
			cur[i].A = MP(last[i],0);
			if (cur[i].B+k<len) cur[i].A.B = last[where[cur[i].B+k]];
		}
		stable_sort(cur,cur+len);
		for (int i=0;i<len;i++) where[cur[i].B] = i;
		last[0] = 0;
		for (int i=1;i<len;i++) last[i] = last[i-1]+(cur[i].A!=cur[i-1].A);
	}
	for (int i=0;i<len;i++) suffix[i] = cur[i].B;
	int prev = 0;
	for (int i=0;i<len;i++) {
		int& l = lcp[where[i]];
		l = max(0,prev-1);
		while (t[i+l]==t[suffix[where[i]+1]+l] && t[i+l]!='$') l+=1;
		lcp[where[i]] = l;
		prev = l;
	}
	lcp[len-1] = 0;
}

ll sums[600013];
int l[600013], r[600013];
stack<int> has;
ll sum(int a, int b) { return sums[b]-(a ? sums[a-1] : 0); }
void solve() {
	sums[0] = c[id[suffix[0]]];
	for (int i=1;i<len;i++) sums[i] = sums[i-1]+c[id[suffix[i]]];
	fill(l,l+len,-1);
	for (int i=0;i<len-1;i++) {
		while (has.size() && lcp[has.top()]>=lcp[i]) has.pop();
		if (has.size()) l[i] = has.top();
		has.push(i);
	}
	while (has.size()) has.pop();
	fill(r,r+len,len-1);
	for (int i=len-2;i>=0;i--) {
		while (has.size() && lcp[has.top()]>=lcp[i]) has.pop();
		if (has.size()) r[i] = has.top();
		has.push(i);
	}
	ll ans = 0;
	for (int i=0;i<len;i++) {
		if (t[suffix[i]]=='$') continue;
		if (i<len-1) ans = max(ans,lcp[i]*(sums[r[i]]-(l[i]+1 ? sums[l[i]] : 0)));
		ll dist = e[id[suffix[i]]]-suffix[i];
		if (i && dist==lcp[i-1]) continue;
		if (dist==lcp[i]) continue;
		ans = max(ans,dist*c[id[suffix[i]]]);
	}
	printf("%lld\n",ans);
}

int main() {
	scanf("%d",&n);
	char *head = t;
	for (int i=0;i<n;i++) {
		scanf(" %s",head);
		while (*head) {
			id[head-t] = i;
			head++;
		}
		e[i] = head-t;
		*head = '$';
		id[head-t] = n;
		head++;
	}
	len = head-t;
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	makeSA();
	solve();

	return 0;
}