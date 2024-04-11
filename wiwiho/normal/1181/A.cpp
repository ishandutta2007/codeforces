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

    ll x, y, z;
    cin >> x >> y >> z;

    ll a = (x + y) / z;
    if(x % z == 0 || y % z == 0 || x / z + y / z == a){
        cout << (x / z + y / z) << " 0\n";
        return 0;
    }

    if(z - (x % z) < z - (y % z)){
        ll ans = z - (x % z);
        x += ans;
        y -= ans;
        cout << (x / z + y / z) << " " << ans << "\n";
    }
    else{
        ll ans = z - (y % z);
        y += ans;
        x -= ans;
        cout << (x / z + y / z) << " " << ans << "\n";
    }

    return 0;
}