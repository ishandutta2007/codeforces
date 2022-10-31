#include <bits/stdc++.h>
using namespace std;

int n;
int a,b,c;
vector<vector<int> > group;
multiset<int> has;

int main() {
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	for (int r=0;r<2;r++) {
		if (a>b) swap(a,b);
		if (b>c) swap(b,c);
	}
	group.push_back({c+b+a});
	group.push_back({c+b,a});
	group.push_back({c+a,b});
	if (b+a>c) group.push_back({b+a,c});
	group.push_back({c,b,a});
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		has.insert(t);
	}
	if (*has.rbegin()>a+b+c) return printf("-1\n"), 0;
	int ans = 0;
	for (int i=0;i<group.size()-1;i++) {
		if (!has.size()) break;
		int next = group[i+1][0];
		while (has.size() && *has.rbegin()>next) {
			ans+=1;
			has.erase(--has.end());
			for (int j=1;j<group[i].size();j++) {
				auto it = has.upper_bound(group[i][j]);
				if (it==has.begin()) continue;
				has.erase(--it);
			}
		}
	}
	if (1) {
		// find counts
		int zero = has.size();
		int one = 0;
		for (int i: has) if (i<=b+a) one+=1;
		int two = 0;
		for (int i: has) if (i<=b) two+=1;
		int three = 0;
		for (int i: has) if (i<=a) three+=1;
		zero-=one;
		one-=two;
		two-=three;
		int extra = 1e9;
		// i=number of times you choose b+a instead of b,a
		for (int i=0;i<=one;i++) {
			// init
			int abtake = i;
			int nzero = zero;
			int none = one;
			int ntwo = two;
			int nthree = three;

			// first take things only c can
			int cur = 0;
			cur+=nzero;
			int has = nzero;
			nzero = 0;
			// get as many b+a's as you said you would
			int go = min(abtake,has);
			none-=min(none,go);
			has-=go;
			abtake-=go;
			// b's take stuff, a's take stuff
			go = min(ntwo,has);
			nthree-=min(nthree,go);
			ntwo-=min(ntwo,go);
			has-=go;
			// if left, b's and a's both take from a
			go = min((nthree+1)/2,has);
			nthree-=min(nthree,go*2);

			// take the rest of the abtakes you said you would
			cur+=min(abtake,none/2);
			has = min(abtake,none/2);
			none-=has*2;

			// now c's take rest of ones, b's and a's are separate
			cur+=none;
			has = none;
			none = 0;
			// b's take from b, a's take from a
			go = min(ntwo,has);
			ntwo-=min(ntwo,go);
			nthree-=min(nthree,go);
			has-=go;
			// if left, b's and a's both take from a
			go = min((nthree+1)/2,has);
			nthree-=min(nthree,go*2);

			// now c's and b's both take from b
			cur+=ntwo/2;
			has = ntwo/2;
			ntwo%=2;
			// a's take what they can
			nthree-=min(nthree,has);
			// c take remainder, b'a and a's take from a
			cur+=ntwo;
			has = ntwo;
			ntwo = 0;
			go = min((nthree+1)/2,has);
			nthree-=min(nthree,go*2);

			// all take from a
			cur+=(nthree+2)/3;
			nthree = 0;

			extra = min(extra,cur);
		}
		ans+=extra;
		has.clear();
	}
	printf("%d\n",ans);

	return 0;
}