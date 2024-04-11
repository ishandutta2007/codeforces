#include <iostream>
#include <vector>
#include <algorithm>

struct PT {
	typedef long long T;
	T x, y;
	PT(T x = 0, T y = 0) : x(x), y(y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	T operator !()        const { return x*x+y*y;   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
};

std::vector<PT> ConvexHull (std::vector<PT> pts) {
	if(pts.size() <= 1) return pts;
	std::sort(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x != b.x ? a.x < b.x : a.y < b.y; });
	pts.resize(std::unique(pts.begin(), pts.end(), [](PT a, PT b) -> bool { return a.x == b.x && a.y == b.y; }) - pts.begin());
	std::vector<PT> ans(2 * pts.size());
	int s = 0;
	for(int i = 0; i < pts.size(); i++) {
		while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	for(int i = pts.size() - 1, t = s + 1; i > 0; i--) {
		while(s >= t && (pts[i - 1] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i - 1];
	}
	ans.resize(s - 1);
	return ans;
}

bool isInside(const std::vector<PT> &hull, PT point) {
	int n = hull.size();
	if((point - hull[0]) % (hull[1] - hull[0]) > 0 || (point - hull[0]) % (hull[n-1] - hull[0]) < 0) {
		return false;
	}
	int l = 1, r = n - 1;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if((point - hull[0]) % (hull[mid] - hull[0]) < 0) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return (hull[(l+1)%n] - hull[l]) % (point - hull[l]) >= 0;
}

template <class T>
std::vector<int> getBorder(std::vector<T> str) {
	int n = str.size();
	std::vector<int> border(n, -1);
	for(int i = 1, j = -1; i < n; i++) {
		while(j >= 0 && str[i] != str[j + 1]) {
			j = border[j];
		}
		if(str[i] == str[j + 1]) {
			j++;
		}
		border[i] = j;
	}
	return border;
}

template <class T>
int matchPattern(const std::vector<T> &txt, const std::vector<T> &pat, const std::vector<int> &border) {
	int freq = 0;
	for(int i = 0, j = -1; i < txt.size(); i++) {
		while(j >= 0 && txt[i] != pat[j + 1]) {
			j = border[j];
		}
		if(pat[j + 1] == txt[i]) {
			j++;
		}
		if(j + 1 == pat.size()) {
			//found occurence
			freq++;
			j = border[j];
		}
	}
	return freq;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<PT> a(n);
	std::vector<PT> b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].x >> a[i].y;
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i].x >> b[i].y;
	}
	a = ConvexHull(a);
	b = ConvexHull(b);
	n = a.size();
	m = b.size();
	if(n != m) {
		std::cout << "NO\n";
		return 0;
	}
	std::vector<long long> d1(n);
	std::vector<long long> d2(n);
	for(int i = 0; i < n; i++) {
		d1[i] = !(a[(i+1)%n] - a[i]);
		d2[i] = !(b[(i+1)%n] - b[i]);
	}
	std::sort(d1.begin(), d1.end());
	std::sort(d2.begin(), d2.end());
	if(d1 != d2) {
		std::cout << "NO\n";
		return 0;
	}
	std::vector<std::pair<long long, long long>> f, s;
	for(int i = 0; i < n; i++) {
		auto pivot = a[(i+n-1)%n];
		auto p1 = a[(i+1) % n] - pivot;
		auto p2 = a[i] - pivot;
		f.emplace_back(p1 % p2, p1 * p2);
	}
	for(int i = 0; i < n; i++) {
		auto pivot = b[(i+n-1)%n];
		auto p1 = b[(i+1) % n] - pivot;
		auto p2 = b[i] - pivot;
		s.emplace_back(p1 % p2, p1 * p2);
	}
	for(int i = 0; i < n; i++) {
		auto pivot = b[(i+n-1)%n];
		auto p1 = b[(i+1) % n] - pivot;
		auto p2 = b[i] - pivot;
		s.emplace_back(p1 % p2, p1 * p2);
	}
	auto border = getBorder<std::pair<long long, long long>>(f);
	int freq = matchPattern(s, f, border);
	if(freq) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}