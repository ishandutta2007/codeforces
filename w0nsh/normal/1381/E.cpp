#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
typedef long double ld;
typedef std::pair<ld, ld> PLD;

void swp_crd(std::vector<PII> &A){
	TRAV(i, A) std::swap(i.X, i.Y);
}

ld pole_zero(std::vector<PII> xd){
	ld ans = 0;
	REP(i, 1, SZ(xd)){
		ans += (ld)(xd[i-1].Y+xd[i].Y)*std::abs(xd[i].X-xd[i-1].X)/2;
	}
	return ans;
}

ld hei(PLD a, PLD b, ld x){
	assert(a.X < b.X);
	return a.Y + (x-a.X)/(b.X-a.X)*(b.Y-a.Y);
}

std::vector<PLD> get_mid(std::vector<PII> down, std::vector<PII> up){
	std::vector<PLD> ans;
	VI xx;
	TRAV(i, down) xx.push_back(i.X);
	TRAV(i, up) xx.push_back(i.X);
	std::sort(xx.begin(), xx.end());
	xx.resize(std::unique(xx.begin(), xx.end())-xx.begin());

	TRAV(x, xx){
		auto d = std::lower_bound(down.begin(), down.end(), MP(x, -10));
		auto u = std::lower_bound(up.begin(), up.end(), MP(x, -10));
		if(d == down.begin()){
			ans.push_back(MP((ld)x, (ld)d->Y));
			continue;
		}

		assert(u != up.begin());
		d--; u--;
		
		assert(u->X <= x && std::next(u)->X >= x);
		assert(d->X <= x && std::next(d)->X >= x);
		ans.push_back(MP((ld)x, (hei(*u, *std::next(u), x)+hei(*d, *std::next(d), x))/2));
	}

	return ans;
}

template<typename T, typename V>
std::vector<T> convert(const std::vector<V> &vec){
	std::vector<T> ret;
	TRAV(i, vec) ret.push_back((T)i);
	return ret;
}


struct Siema{
	
	struct Ev{
		ld a, b, c;
		Ev(){}
		Ev(ld x, ld y, ld z) : a(x), b(y), c(z) {}

		friend bool operator <(Ev a, Ev b){
			return false;
		}
	};

	std::vector<PR<ld, Ev> > events;
	ld pa, pb, pc;

	Siema(){}
	Siema(std::vector<PLD> A){
		pa = 0;
		pb = 0;
		pc = 0;

		auto add = [&](PLD a, PLD b){
			assert(a.X < b.X);

			ld w = b.X-a.X;
			pb += w;
			if(a.Y > b.Y) std::swap(a, b);

			events.push_back(MP(a.Y, Ev(0, -w, 0)));
			events.push_back(MP(a.Y, Ev(0, 0, w*(b.Y+a.Y)/2)));
			if(std::abs(a.Y-b.Y) < 1e-8) return;

			ld heh = w/(b.Y-a.Y);
			events.push_back(MP(a.Y, Ev(-heh/2, (ld)b.Y*heh, -(ld)b.Y*b.Y*heh/2)));

			events.push_back(MP(b.Y, Ev(heh/2, -(ld)b.Y*heh, (ld)b.Y*b.Y*heh/2)));
		};

		FOR(i, SZ(A)-1){
			add(A[i], A[i+1]);
		}

		std::sort(events.begin(), events.end());
		std::reverse(events.begin(), events.end());
	}

	ld move(ld x){
		while(SZ(events) && events.back().X <= x){
			auto ev = events.back().Y;
			events.pop_back();
			pa += ev.a;
			pb += ev.b;
			pc += ev.c;
		}

		return pa*x*x + pb*x + pc;
	}
};

template <typename T>
ld pole(std::vector<PR<T, T> > A){
	ld ret = 0;
	FOR(i, SZ(A)){
		ret += ((ld)A[i].X*A[(i+1)%SZ(A)].Y-(ld)A[i].Y*A[(i+1)%SZ(A)].X);
	}
	return std::abs(ret/2);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;

	std::vector<PII> A(n);
	std::vector<PII> Q(q);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	FOR(i, n) A[i].X += 100005, A[i].Y += 100005;
	ld ar = pole(A);

	A.resize(2*n);
	std::copy_n(A.begin(), n, A.begin()+n);

	FOR(i, q) std::cin >> Q[i].X, Q[i].Y = i;
	FOR(i, q) Q[i].X += 100005;
	std::sort(Q.begin(), Q.end());

	std::vector<PII> up, down;

	std::vector<PII> cur;
	cur.push_back(A[0]);
	FOR(i, 2*n){
		if(SZ(cur) == 0 || A[i].Y > cur.back().Y) cur.push_back(A[i]);
		else{
			if(SZ(up) < SZ(cur)) up = cur;
			cur = std::vector<PII>{A[i]};
		}
	}
	if(SZ(up) < SZ(cur)) up = cur;
	cur.clear();

	cur.push_back(A[0]);
	FOR(i, 2*n){
		if(SZ(cur) == 0 || A[i].Y < cur.back().Y) cur.push_back(A[i]);
		else{
			if(SZ(down) < SZ(cur)) down = cur;
			cur = std::vector<PII>{A[i]};
		}
	}
	if(SZ(down) < SZ(cur)) down = cur;
	cur.clear();

	swp_crd(down);
	swp_crd(up);

	if(pole_zero(down) > pole_zero(up)) std::swap(down, up);
	if(down[0].X > down[1].X) std::reverse(down.begin(), down.end());
	if(up[0].X > up[1].X) std::reverse(up.begin(), up.end());

	auto mid = get_mid(down, up);
	auto dd = convert<PLD>(down);
	auto uu = convert<PLD>(up);

	Siema sm(mid);
	Siema sd(dd);
	Siema su(uu);

	std::vector<ld> ans(q, ar);
	TRAV(qq, Q){
		ans[qq.Y] += su.move(qq.X) + sd.move(qq.X) - 2*sm.move(qq.X);
	}

	std::cout << std::setprecision(12) << std::fixed;
	TRAV(i, ans) std::cout << i << "\n";

	return 0;
}