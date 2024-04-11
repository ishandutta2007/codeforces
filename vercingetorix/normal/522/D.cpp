#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define INF 99999999

class SegTreeMin {
public:
	SegTreeMin() { };
	SegTreeMin(vi & a) : data(a) { };
	void Init();
	int GetSize() {return data.size();}
	vi & GetData() {return data;}
	void Modify(int index, int value);
	int GetMin(int k) {return RecMinImpl(1, 0, p2 - 1, 0, k - 1);}
private:
	int RecMinImpl(int v, int tl, int tr, int l, int r);
	int p2;
	vi data;
	vi segdata;
};

void SegTreeMin::Init() {
	p2 = 1;
	int deg = 0;
	while (p2 < data.size()) {
		p2 *= 2;
		deg++;
	}
	segdata.resize(2 * p2);
	for (int i = 0; i < data.size(); i++) {
		segdata[i + p2] = data[i];
	}
	for (int i = data.size(); i < p2; i++) {
		segdata[i + p2] = INF;
	}
	int curp2 = p2;
	int step = 1;
	while (curp2 > 1) {
		curp2 /= 2;
		step *= 2;
		for (int i = 0; i < curp2; i ++) {
			segdata[i + curp2] = min(segdata[2 * i + curp2 * 2], segdata[2 * i + 1 + curp2 * 2]);
		}
	}

}

void SegTreeMin::Modify(int index, int value) {
	int curp2 = p2;
	int curind = index;
	segdata[curp2 + index] = value;
	while (curp2 > 1) {
		curp2 /= 2;
		curind /= 2;
		segdata[curind + curp2] = min(segdata[2 * curind + 2 * curp2], segdata[2 * curind + 1 + 2 * curp2]);
	}
}

int SegTreeMin::RecMinImpl(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return INF;
	}
	if (l == tl && r == tr) {
		return segdata[v];
	}
	int tm = (tl + tr) / 2;
	return min(RecMinImpl(v*2, tl, tm, l, min(r,tm)), RecMinImpl(v*2+1, tm+1, tr, max(l,tm+1), r));
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    //int ans = 0;
    int n, m, l, r;
	/*vi kl;// = {45, 41, 51, 6, -1, 4, 5, 1};
	kl.pb(45); kl.pb(41); kl.pb(51); kl.pb(6); kl.pb(-1); kl.pb(4); kl.pb(5); kl.pb(1);
	SegTreeMin lol(kl);
	lol.Init();
	cout<<lol.GetMin(1)<<endl;
	cout<<lol.GetMin(2)<<endl;
	cout<<lol.GetMin(4)<<endl;
	cout<<lol.GetMin(5)<<endl;
	lol.Modify(1, 4);
	cout<<lol.GetMin(1)<<endl;
	cout<<lol.GetMin(2)<<endl;
	cout<<lol.GetMin(4)<<endl;
	cout<<lol.GetMin(5)<<endl;*/
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	vi a(n);
	vi next(n, INF);
	vi prevdiff(n, INF);
	map<int, int> ind;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<pair<pair<int, int>, int>> req;
	for (int i = 0; i < m; i++) {
		//cin >> l >> r;
		scanf("%d %d", &l, &r);
		req.pb(mp(mp(l, r), i));
	}
	for(int i = n - 1; i >= 0; i--) {
		if (ind[a[i]] > 0) {
			next[i] = ind[a[i]];
			prevdiff[ind[a[i]]] = ind[a[i]] - i;
		}
		ind[a[i]] = i;
	}
	SegTreeMin st(prevdiff);
	st.Init();
	sort(all(req));
	vi ans(m);
	int curl = 0;
	for (int i = 0; i < m; i++) {
		while (curl < req[i].first.first - 1) {
			if (next[curl] < INF) {
				st.Modify(next[curl], INF);
			}
			curl++;
		}
		ans[req[i].second] = st.GetMin(req[i].first.second);
	}
	for (int i = 0; i < m; i++) {
		if (ans[i] == INF) {
			ans[i] = -1;
		}
		//cout << ans[i] << endl;
		printf("%d\n", ans[i]);
	}
}