#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

int e,s,n,m;
vector<int> comp;
vector<pair<int,int> > has;
vector<int> all, butR, onlyS;

int id(int x) { return lower_bound(comp.begin(),comp.end(),x)-comp.begin(); }

vector<int> cover(vector<int> use) {
	vector<int> res(comp.size());
    for (auto i: has) if (use[i.B]) {
		res[id(i.A)]+=1;
		res[id(i.A+s)]-=1;
    }
	int prev = 0;
	for (int& i: res) i+=prev, prev = i;
	for (int i=0;i<res.size()-1;i++) {
		if (res[i]) res[i] = comp[i+1]-comp[i];
	}
	prev = 0;
	for (int& i: res) i+=prev, prev = i;
    return res;
}

bool test(vector<int>& vec, int ind) { return ind!=0 && vec[ind]>vec[ind-1]; }

pair<int,int> solve(int f) {
	if (comp[id(f)]-f>s) return MP(-1,-1);
	if (f+s>=e) return MP(0,0);
	int extraR = 0, extraP = 0;
	int will = comp[id(f+s)];
	if (will>f+s) {
		int loc = id(will)-1;
		if (!test(all,loc)) return MP(-1,-1);
		if (!test(onlyS,loc)) {
			if (test(butR,loc)) extraP = will-(f+s);
			else extraR = will-(f+s);
		}
	}
	f = will;
	int eAt = id(e)-1, fAt = id(f)-1;
	if (all[eAt]-all[fAt]!=e-f) return MP(-1,-1);
	int needR = (e-f)-(butR[eAt]-butR[fAt]);
	int needP = (e-f)-(onlyS[eAt]-onlyS[fAt])-needR;
	return MP(needR+extraR,needP+extraP);
}

int main() {
	scanf("%d%d%d%d",&e,&s,&n,&m);
	comp.push_back(e);
	comp.push_back(-1.01e9);
	for (int i=0;i<n;i++) {
		int t,x;
		scanf("%d%d",&t,&x);
		if (x>=e) continue;
		has.push_back(MP(x,t));
		comp.push_back(x);
		comp.push_back(x+s);
	}
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	all = cover({0,1,1,1});
	butR = cover({0,0,1,1});
	onlyS = cover({0,0,0,1});
	for (int i=0;i<m;i++) {
		int f;
		scanf("%d",&f);
		pair<int,int> ans = solve(f);
		printf("%d %d\n",ans.A,ans.B);
	}

	return 0;
}