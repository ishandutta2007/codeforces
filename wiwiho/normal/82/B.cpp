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

    int n;
    cin >> n;

    if(n == 2){

        int k;
        cin >> k;

        int t;
        cin >> t;
        cout << "1 " << t << "\n";
        cout << k - 1 << " ";
        for(int i = 1; i < k; i++){
            int tt;
            cin >> tt;
            cout << tt << " ";
        }
        cout << "\n";
        return 0;
    }

    map<int, bitset<20000>> b;
    for(int i = 0; i < n * (n - 1) / 2; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k ;j++){
            int t;
            cin >> t;
            //cerr << "test " << t << " " << i << "\n";
            b[t][i] = 1;
        }
    }

    unordered_map<bitset<20000>, vector<int>> m;
    for(auto p : b){
        m[p.S].pb(p.F);
        //cerr << p.F << " " << p.S << "\n";
    }
    
    for(auto p : m){
        cout << p.S.size() << " ";
        printv(p.S, cout);
    }

    return 0;
}