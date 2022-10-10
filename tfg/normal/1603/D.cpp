#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const int me = 19;

// Point update, range Query segment tree

struct Node {
    Node() {
        // empty constructor
        ans = 1e18;
        sum = 0;
    }
    
    Node(long long x) {
        // init
        ans = sum = x;
    }
    
    Node(Node l, Node r) {
        // merge
        ans = std::min(l.ans + r.sum, r.ans);
        sum = l.sum + r.sum;
    }

    // atributes
    long long ans, sum;
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


long long dp[me][ms];
int tot[ms];
long long totSum[ms];
long long sum[ms];
int opt[ms];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    for(int i = 1; i < ms; i++) tot[i] = i;
    for(int i = 1; i < ms; i++) for(int j = i+i; j < ms; j += i) {
        tot[j] -= tot[i];
    }
    for(int i = 2; i < ms; i++) {
        totSum[i] = totSum[i-1] + tot[i];
    }
    for(int i = 1; i < ms; i++) {
        dp[0][i] = 1e18;
    }
    std::vector<std::vector<int>> divisors(ms);
    for(int i = 1; i < ms; i++) for(int j = i+i; j < ms; j += i) divisors[j].push_back(i);
    for(int i = 1; i < me; i++) {
        std::vector<long long> arr(ms);
        arr[ms-1] = dp[i-1][ms-1];
        for(int j = ms-2; j >= 0; j--) {
            arr[j] = dp[i-1][j] - dp[i-1][j+1];
        }
        SegmentTree<Node, long long> tree;
        tree.init(arr);
        for(int j = 0; j < ms; j++) {
            for(int d : divisors[j]) {
                arr[d-1] += tot[j / d];
                tree.upd(d-1, arr[d-1]);
            }
            dp[i][j] = tree.qry(0, j+1).ans + tree.qry(j+1, (int) arr.size()).sum;
        }
    }
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << (k >= me ? (long long) n : n + dp[k][n]) << '\n';
    }
}