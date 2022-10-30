#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
char sC[100013];
string s;
vector<vector<int> > has;

set<int> L,R;
void make() {
	if (*L.begin()>*R.begin()) swap(L,R);
	vector<int> res;
	int where = 0;
	while (true) {
		int cur = *L.lower_bound(where);
		if (cur==n) {
			has.push_back(res);
			return;
		}
		res.push_back(cur);
		where = cur;
		L.erase(cur);
		swap(L,R);
	}
}

int crossL = 0, crossR = 0;
set<int> ls,rs;
vector<int> solve() {
	vector<int> res;
	if (crossL<crossR || ls.size()==0) swap(ls,rs);
	while (ls.size()) {
		int cur = *ls.begin();
		ls.erase(cur);
		if (cur<0) cur = -cur-1;
		for (int i: has[cur]) res.push_back(i);
		if (s[has[cur].front()]==s[has[cur].back()]) swap(ls,rs);
	}
	return res;
}

int main() {
	scanf(" %s",&sC);
	n = strlen(sC);
	s = string(sC);
	for (int i=0;i<n;i++) {
		if (s[i]=='L') L.insert(i);
		else R.insert(i);
	}
	L.insert(n);
	R.insert(n);
	while (L.size()>1 || R.size()>1) {
		make();
		int val = has.size()-1;
		if (s[has.back().front()]!=s[has.back().back()]) val = -val-1;
		if (s[has.back().front()]=='L') {
			ls.insert(val);
			if (val>=0) crossL+=1;
		} else {
			rs.insert(val);
			if (val>=0) crossR+=1;
		}
	}
	if (crossL==0 && crossR==0 && ls.size()>0 && rs.size()>0) {
		int moving = has[0].back();
		has[0].pop_back();
		for (auto& i: has) {
			if (s[i.front()]!=s[0]) {
				i.push_back(moving);
				break;
			}
		}
	}
	printf("%d\n",has.size()-1);
	vector<int> res = solve();
	for (int i: res) printf("%d ",i+1);
	printf("\n");

	return 0;
}