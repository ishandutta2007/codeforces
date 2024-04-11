//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

struct Node{
    Node* z = nullptr, *o = nullptr;
    int cnt = 0;
};

int sz(Node* n){
    if(n == nullptr) return 0;
    else return n->cnt;
}

void build(Node* now, int n, int a){
    if(n == -1){
        now->cnt++;
        return;
    }
    if(a & (1LL << n)){
        if(now->o == nullptr) now->o = new Node();
        build(now->o, n - 1, a);
    }
    else{
        if(now->z == nullptr) now->z = new Node();
        build(now->z, n - 1, a);
    }
    now->cnt = sz(now->z) + sz(now->o);
}

int dfs(Node* now, int n){
    if(n == -1) return 0;
    if(now->o == nullptr) return dfs(now->z, n - 1);
    else if(now->z == nullptr) return dfs(now->o, n - 1);
    else{
        return((1 << n) + min(dfs(now->z, n - 1), dfs(now->o, n - 1)));
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    Node* root = new Node();
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        build(root, 29, a);
    }

    cout << dfs(root, 29) << "\n";

    return 0;
}