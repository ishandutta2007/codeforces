#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
template<class T>
using indexed_set =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
const ll mod = 1e9 + 7;

void solve() {
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);

    vector<int> times1, times2;

    int res = 0;

    while(b + res * a< 10000) {
        times1.push_back(b + res * a);
        res++;
    }
    res = 0;
    while(y + res * x < 10000) {
        times2.push_back(y + res * x);
        ++res;
    }


    for(auto &e: times1) {
        int p = *lower_bound(times2.begin(), times2.end(), e);
        if(p == e) {
            printf("%d", p);
            return;
        }
    }


    printf("-1\n");
}
int main() {

    int t = 1, i = 1;

    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}