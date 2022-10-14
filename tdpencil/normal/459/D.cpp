#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

// #define int long long
// a * b = x * y
// find factors of x * y

// first coordinate comrpess
// use fenwick tree to find inversions
// then use another fenwick tree to find inversions related to inversions
struct merge_sort_tree {
    vector<vector<int>> data;
    vector<int> a;
    merge_sort_tree(int T, vector<int> avx) {
        data.resize(T << 2);
        // apparently if doesn't work if T is a power of 2, but honestly i have no idea how true / false this is
        a = avx;
    }
    
    vector<int> combine(vector<int> a, vector<int> b) {
        vector<int> ans;
        int l = 0, r = 0;
        
        while(l < int(a.size()) && r < int(b.size())) {
            if(a[l] < b[r]) {
                ans.push_back(a[l]);
                ++l;
            } else {
                ans.push_back(b[r]);
                ++r;
            }
        }
        
        while(l < int(a.size())) ans.push_back(a[l++]);
        
        while(r < int(b.size())) ans.push_back(b[r++]);
        
        return ans;
    }
    
    void build(int ver, int t1, int t2) {
        if(t1 == t2) {
            data[ver] = vector<int> {a[ver]};
        } else {
            int mid = (t1+t2)>>1;
            build(ver << 1, t1, mid);
            build(ver << 1 | 1, mid + 1, t2);
            data[ver] = combine(data[ver << 1], data[ver << 1 | 1]);
            assert(is_sorted(data[ver].begin(), data[ver].end()));
        }
    }
    
    int query(int ver, int t1, int t2, int l, int r, int x) {
        if(l > t2 || r < t1) return 0;
        // cout << "WORKS???";
        
        
        
        if(l <= t1 && r >= t2) {
            int b = lower_bound(data[ver].begin(), data[ver].end(), x) - data[ver].begin();
            int c = upper_bound(data[ver].begin(), data[ver].end(), x) - data[ver].begin();
            return (c - b);
        } else {
            int mid = (t1 + t2) >> 1;
            return query(ver << 1, t1, mid, l, r, x) + query(ver << 1 | 1, mid + 1, t2, l, r, x);
        }
    }
};


const int MAXN = 1e6;
int A[MAXN], B[MAXN], C[MAXN];
int F[MAXN];
int P[MAXN], Q[MAXN];
pair<int, int> coordinateCompress[MAXN];
set<pair<int, int>> pairset;
oset<pair<int, int>> os;
// os will contain count, index
// pairset will contain index, count
// we can update index, count
// then update count, index
// then finally find the element in os
// print all elements with a size bigger than it
// and boom
// done it
// edit: dumb idea, just finding number of times x occurs 
// and then updating in fenwick tree
int N;
// C stores the amount of times an element occurs
int totalCount[MAXN];

int ft[MAXN + 2];

void update(int pos, int val) {
    for(++pos; pos <= MAXN; pos += pos & -pos)
        ft[pos] += val;
}

int get(int pos) {
    int s=0;
    for(++pos; pos > 0; pos -= pos & -pos)
        s += ft[pos];
    return s;
}

int query(int l, int r) {
    return get(r)-get(l - 1);
}
void run_case() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < N; i++)
        B[i] = A[i];

    sort(B, B+N);

    for(int i = 0; i < N; i++)
        coordinateCompress[i] = pair<int, int>{B[i], i};
    vector<int> V;
    for(int i = 0; i < N; i++)
        V.push_back(A[i]);

    // merge_sort_tree tree(N, V);
    // tree.build(1, 0, N - 1);
    auto getidx = [&](int val) -> int {
        return (*lower_bound(coordinateCompress, coordinateCompress + N, pair<int, int>{val, 0})).second;
    };

    for(int i = N - 1; ~i; i--)
        P[i] = ++Q[getidx(A[i])];
    for(int i = 0; i < N; i++)
        F[i] = ++C[getidx(A[i])];
    // update occurances of 
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int distinct = P[i];
        // cout << distinct << "\n";
        // greater than distinct
        ans += query(distinct + 1, MAXN);
        update(F[i], 1);
    }



    cout << ans << "\n";
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}