#include <bits/stdc++.h>

using namespace std;
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
    int x; scanf("%d", &x);
    if(x == 3) {
        printf("%d", 5);
        return;
    }
    int l = 0, r = 100;
    
    while(l < r) {
        int mid = (l + r) / 2;
        if((mid*mid + 1) / 2 >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", l + (l%2?0:1));
}
int main() {

    int t = 1, i = 1;
    //scanf("%d", &t);
    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}