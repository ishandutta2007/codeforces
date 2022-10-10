#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int k;

struct Node {
  Node() {
    for(int i = 0; i < (1 << k); i++) {
      t[i] = (int) -1e9;
    }
    ans = 0;
  }
  
	void read() {
	  int a[5];
	  for(int i = 0; i < k; i++) {
	    std::cin >> a[i];
	  }
	  for(int i = 0; i < (1 << k); i++) {
	    t[i] = 0;
	    for(int j = 0; j < k; j++) {
	      if(1 & (i >> j)) {
	        t[i] += a[j];
	      } else {
	        t[i] -= a[j];
	      }
	    }
	  }
	}
	Node(Node l, Node r) {
		// merge
		ans = std::max(l.ans, r.ans);
		for(int i = 0; i < (1 << k); i++) {
		  ans = std::max(ans, l.t[i] + r.t[((1<<k)-1)^i]);
		  t[i] = std::max(l.t[i], r.t[i]);
		}
	}

	// atributes
	int t[1 << 5], ans;
};

template <class i_t>
class SegmentTree {
public:
	void init(int s) {
		n = s;
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n].read();
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
	
	void upd(int pos) {
		pos += n;
		tree[pos].read();
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  std::cin >> n >> k;
  SegmentTree<Node> tree;
  tree.init(n);
  int q;
  std::cin >> q;
  while(q--) {
    int t;
    std::cin >> t;
    if(t == 1) {
      int x;
      std::cin >> x;
      tree.upd(x-1);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << tree.qry(l-1, r).ans << '\n';
    }
  }
  return 0;
}