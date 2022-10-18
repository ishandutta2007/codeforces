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

        int n;
        cin >> n;

        vector<int> a(n + 1);
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            a[t]++;
        }

        gsort(a);

        int last = a[0] + 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                break;
            }
            if(a[i] >= last){
                a[i] = last - 1;
                if(a[i] <= 0){
                    break;
                }
                ans += a[i];
                last = a[i];
                continue;
            }
            ans += a[i];
            last = a[i];
        }

        cout << ans << "\n";

    }

    return 0;
}