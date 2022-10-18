//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream
//    freopen("test.txt", "r", stdin);

    int x, y;
    cin >> x >> y;

    vector<pii> pos(667);
    for(int i = 1; i <= 666; i++) cin >> pos[i].F >> pos[i].S;

    while(x != 500 || y != 500){
        int nx = x, ny = y;
        if(x > 500) nx--;
        else if(x < 500) nx++;
        else if(y > 500) ny--;
        else if(y < 500) ny++;

        x = nx; y = ny;

        cout << x << " " << y << "\n" << flush;
        int k;
        cin >> k;
        if(k <= 0) return 0;
//        return 0;
        cin >> pos[k].F >> pos[k].S;
    }
//    cerr << x << " " << y << "test\n";

    vector<int> cnt(4);
    for(int i = 1; i <= 666; i++){
        if(pos[i].F < 500 && pos[i].S < 500) cnt[0]++;
        if(pos[i].F > 500 && pos[i].S < 500) cnt[1]++;
        if(pos[i].F < 500 && pos[i].S > 500) cnt[2]++;
        if(pos[i].F > 500 && pos[i].S > 500) cnt[3]++;
    }

    int go = min_element(iter(cnt)) - cnt.begin();

    while(true){
        int nx = x, ny = y;
        if((go == 0 || go == 2) && x != 999) nx++;
        else if((go == 1 || go == 3) && x != 1) nx--;
        if((go == 0|| go == 1) && y != 999) ny++;
        else if((go == 2 || go == 3) && y != 1) ny--;

        for(int i = 1; i <= 666; i++){
            if(pos[i] == mp(nx, ny)){
                nx = x;
                break;
            }
        }

        x = nx; y = ny;
        cout << x << " " << y << "\n" << flush;
        int k;
        cin >> k;
        if(k <= 0) return 0;
//        assert(k != 0);
        cin >> pos[k].F >> pos[k].S;
//        cerr << k << " " << pos[k] << "\n";
    }

    return 0;
}