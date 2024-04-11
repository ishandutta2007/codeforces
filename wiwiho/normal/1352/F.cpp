//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        if(n0 == 0 && n1 == 0){
            cout << string(n2 + 1, '1') << "\n";
            continue;
        }
        if(n0 == 0 && n2 == 0){
            if(n1 % 2 == 0) cout << "1", n1--;
            for(int i = 0; i < n1 + 1; i++){
                cout << i % 2;
            }
            cout << "\n";
            continue;
        }
        if(n1 == 0 && n2 == 0){
            cout << string(n0 + 1, '0') << "\n";
            continue;
        }

        if(n1 % 2 == 0) cout << "1", n1--;

        for(int i = 0; i < n0 + 1; i++) cout << "0";
        for(int i = 0; i < n2 + 1; i++) cout << "1";
        for(int i = 2; i < n1 + 1; i++) cout << i % 2;
        cout << "\n";

    }

    return 0;
}