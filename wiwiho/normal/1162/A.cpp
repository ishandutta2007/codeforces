#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream

    int n, h, m;
    cin >> n >> h >> m;
    
    vector<int> res(n + 1, h);
    for(int i = 0; i < m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        for(int j = l; j <= r; j++){
            res[j] = min(res[j], x);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += res[i] * res[i];
    }
    cout << ans << "\n";

    return 0;
}