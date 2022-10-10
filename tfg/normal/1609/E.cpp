#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Point update, range Query segment tree
const int INF = 0x3f3f3f3f;

struct Node {
    Node() {
        // empty constructor
        dp[0][0] = -1;
    }
    
    Node(char ch) {
        // init
        int val = ch - 'a';
        for(int i = 0; i < 4; i++) {
            for(int j = i; j < 4; j++) {
                dp[i][j] = INF;
            }
        }
        dp[3][3] = 0;
        for(int i = 0; i < 3; i++) {
            dp[i][i] = val == i ? 1 : 0;
            dp[i][i+1] = 1 - dp[i][i];
        }
    }
    
    Node(Node l, Node r) {
        // merge
        if(l.dp[0][0] == -1) {
            *this = r;
        } else if(r.dp[0][0] == -1) {
            *this = l;
        } else {
            memset(dp, 0x3f, sizeof dp);
            for(int i = 0; i < 4; i++) for(int j = i; j < 4; j++) for(int k = j; k < 4; k++) {
                dp[i][k] = std::min(dp[i][k], l.dp[i][j] + r.dp[j][k]);
            }
        }
    }

    int get() {
        int ans = INF;
        for(int i = 0; i < 3; i++) {
            ans = std::min(ans, dp[0][i]);
        }
        return ans;
    }

    // atributes
    int dp[4][4];
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
    
    void upd(int pos, e_t v) {
        pos += n;
        tree[pos] = i_t(v);
        for(pos /= 2; pos > 0; pos /= 2) {
            tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
        }
    }
    
private:
    int n;
    std::vector<i_t> tree;
};


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    std::vector<char> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    SegmentTree<Node, char> tree;
    tree.init(a);
    while(q--) {
        int pos;
        char ch;
        std::cin >> pos >> ch;
        tree.upd(pos-1, ch);
        std::cout << tree.qry(0, n).get() << '\n';
    }
}