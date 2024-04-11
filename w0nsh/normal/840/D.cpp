#include <bits/stdc++.h>
typedef std::pair<int, int> PII;
#define X first
#define Y second

constexpr int LOG = 20;
constexpr int N = 300005;

struct Node {
    int val, left, right;
};

Node tree[LOG+1][N];

int n, q;
std::vector<int> A;

bool inside(int a, int b, int c){
    return a >= b && a <= c;
}

void build(){
    for(int i = 0; i < n; ++i){
        tree[0][i] = Node{A[i], -1, -1};
    }

    for(int level = 0; level < LOG; ++level) {
        int pos = 0;
        int b_ind = 0;
        int step = (1<<(LOG-level));
        int half = (1<<(LOG-level-1));

        while(pos < n){
            // nasze wartosci sa z przedzialu <b_ind * step, (b_ind+1) * step)
            int end = pos;
            int mn = 0;
            while(end < n && inside(tree[level][end].val, b_ind * step, (b_ind+1) * step - 1)){
                if(inside(tree[level][end].val, 2*b_ind * half, (2*b_ind+1) * half - 1)){
                    mn++;
                }
                end++;
            }

            int write_a = pos;
            int write_b = pos + mn;

            for(int p = pos; p < end; ++p){
                tree[level][p].left = write_a;
                tree[level][p].right = write_b;
                if(inside(tree[level][p].val, 2*b_ind * half, (2*b_ind+1) * half - 1)){
                    tree[level+1][write_a++].val = tree[level][p].val;
                }else{
                    tree[level+1][write_b++].val = tree[level][p].val;
                }
            }

            pos = end;
            b_ind++;
        }
    }
}

int better(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return std::min(a, b);
}

int query(int level, int a, int b, int ile, int lo, int hi){
    if(b-a+1 <= ile) return -1;
    if(level == LOG) return tree[level][a].val;

    int mid = (lo+hi)/2;
    int next_left = tree[level][b].left;
    int next_right = tree[level][b].right;
    if(inside(tree[level][b].val, lo, mid)) next_right--;
    else next_left--;

    return better(query(level+1, tree[level][a].left, next_left, ile, lo, mid),
        query(level+1, tree[level][a].right, next_right, ile, mid+1, hi));
}

int ans(int l, int r, int k){
    return query(0, l, r, (r-l+1)/k, 0, (1<<LOG)-1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> q;
    A.resize(n);
    for(int i = 0; i < n; ++i) std::cin >> A[i];
    build();

    for(int i = 0; i < q; ++i){
        int l, r, k;
        std::cin >> l >> r >> k;
        l--;r--;
        std::cout << ans(l, r, k) << "\n";
    }

    return 0;
}