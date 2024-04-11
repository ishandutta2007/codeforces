#include <bits/stdc++.h>
using namespace std;
template<class T>
struct segtree {
    vector<T> A;
    struct Node {
        long long val, lazy;
    };
    vector<Node> tree;
    segtree(vector<T> &t) {
        A = t;
        tree.resize(int(A.size()) * 4);
    }



    function<T(T, T)> combine = [](T x, T y) -> T {
        return x + y;   
    };
    void build(int v, int t1, int t2) {
        if(t1 == t2) {
            tree[v].val = A[t1];
            tree[v].lazy = 0;
        } else {
            int mid = (t1 + t2) >> 1;
            build(v << 1, t1, mid);
            build(v << 1 | 1, 1+mid, t2);
            tree[v].val = combine(tree[v << 1].val, tree[v << 1 | 1].val);
        }
    }

    void updateRange(int v, int t1, int t2, int l, int r, T val) {
        if(tree[v].lazy != 0) {
            tree[v].val += tree[v].lazy;
            if(t1 != t2) {
                tree[v << 1].lazy += tree[v].lazy;
                tree[v << 1 | 1].lazy += tree[v].lazy;
            }
            tree[v].lazy = 0;
        }

        if(r < t1 || l > t2 || t1 > t2)
            return;

        if(l <= t1 && r >= t2) {
            tree[v].val += val;
            if(t1 != t2) {
                tree[v << 1].lazy += val;
                tree[v << 1 | 1].lazy += val;
            }
            return;
        }

        int mid = (t1 + t2) >> 1;
        updateRange(v << 1, t1, mid, l, r, val);
        updateRange(v << 1 | 1, mid + 1,t2, l, r, val);
        tree[v].val = combine(tree[v << 1].val, tree[v << 1 | 1].val);
    }


    T query(int v, int t1, int t2, int l, int r) {
        if(l > t2 || r < t1)
            return 0;
        if(l <= t1 && r >= t2)
            return tree[v].val;
        if(tree[v].lazy != 0) {
            tree[v].val += tree[v].lazy;
            if(t1 != t2) {
                tree[v << 1].lazy += tree[v].lazy;
                tree[v << 1 | 1].lazy += tree[v].lazy;
            }
            tree[v].lazy = 0;
        }
        int mid = ( t1 + t2 ) >> 1;
        return combine(query(v << 1, t1, mid, l, r) + query(v << 1 | 1, 1 + mid, t2, l, r));
    }

    void build() {
        int X = A.size();
        build(1, 0, X - 1);
    }

    void update(int l, int r, T val) {
        int X = A.size();
        updateRange(1, 0, X - 1, l, r, val);
    }
    void update(int pos, T val) {
        int X = A.size();
        updateRange(1, 0, X - 1, pos, pos, val);
    }

    T query(int l, int r) {
        int X = A.size();
        return query(1, 0, X - 1, l, r);
    }

    T query(int pos) {
        int X = A.size();
        return query(1, 0, X - 1, pos, pos);
    }
};
const int V[] = {100, 20, 10, 5, 1};

int main() {
	int n; scanf("%d", &n);
	vector<int> x(2);
	segtree<int> st(x);
	st.build();
	int a=0;
	for(int i = 0; i < 1e9 + 4e8; i++) {
		a+=1;
	}
	cerr << a << "\n";
	int ans=0;
	for(int i = 0; i < 5; i++) {
		ans += (n / V[i]);
		n%=V[i];
	}
	printf("%d", ans);
}