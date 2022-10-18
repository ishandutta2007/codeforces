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

        int k, n, a, b;
        cin >> k >> n >> a >> b;

        if(k < 1 + (ll)b * n){
            cout << "-1\n";
            continue;
        }

        int t = (k - (1 + (ll)b * n)) / (a - b);

        t = min(n, t);

        if(k - (ll)t * a == 0){
            t--;
        }
        cout << t << "\n";

    }

    return 0;
}