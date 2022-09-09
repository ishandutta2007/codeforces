#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

using line_t = long double;
const line_t is_query = -(1LL<<62);
struct Line {
	line_t m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ();
		if (!s) return 0;
		line_t x = rhs.m;
		return b - s->b < (s->m - m) * x;
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m -x->m);
	}
	void insert_line(line_t m, line_t b) {
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	line_t eval(line_t x) {
		auto l = *lower_bound((Line) { x, is_query });
		return l.m * x + l.b;
	}
};

HullDynamic *H[100100];
int  n;
ll a[100100], b[100100];
vector<int> lis[100100];
int sz[100100];

void idfs(int here,int p){
    sz[here]=1;
    int t = -1;
    for (int i=0;i<lis[here].size();i++) {
        int there = lis[here][i];
        if (there==p) {t=i;continue;}
        idfs(there,here);
        sz[here]+=sz[there];
    }
    if (~t) lis[here].erase(lis[here].begin()+t);
    sort(lis[here].begin(),lis[here].end(),[](int a, int b){return sz[a]>sz[b];});
}

ll d[100100];
void mer(int i, int j) {
    auto it = H[j]->begin();
    while(it!=H[j]->end()) {H[i]->insert_line(it->m,it->b); it++;}
    H[j]->clear();
}

void cdfs(int here) {
    H[here] = new HullDynamic();
    for (auto &there:lis[here]) {
        cdfs(there);
        mer(here,there);
    }
    if (lis[here].empty()) d[here] = 0;
    else d[here] = round(-H[here]->eval(a[here]));
    H[here]->insert_line(-b[here],-d[here]);
}

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&a[i]);
    for (i=0;i<n;i++) scanf("%lld",&b[i]);
    for (i=0;i<n-1;i++) {
        int u, v;
        scanf("%d%d",&u,&v);u--;v--;
        lis[u].push_back(v);
        lis[v].push_back(u);
    }
    idfs(0,-1);
    cdfs(0);
    for (i=0;i<n;i++) printf("%lld ",d[i]);
    printf("\n");

    return 0;
}