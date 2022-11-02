//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 15001;

using block = vector<int>;

int n;

vector<block> blocks;
vector<pii> queries;

void generate_blocks(vector<int> & bg, int pw){
    if(bg.size() == 1u){
        block b;
        for(int i = 0; i < (1<<pw); i++){
            b.push_back(bg[0] + i);
        }
        blocks.pb(b);
        return;
    }
    vector<int> nbg = {};
    for(size_t i = 0; i < bg.size(); i += 2){
        if(i + 1 == bg.size())
            break;
        for(int t = 0; t < (1<<(pw)); t++){
            queries.push_back(make_pair(bg[i] + t, bg[i + 1] + t));
        }
        nbg.push_back(bg[i]);
    }
    if(bg.size()&1){
        block b;
        for(int i = 0; i < (1<<pw); i++){
            b.push_back(bg.back() + i);
        }
        blocks.pb(b);
    }
    generate_blocks(nbg, pw + 1);
}

void sum_blocks(){
    if(blocks.size() <= 2u)
        return;
    int active_blocks = blocks.size();
    int ptr = 0;
    int pool_ptr = 0;
    while(active_blocks > 2){
        //cerr << active_blocks << ' ' << ptr << ' ' << blocks[ptr].size() << endl;
        if(blocks[ptr].size() == blocks[ptr + 1].size()){
            for(size_t i = 0; i < blocks[ptr].size(); i++){
                blocks[ptr + 1].push_back(blocks[ptr][i]);
                queries.push_back(make_pair(blocks[ptr][i], blocks[ptr + 1][i]));
            }
            ++ptr;
            --active_blocks;
            continue;
        }
        size_t sz = blocks[ptr].size();
        for(size_t i = 0; i < sz; i++){
            queries.push_back(make_pair(blocks[ptr][i], blocks.back()[pool_ptr]));
            blocks[ptr].push_back(blocks.back()[pool_ptr++]);
        }
    }
}

void solve(){
    scanf("%d", &n);
    vector<int> bg(n);
    iota(all(bg), 0);
    generate_blocks(bg, 0);
#ifdef LOCAL
    //cerr << blocks.size() << endl;
    for(auto& b: blocks){
        //cerr << b.size() << endl;
    }
#endif
    sum_blocks();
    size_t bound = (size_t)5e5;
    assert(queries.size() <= bound);
    printf("%d\n", (int)queries.size());
    for(auto q: queries){
        printf("%d %d\n", q.X + 1, q.Y + 1);
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}