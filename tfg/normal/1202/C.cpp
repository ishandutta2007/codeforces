#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	int x, y;
	PT(int a=0, int b=0) { x = a, y = b; }
	PT(char c) {
		x = y = 0;
		if(c == 'N') {
			y = 1;
		} else if(c == 'S') {
			y = -1;
		} else if(c == 'E') {
			x = 1;
		} else {
			x = -1;
		}
	}

	PT rev() { return PT(-x, -y); }
	PT operator + (PT o) const { return PT(x+o.x, y+o.y); }
};

struct Box {
	int xl, xr;
	int yl, yr;
	Box() {
		xl = xr = yl = yr = 0;
	}

	long long area() {
		return (xr-xl+1) * (yr-yl+1LL);
	}

	void add(PT p) {
		xl = std::min(xl, p.x);
		xr = std::max(xr, p.x);
		yl = std::min(yl, p.y);
		yr = std::max(yr, p.y);
	}
};

void solve() {
	std::string s;
	std::cin >> s;
	int n = (int) s.size();
	std::vector<PT> dirs(n);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'D') {
			s[i] = 'E';
		} else if(s[i] == 'W') {
			s[i] = 'N';
		} else if(s[i] == 'A') {
			s[i] = 'W';
		} else {
			s[i] = 'S';
		}
		dirs[i] = PT(s[i]);
	}
	std::vector<PT> prefPos(n+1);
	std::vector<Box> prefBox(n+1);
	std::vector<PT> posPos(n+1);
	std::vector<Box> posBox(n+1);
	// calculating prefix
	for(int i = 0; i < n; i++) {
		prefPos[i+1] = prefPos[i] + dirs[i];
		prefBox[i+1] = prefBox[i];
		prefBox[i+1].add(prefPos[i+1]);
	}
	// calculating suffix
	for(int i = n-1; i >= 0; i--) {
		posPos[i] = posPos[i+1] + dirs[i].rev();
		posBox[i] = posBox[i+1];
		posBox[i].add(posPos[i]);
	}
	// merge
	long long ans = prefBox.back().area();
	char har[4] = {'N', 'S', 'E', 'W'};
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 4; j++) {
			// using pref[i] and suf[i]
			Box curBox = prefBox[i];
			PT curPos = prefPos[i];
			curPos = curPos + PT(har[j]);
			curBox.add(curPos);
			// now suffix
			curBox.xr = std::max(curBox.xr, curPos.x + (posBox[i].xr - posPos[i].x));
			curBox.xl = std::min(curBox.xl, curPos.x - (posPos[i].x - posBox[i].xl));
			curBox.yr = std::max(curBox.yr, curPos.y + (posBox[i].yr - posPos[i].y));
			curBox.yl = std::min(curBox.yl, curPos.y - (posPos[i].y - posBox[i].yl));
			ans = std::min(ans, curBox.area());
			//std::cout << "at pos " << i << " using " << har[j] << " got " << curBox.area() << '\n';
		}
	}
	std::cout << ans << '\n';
}

int main() {
	// fuck missed first to solve F because of bathroom :D
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}