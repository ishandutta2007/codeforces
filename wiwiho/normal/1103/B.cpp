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

    string s;
    while(cin >> s){
        if(s != "start") break;

        cout << "? " << 0 << " " << (1 << 30) << "\n" << flush;
        cin >> s;
        if(s == "x"){
            for(int i = 0; i <= 30; i++){
                cout << "? " << 0 << " " << (1 << i) << "\n" << flush;
                cin >> s;
                if(s == "x"){
                    cout << "! " << (1 << i) << "\n" << flush;
                    break;
                }
            }
            continue;
        }

        int tmp = 1;
        for(int i = 1; i <= 30; i++){
            cout << "? " << (1 << (i - 1)) << " " << (1 << i) << "\n" << flush;
            cin >> s;
            if(s == "x"){
                tmp = i;
                break;
            }
        }

        int l = 1 << (tmp - 1), r = (1 << tmp) - 1;
        while(l < r){
            int m = (l + r) / 2;
            cout << "? " << m << " " << (1 << (tmp - 1)) << "\n" << flush;
            cin >> s;
            assert(s != "e");
            if(s == "y") r = m;
            else l = m + 1;
        }

        cout << "! " << l << "\n" << flush;

    }

    return 0;
}