#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	typedef long long T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }
};


std::vector<PT> ConvexHull (std::vector<PT> pts) {
	std::sort(pts.begin(), pts.end());
	pts.resize(std::unique(pts.begin(), pts.end()) - pts.begin());
	if(pts.size() <= 1) return pts;
	std::vector<PT> ans(pts.size() * 2);
	int s = 0;
	for(int i = 0; i < (int) pts.size(); i++) {
		while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	for(int i = (int) pts.size() - 2, t = s + 1; i >= 0; i--) {
		while(s >= t && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
			s--;
		}
		ans[s++] = pts[i];
	}
	ans.resize(s-1);
	for(int i = 1; i < (int) ans.size(); i++) {
		ans[i] = ans[i] - ans[0];
	}
	ans[0] = PT(0, 0);
	return ans;
}

bool comp(PT a, PT b){
	int hp1 = (a.x < 0 || (a.x==0 && a.y<0));
	int hp2 = (b.x < 0 || (b.x==0 && b.y<0));
	if(hp1 != hp2) return hp1 < hp2;
	long long R = a%b;
	if(R) return R > 0;
	return a*a < b*b;
}

// This code assumes points are ordered in ccw and the first points in both vectors is the min lexicographically
std::vector<PT> minkowskiSum(const std::vector<PT> &a, const std::vector<PT> &b){
	if(a.empty() || b.empty()) return std::vector<PT>(0);
	std::vector<PT> ret;
	int na = (int) a.size(), nb = (int) b.size();
	if(std::min(a.size(), b.size()) < 2){
		for(int i = 0; i < na; i++) {
			for(int j = 0; j < nb; j++) {
				ret.push_back(a[i]+b[j]);
			}
		}
		return ret;
	}
	ret.push_back(a[0]+b[0]);
	PT p = ret.back();
	int pa = 0, pb = 0;
	while(pa + pb + 1 < na + nb) {
		PT va = (a[(pa+1)%na]-a[pa%na]);
		PT vb = (b[(pb+1)%nb]-b[pb%nb]);
		if(pb == nb || (pa < na && comp(va, vb))) { p = p + va, pa++; }
		else { p = p + vb, pb++; }
		while(ret.size() >= 2 && (p-ret.back()) % (p-ret[(int)ret.size()-2]) == 0) {
			// removing colinear points
			// needs the scalar product stuff it the result is a line
			ret.pop_back();
		}
		ret.push_back(p);
	}
	return ret;
}

template<class T>
std::vector<int> getBorder(T str) {
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

template<class T>
int matchPattern(const T &txt, const T &pat, const std::vector<int> &border) {
	int freq = 0;
	for(int i = 0, j = -1; i < (int) txt.size(); i++) {
		while(j >= 0 && txt[i] != pat[j + 1]) {
			j = border[j];
		}
		if(pat[j + 1] == txt[i]) {
			j++;
		}
		if(j + 1 == (int) pat.size()) {
			//found occurence
			freq++;
			j = border[j];
		}
	}
	return freq;
}


bool test(const std::vector<PT> &a, const std::vector<PT> &b) {
	int n = (int) a.size();
	assert(a.size() == b.size());
	std::vector<std::pair<long long, long long>> str1, str2;
	for(int i = 0; i < n; i++) {
		PT diff = a[(i+1)%n] - a[i];
		PT diff2 = a[(i+2)%n] - a[i];
		str1.emplace_back(diff * diff, diff2 % diff);
	}
	for(int i = 0; i < n; i++) {
		PT diff = b[(i+1)%n] - b[i];
		PT diff2 = b[(i+2)%n] - b[i];
		str2.emplace_back(diff * diff, diff2 % diff);
		if(str2.back().first % 4 != 0 || str2.back().second % 4 != 0) {
			return false;
		} else {
			str2.back().first /= 4;
			str2.back().second /= 4;
		}
	}
	for(int i = 0; i < n; i++) {
		str2.push_back(str2[i]);
	}
	auto border = getBorder(str1);
	return matchPattern(str2, str1, border) > 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> hull(n);
	for(int i = 0; i < n; i++) {
		std::cin >> hull[i].x >> hull[i].y;
	}
	std::vector<PT> a(n), b(n);
	for(int i = 0; i < n; i++) {
		a[i] = hull[(i+1)%n] - hull[i];
		b[i] = PT(0, 0) - a[i];
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	std::cout << (a == b ? "YES\n" : "NO\n");
}