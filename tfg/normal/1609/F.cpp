#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Point update, range Query segment tree

struct Node {
    Node() {
        // empty constructor
        ans = {0, 0};
        sum = 0;
    }
    
    Node(int x) {
        // init
        ans = {x, 1};
        sum = x;
    }
    
    Node(Node l, Node r) {
        // merge
        ans.first = std::max(l.ans.first, l.sum + r.ans.first);
        ans.second = 0;
        if(ans.first == l.ans.first) ans.second += l.ans.second;
        if(ans.first == l.sum + r.ans.first) ans.second += r.ans.second;
        sum = l.sum + r.sum;
    }

    int get() { return ans.first == 2 ? ans.second : 0; }

    // atributes
    std::pair<int, int> ans;
    int sum;
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
        tree[pos].ans.first += v;
        tree[pos].sum += v;
        for(pos /= 2; pos > 0; pos /= 2) {
            tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
        }
    }
    
//private:
    int n;
    std::vector<i_t> tree;
};



int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    std::vector<int> val(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        val[i] = __builtin_popcountll(a[i]);
    }
    const int me = 61;
    struct Event {
        int l, r, pos, v;
    };
    std::vector<Event> events[me];
    for(int t = 0; t < 2; t++) {
        std::stack<std::pair<int, int>> st;
        for(int i = 0; i < n; i++) {
            int pt = i;
            int f = 1;
            while(!st.empty() && a[st.top().first] <= a[i]) {
                f += st.top().second;
                pt -= st.top().second;
                events[val[st.top().first]].push_back({pt, pt + st.top().second, i, -1});
                st.pop();
            }
            events[val[i]].push_back({pt, i+1, i, 1});
            st.push({i, f});
        }
        int pt = n;
        while(!st.empty()) {
            pt -= st.top().second;
            events[val[st.top().first]].push_back({pt, pt + st.top().second, n, -1});
            st.pop();
        }
        for(auto &x : a) x = -x;
    }
    SegmentTree<Node, int> tree;
    tree.init(std::vector<int>(1 << 20, 0));
    long long ans = 0;
    for(int i = 0; i < me; i++) if(!events[i].empty()) {
        std::sort(events[i].begin(), events[i].end(), [](auto v1, auto v2) { return v1.pos < v2.pos; });
        int on = 0;
        long long cur = 0;
        for(auto event : events[i]) {
            if(event.pos != on) {
                cur += (long long) (event.pos - on) * tree.tree[1].get();
                on = event.pos;
            }
            tree.upd(event.l, event.v);
            tree.upd(event.r, -event.v);
        }
        ans += cur;
    }
    std::cout << ans << '\n';
}