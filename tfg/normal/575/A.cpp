#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mod;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase o) { *this = *this + o; }
	void operator -= (modBase o) { *this = *this - o; }
	void operator *= (modBase o) { *this = *this * o; }
	modBase operator * (modBase o) { return (long long) val * o.val % mod; }
	modBase operator / (modBase o) { return *this * fexp(o, mod - 2); }
	modBase operator + (modBase o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase operator - (modBase o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

template<const size_t n, const size_t m, class T = modBase>
struct Matrix {
	T v[n][m];
	
	Matrix(int d = 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				v[i][j] = T(0);
			}
			if(i < m) {
				v[i][i] = T(d);
			}
		}
	}
	
	template<size_t mm>
	Matrix<n, mm, T> operator *(Matrix<m, mm, T> &o) {
		Matrix<n, mm, T> ans;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < mm; j++) {
				for(int k = 0; k < m; k++) {
					ans.v[i][j] = ans.v[i][j] + v[i][k] * o.v[k][j];
				}
			}
		}
		return ans;
	}
	
	void print() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << v[i][j].val << (j + 1 == m ? '\n' : ' ');
			}
		}
	}
};

struct Node {
	Node(Matrix<2, 2> mat = Matrix<2, 2>(1)) {
		// init
		ans = mat;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = r.ans * l.ans;
	}

	// atributes
	Matrix<2, 2> ans;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}
	
	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
private:
	int n;
	std::vector<i_t> tree;
};

Matrix<2, 2> createMat(int v1, int v2) {
	Matrix<2, 2> ans(0);
	ans.v[0][0] = v2;
	ans.v[0][1] = v1;
	ans.v[1][0] = 1;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k;
	std::cin >> k >> mod;
	if(k == 0) {
		std::cout << "0\n";
		return 0;
	}
	int n;
	std::cin >> n;
	SegmentTree<Node, Matrix<2, 2> > tree;
	std::vector<int> a(n);
	std::vector< Matrix<2, 2> > b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		b[i] = createMat(a[i], a[(i+1)%n]);
		//std::cout << "matrix at " << i << ":\n";
		//b[i].print();
	}
	tree.init(b);
	Matrix<2, 1> cur(1);
	long long on = 0;
	int m;
	std::cin >> m;
	std::vector< std::pair<long long, int> > wtf(m);
	for(int i = 0; i < m; i++) {
		std::cin >> wtf[i].first >> wtf[i].second;
	}
	// 0 1 2 4 6 0 4 4 0 4 4 4
	// 1 2 1 1 2 4 1 3 1 1 2 1
	std::sort(wtf.begin(), wtf.end());
	for(int i = 0; i < m; i++) {
		if(wtf[i].first >= k) break;
		int v2 = wtf[i].second;
		int v1 = (i > 0 && wtf[i-1].first + 1 == wtf[i].first ? wtf[i-1].second : a[(wtf[i].first - 1) % n]);
		// on should be wtf[i].first - 1
		long long to = wtf[i].first - 1;
		if(to / n > on / n) {
			cur = tree.qry(on % n, n).ans * cur;
			on = (on / n + 1) * n;
		}
		if(to / n > on / n) {
			cur = fexp(tree.qry(0, n).ans, to / n - on / n) * cur;
			on += (to / n - on / n) * n;
		}
		if(to > on) {
			//tree.qry(on % n, to % n).ans.print();
			cur = tree.qry(on % n, to % n).ans * cur;
			on = to;
		}
		// apply
		to++;
		if(to > on) {
			cur = createMat(v1, v2) * cur;
			on++;
		}
		// on wtf[i].first
		// to wtf[i].first + 1
		to++;
		v1 = wtf[i].second;
		v2 = (i + 1 < m && wtf[i+1].first - 1 == wtf[i].first ? wtf[i+1].second : a[(wtf[i].first + 1) % n]);
		if(to > on) {
			cur = createMat(v1, v2) * cur;
			on++;
		}
	}
	// go to k
	{
		//std::cout << "starting at " << on << " got:\n"; cur.print();
		long long to = k;
		if(to / n > on / n) {
			cur = tree.qry(on % n, n).ans * cur;
			on = (on / n + 1) * n;
		}
		//std::cout << "at " << on << " got:\n"; cur.print();
		if(to / n > on / n) {
			cur = fexp(tree.qry(0, n).ans, to / n - on / n) * cur;
			on += (to / n - on / n) * n;
		}
		//std::cout << "at " << on << " got:\n"; cur.print();
		if(to > on) {
			cur = tree.qry(on % n, to % n).ans * cur;
			on = to;
		}
		//std::cout << "at " << on << " got:\n"; cur.print();
	}
	std::cout << cur.v[1][0].val << '\n';
}