#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

using Pll = pair<ll, ll>;
ll hei, wid, rect, fishes;

ll getCover(Pll p) {
	ll x1 = max(0ll, p.x-rect+1), x2 = min(wid-rect, p.x);
	ll y1 = max(0ll, p.y-rect+1), y2 = min(hei-rect, p.y);
	return (x2-x1+1)*(y2-y1+1);
}

struct Cmp {
	bool operator()(Pll l, Pll r) { return getCover(l) < getCover(r); }
};

set<Pll> visited;
priority_queue<Pll, vector<Pll>, Cmp> que;

void add(Pll p) {
	if (p.x >= 0 && p.y >= 0 && p.x < wid && p.y < hei && !visited.count(p)) {
		que.push(p);
		visited.insert(p);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> hei >> wid >> rect >> fishes;
	rep(dx, -2, 3) rep(dy, -2, 3) add({wid/2+dx, hei/2+dy});

	ll score = 0;

	rep(i, 0, fishes) {
		Pll top = que.top();
		que.pop();
		rep(dx, -1, 2) rep(dy, -1, 2) add({top.x+dx, top.y+dy});
		score += getCover(top);
	}

	ll div = (wid-rect+1)*(hei-rect+1);
	cout << double(score) / double(div) << endl;
	return 0;
}