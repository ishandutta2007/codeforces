#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m;
int x[200013];
ll t[200013];
int cnt[200013];
int p[200013], b[200013];
vector<int> comp;

void updmin(int& i, int v) { if (x[v]>x[i]) i = v; }
int ft[200013];
void update(int i, int v) { while (i<=comp.size()) updmin(ft[i],v), i+=i&-i; }
int query(int i) {
	int res = 0;
	while (i>0) updmin(res,ft[i]), i-=i&-i;
	return res;
}

void put(int i) {
	int loc = lower_bound(comp.begin(),comp.end(),x[i]-t[i])-comp.begin();
	update(loc+1,i);
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d%lld",&x[i],&t[i]);
		x[i] = 1e9+2-x[i];
	}
	comp.resize(m+1);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&p[i],&b[i]);
		p[i] = 1e9+2-p[i];
		comp[i] = p[i];
	}
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (int i=1;i<=m;i++) p[i] = lower_bound(comp.begin(),comp.end(),p[i])-comp.begin();
	for (int i=1;i<=n;i++) put(i);
	set<pair<int,int> > uneaten;
	for (int i=1;i<=m;i++) {
		int ow = query(p[i]+1);
		if (!ow || x[ow]<comp[p[i]]) uneaten.insert(MP(comp[p[i]],i));
		else {
			t[ow]+=b[i];
			cnt[ow]+=1;
			while (true) {
				auto it = uneaten.lower_bound(MP(x[ow]-t[ow],0));
				if (it==uneaten.end() || it->A>x[ow]) break;
				t[ow]+=b[it->B];
				cnt[ow]+=1;
				uneaten.erase(it);
			}
			put(ow);
		}
	}
	for (int i=1;i<=n;i++) printf("%d %lld\n",cnt[i],t[i]);

	return 0;
}