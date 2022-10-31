#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n;
char s[500013];

pair<pair<int,int>,int> cur[500013];
int last[500013];
int where[500013], suff[500013];
int lcp[500013];
void makeSA() {
	s[n++] = '$';
	for (int i=0;i<n;i++) {
		where[i] = cur[i].B = i;
		last[i] = s[i];
	}
	for (int k=1;k<n;k*=2) {
		for (int i=0;i<n;i++) cur[i].A = MP(last[i],(cur[i].B+k<n) ? last[where[cur[i].B+k]] : 0);
		sort(cur,cur+n);
		for (int i=0;i<n;i++) where[cur[i].B] = i;
		last[0] = 1;
		for (int i=1;i<n;i++) last[i] = last[i-1]+(cur[i].A!=cur[i-1].A);
	}
	for (int i=0;i<n;i++) suff[i] = cur[i].B;
	int l = 0;
	for (int i=0;i<n;i++) {
		if (where[i]==n-1) continue;
		l = max(0,l-1);
		while (s[i+l]==s[suff[where[i]+1]+l]) l+=1;
		lcp[where[i]] = l;
	}
}

const int OFFSET = 500000;
int val[500013], far[500013];
vector<int> has[1000013];
void process() {
	fill(far,far+n,n-1);
	stack<int> coast;
	int prev = OFFSET;
	for (int i=0;i<n;i++) {
		val[i] = prev;
		prev+=(s[i]=='(' ? 1 : -1);
		has[prev].push_back(i);
		coast.push(i);
		while (coast.size()>0 && val[coast.top()]>prev) {
			far[coast.top()] = i-1;
			coast.pop();
		}
	}
}

void solve() {
	ll ans = 0;
	for (int i=1;i<n;i++) {
		int low = suff[i]+lcp[i-1];
		int high = far[suff[i]];
		if (high<low) continue;
		int v = val[suff[i]];
		ans+=upper_bound(has[v].begin(),has[v].end(),high)
			-lower_bound(has[v].begin(),has[v].end(),low);
	}
	printf("%lld\n",ans);
}

int main() {
	scanf("%d %s",&n,&s);
	process();
	makeSA();
	solve();

	return 0;
}