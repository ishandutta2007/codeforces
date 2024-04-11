#define NDEBUG

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
const ll MAX = 100000;

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n;
        cin >> n;

        int maxx = MAX, maxy = MAX, minx = -MAX, miny = -MAX;

        for(int i = 0; i < n; i++){

            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if(f1 == 1 && f3 == 0) maxx = min(x, maxx); //left
            else if(f1 == 0 && f3 == 1) minx = max(x, minx); //right
            else if(f1 == 0 && f3 == 0){
                minx = max(x, minx);
                maxx = min(x, maxx);
            }

            if(f2 == 0 && f4 == 1) maxy = min(y, maxy); //down
            else if(f2 == 1 && f4 == 0) miny = max(y, miny); //up
            else if(f2 == 0 && f4 == 0){
                miny = max(y, miny);
                maxy = min(y, maxy);
            }

        }

        if(maxx < minx || maxy < miny){
            cout << "0\n";
            continue;
        }

        cout << 1 << " " << maxx << " " << maxy << "\n";

    }

    return 0;
}