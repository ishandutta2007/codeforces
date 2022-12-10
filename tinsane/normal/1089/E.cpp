#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

vector<pii> ans;
int row = 0;
int col = 0;
vector<int> oth;

void fillOth() {
    for(int i = 2; i < 7; ++i)
        oth.emplace_back(i);
    oth.emplace_back(7);
    oth.emplace_back(1 - col);
}

int n;
void print() {
    for(auto x : ans)
        printf("%c%c ", x.first + 'a', x.second + '1');
    puts("");
    if (ans.size() != n + 1) {
        throw;
    }
}

void solve() {
    scanf("%d", &n);
    //dbg("HERE n = %d\n", n);
    ans.clear();
    oth.clear();
    row = 0;
    col = 0;
    fillOth();
    ans.emplace_back(0, 0);
    for(int i = 0; i < n - 2; ++i) {
        if (oth.empty()) {
            ++row;
            ans.push_back({row, col});
            fillOth();
            continue;
        }
        ans.push_back({row, oth[0]});
        col = oth[0];
        oth.erase(oth.begin());
    }
    if (row == 7) {
        ans.push_back({row, oth.back()});
        ans.push_back({row, oth[oth.size() - 2]});
        print();
        return;
    }
    if (col != 7) {
        ans.push_back({7, col});
        ans.push_back({7, 7});
        print();
        return;
    }
    // row != 7, col == 7
    auto top = ans.back();
    ans.pop_back();
    ans.push_back({row, oth[0]});
    ans.push_back(top);
    ans.push_back({7, 7});
    print();
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    //for(n = 2; n < 64; ++n)
        solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}