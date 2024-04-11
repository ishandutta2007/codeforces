#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, k;
VI R, A;

struct SumTree{
        struct Node{
                Node *left, *right;
                int val;
                Node(){
                        left = right = nullptr;
                        val = 0;
                }
        };
        Node *root = new Node();
        int query(int a, int b, Node *node=nullptr, int lo=0, int hi=(1<<30)-1){
                if(node == nullptr) node = root;
                if(a > b) return 0;
                if(a == lo && b == hi) return node->val;
                int mid = (lo+hi)/2;
                int ret = 0;
                if(node->left != nullptr) ret += query(a, std::min(b, mid), node->left, lo, mid);
                if(node->right != nullptr) ret += query(std::max(a, mid+1), b, node->right, mid+1, hi);
                return ret;
        }
        void add(int a, int val){
                int lev = 30;
                Node *node = root;
                root->val += val;
                while(lev > 0){
                        lev--;
                        Node *nw;
                        if(a & (1<<lev)) nw = node->right;
                        else nw = node->left;
                        if(nw == nullptr){
                                nw = new Node();
                                if(a & (1<<lev)) node->right = nw;
                                else node->left = nw;
                        }
                        node = nw;
                        node->val += val;
                }
        }
};

struct MaxTree{
        struct Node{
                Node *left, *right;
                int val;
                Node(){
                        left = right = nullptr;
                        val = 0;
                }
        };
        Node *root = new Node();
        int query(int a, int b, Node *node=nullptr, int lo=0, int hi=(1<<30)-1){
                if(node == nullptr) node = root;
                if(a > b) return 0;
                if(a == lo && b == hi) return node->val;
                int mid = (lo+hi)/2;
                int ret = 0;
                if(node->left != nullptr) ret = std::max(ret, query(a, std::min(b, mid), node->left, lo, mid));
                if(node->right != nullptr) ret = std::max(ret, query(std::max(a, mid+1), b, node->right, mid+1, hi));
                return ret;
        }
        void add(int a, int val){
                int lev = 30;
                Node *node = root;
                root->val = std::max(root->val, val);
                while(lev > 0){
                        lev--;
                        Node *nw;
                        if(a & (1<<lev)) nw = node->right;
                        else nw = node->left;
                        if(nw == nullptr){
                                nw = new Node();
                                if(a & (1<<lev)) node->right = nw;
                                else node->left = nw;
                        }
                        node = nw;
                        node->val = std::max(node->val, val);
                }
        }
};


int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cin >> n >> k;
        R.resize(n);
        A.resize(n);
        FOR(i, n) std::cin >> R[i];
        FOR(i, n) std::cin >> A[i];
        SumTree tree;
        FOR(i, n) tree.add(A[i], 1);
        std::vector<PII> guys;
        FOR(i, n) guys.push_back(MP(R[i], i));
        std::sort(guys.begin(), guys.end(), std::greater<PII>());
        VI de;
        de.push_back(guys[0].Y);
        VI score(n);
        score[guys[0].Y] = tree.query(std::max(0, A[guys[0].Y]-k), std::min(1000000000, A[guys[0].Y]+k));
        REP(i, 1, n){
                if(R[de.back()] != guys[i].X)
                        while(SZ(de)) tree.add(A[de.back()], -1), de.pop_back();
                de.push_back(guys[i].Y);
                score[guys[i].Y] = tree.query(std::max(0, A[guys[i].Y]-k), std::min(1000000000, A[guys[i].Y]+k));
        }
        int qi;
        std::cin >> qi;
        std::vector<PR<PII, int> > que;
        FOR(i, qi){
                int a, b;
                std::cin >> a >> b;
                a--;b--;
                if(A[a] > A[b]) std::swap(a, b);
                que.push_back(MP(MP(a, b), i));
        }
        std::sort(que.begin(), que.end(), [](const PR<PII, int> &a, const PR<PII, int> &b){
                return std::max(R[a.X.X], R[a.X.Y]) < std::max(R[b.X.X], R[b.X.Y]);
        });
        std::reverse(que.begin(), que.end());
        MaxTree mt = MaxTree();
        auto it = guys.begin();
        VI ans(qi);
        TRAV(q, que){
                while(it != guys.end() && it->X >= std::max(R[q.X.X], R[q.X.Y]))
                        mt.add(A[it->Y], score[it->Y]), it++;
                if(A[q.X.Y]-k > A[q.X.X]+k) ans[q.Y] = -1;
                else{
                        ans[q.Y] = mt.query(std::max(0, A[q.X.Y]-k), std::min(1000000000, A[q.X.X]+k));
                        if(ans[q.Y] == 0) ans[q.Y] = -1;
                }
        }
        TRAV(i, ans) std::cout << i << "\n";

        return 0;
}