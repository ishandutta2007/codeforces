#include <bits/stdc++.h>
using namespace std;

int n;
int x[100013], y[100013];
vector<int> has_[200013];
vector<int>& has(int i) { return has_[i+100000]; }
int w[100013];

bool byx(int a, int b) { return x[a]>x[b]; }

set<pair<int,int> > already;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		has(y[i]-x[i]).push_back(i);
	}
	for (int i=-100000;i<=100000;i++) sort(has(i).begin(),has(i).end(),byx);
	vector<int> ans;
	for (int i=1;i<=n;i++) {
		scanf("%d",&w[i]);
		if (has(w[i]).size()>0) {
			ans.push_back(has(w[i]).back());
			has(w[i]).pop_back();
			int c = ans.back();
			if (x[c] && !already.count(make_pair(x[c]-1,y[c]))) return printf("NO\n"), 0;
			if (y[c] && !already.count(make_pair(x[c],y[c]-1))) return printf("NO\n"), 0;
			already.insert(make_pair(x[c],y[c]));
		} else return printf("NO\n"), 0;
	}
	printf("YES\n");
	for (int i: ans) printf("%d %d\n",x[i],y[i]);

	return 0;
}