//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int r, c;
    cin >> r >> c;
    if(r == 1 && c == 1){
        cout << "0\n";
        return 0;
    }

    vector<int> row(r), column(c);
    map<int, bool> use;
    int now = c == 1 ? 2 : 1;
    for(int i = 0; i < r; i++){
        row[i] = now;
        now++;
    }

    now = c == 1 ? 1 : now;
    for(int i = 0; i < c; i++){
        column[i] = now;
        now++;
    }

    /*printv(row, cerr);
    printv(column, cerr);

    for(int i = 0; i < r; i++){
        int g = 0;
        for(int j = 0; j < c; j++) g = __gcd(g, row[i] * column[j]);
        cerr << i << "\n";
        assert(g == row[i]);
    }

    for(int j = 0; j < c; j++){
        int g = 0;
        for(int i = 0; i < r; i++) g = __gcd(g, row[i] * column[j]);
        cerr << j << "\n";
        assert(g == column[j]);
    }*/

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cout << row[i] * column[j] << " ";
        cout << "\n";
    }

    return 0;
}