#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int q;
    cin >> q;

    for(int testcase = 0; testcase < q ; testcase++){

        int n, k;
        cin >> n >> k;

        int a[n];
        int mi = MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] += k;
            mi = min(mi, a[i]);
        }

        int ans = mi;
        for(int i = 0; i < n; i++){
            if(a[i] - mi > 2 * k){
                ans = -1;
                break;
            }
        }

        cout << ans << "\n";

    }

    return 0;
}