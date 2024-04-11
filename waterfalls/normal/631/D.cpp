#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Block {
	ll l;
	char c;
	bool add(Block o) {
		if (c==o.c) l+=o.l;
		return (c==o.c);
	}
	bool operator==(Block o) {
		return (c==o.c) && (l==o.l);
	}
	bool operator>=(Block o) {
		return (c==o.c) && (l>=o.l);
	}
};

int n,m;
vector<Block> t,s;

void solve1() {
	ll ans = 0;
	for (Block b: t) {
		if (b.c==s[0].c && b.l>=s[0].l) {
			ans+=b.l-s[0].l+1;
		}
	}
	printf("%lld\n",ans);
}
void solve2() {
	ll ans = 0;
	for (int i=0;i+1<t.size();i++) {
		if (t[i]>=s[0] && t[i+1]>=s[1]) {
			ans+=1;
		}
	}
	printf("%lld\n",ans);
}

vector<Block> zs;
int z[400013];
void solve() {
	for (int i=1;i+1<s.size();i++) zs.push_back(s[i]);
	for (int i=1;i+1<t.size();i++) zs.push_back(t[i]);
	zs.push_back({-1,0});
	int l = 0, r = 0;
	for (int i=1;i<zs.size();i++) {
		z[i] = min(z[i-l],max(0,r-i));
		while (zs[z[i]]==zs[i+z[i]]) z[i]+=1;
		if (i+z[i]>r) l = i, r = i+z[i];
	}
	ll ans = 0;
	for (int i=s.size()-2;i<zs.size();i++) {
		if (z[i]>=s.size()-2) {
			if (t[i-s.size()+2]>=s[0] && t[i+1]>=s.back()) {
				ans+=1;
			}
		}
	}
	printf("%lld\n",ans);
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		Block cur;
		scanf("%lld-%c",&cur.l,&cur.c);
		if (t.size()==0 || !t.back().add(cur)) t.push_back(cur);
	}
	for (int i=0;i<m;i++) {
		Block cur;
		scanf("%lld-%c",&cur.l,&cur.c);
		if (s.size()==0 || !s.back().add(cur)) s.push_back(cur);
	}
	if (t.size()<s.size()) return printf("0\n"), 0;
	if (s.size()==1) solve1();
	if (s.size()==2) solve2();
	if (s.size()>=3) solve();

	return 0;
}