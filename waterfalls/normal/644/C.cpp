#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second

int n;
char buff[113];
set<string> query;
map<string,vector<string> > has, rev;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		string s(buff);
		if (query.count(s)) continue;
		query.insert(s);
		int ind = s.find('/',7);
		if (ind==string::npos) ind = s.size();
		string host = s.substr(0,ind);
		string path = s.substr(ind)+'$';
		has[host].push_back(path);
	}
	for (auto p: has) {
		string s;
		sort(p.B.begin(),p.B.end());
		for (auto t: p.B) s+=t;
		rev[s].push_back(p.A);
	}
	int ans = 0;
	for (auto p: rev) {
		if (p.B.size()>1) {
			ans+=1;
		}
	}
	printf("%d\n",ans);
	for (auto p: rev) {
		if (p.B.size()>1) {
			for (auto s: p.B) printf("%s ",s.c_str());
			printf("\n");
		}
	}

	return 0;
}