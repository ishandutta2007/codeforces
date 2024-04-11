// http://codeforces.com/problemset/problem/547/D - Mike and Fish

#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#ifdef _GLIBCXX_DEBUG
// namespace __gnu_debug{void _Error_formatter::_M_error() const { __builtin_trap(); }}
#endif

template <class T, std::size_t N>
struct finite_vector {
	std::size_t size;
	finite_vector() : size (0), data () {}

	T const & operator[] (std::size_t i) const {
		assert(i < size);
		return data[i];
	}
	T const & back() const { return operator[] (size-1); }
	void push_back(T x) {
		data[size++] = std::move(x);
	}
	void pop_back() {
		assert(size != 0);
		--size;
	}

	T& operator[] (std::size_t i) {
		return const_cast<T&>(static_cast<finite_vector const&>(*this)[i]);
	}
	T& back () {
		return const_cast<T&>(static_cast<finite_vector const&>(*this).back());
	}

	using iterator = typename std::array<T, N>::iterator;
	using const_iterator = typename std::array<T, N>::const_iterator;
	
	iterator begin() { return data.begin(); }
	iterator end() { return data.begin() + size; }

private:
	std::array<T, N> data;
};

struct point {
	int x, y, id;
};
std::istream& operator>> (std::istream& st, point& p) {
	return st >> p.x >> p.y;
}

int n_point;
std::vector<point> points;
std::vector<finite_vector<int, 2>> adjlist;

template <class Function>
void connect_pairs(Function eqf) {
	for (int i = points.size()-1; i > 0;) {
		if (eqf(points[i], points[i-1])) {
			int u = points[i].id, v = points[i-1].id;
			adjlist[u].push_back(v);
			adjlist[v].push_back(u);
			i -= 2;
		} else {
			--i;
		}
	}
}

// std::vector<char> color;
std::string color;

void dfs(int node) {
	for (int adj : adjlist[node]) {
		if (color[adj] == 0) {
			color[adj] = color[node] ^ ('r' ^ 'b');
			dfs(adj);
		} else {
			assert((color[node] ^ color[adj]) == ('r' ^ 'b'));
		}
	}
}

int main() {
	std::cin >> n_point;
	points.assign(n_point, {});
	for (int i = 0; i < n_point; ++i) {
		std::cin >> points[i];
		points[i].id = i;
	}
	
	adjlist.assign(n_point, {});

	// should I use ptr to member instead? ...
	std::sort(points.begin(), points.end(), [](point a, point b) { return a.x < b.x; });
	connect_pairs([](point a, point b) { return a.x == b.x; });
	std::sort(points.begin(), points.end(), [](point a, point b) { return a.y < b.y; });
	connect_pairs([](point a, point b) { return a.y == b.y; });
	
	// the graph must be bipartite now.
	color.assign(n_point, 0);
	for (int i = 0; i < n_point; ++i) {
		if (color[i] == 0) {
			color[i] = 'r';
			dfs(i);
		}
	}
	
	std::cout << color << '\n';
};