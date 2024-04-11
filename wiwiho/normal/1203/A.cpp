//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int q;
    cin >> q;

    while(q--){

        int n;
        cin >> n;

        vector<int> p(n);
        int pos1;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i] == 1) pos1 = i;
        }

        bool t1 = true;
        int now1 = 2;
        for(int i = (pos1 + 1) % n; i != pos1; i = (i + 1) % n){
            if(p[i] != now1){
                t1 = false;
                break;
            }
            now1++;
        }

        bool t2 = true;
        int now2 = 2;
        for(int i = (pos1 - 1 + n) % n; i != pos1; i = (i - 1 + n) % n){
            if(p[i] != now2){
                t2 = false;
                break;
            }
            now2++;
        }

        cout << (t1 || t2 ? "YES\n" : "NO\n");

    }

    return 0;
}