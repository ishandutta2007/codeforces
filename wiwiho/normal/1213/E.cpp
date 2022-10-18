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
    string s, t;
    cin >> s >> t;

    string abc = "abc";
    cout << "YES\n";

    bool nxt = false;
    while(!nxt || next_permutation(iter(abc))){
        nxt = true;
        if(abc.find(s) != string::npos || abc.find(t) != string::npos){
            //cerr << "test " << abc << "\n";
            continue;
        }
        if(n == 1){
            cout << abc << "\n";
            return 0;
        }
        if(!(abc[2] == s[0] && abc[0] == s[1]) && !(abc[2] == t[0] && abc[0] == t[1])){
            for(int i = 0; i < n; i++) cout << abc;
            cout << "\n";
            return 0;
        }
        if(s[1] != s[0] && t[1] != t[0]){
            for(int i = 0; i < n; i++) cout << abc[0];
            for(int i = 0; i < n; i++) cout << abc[1];
            for(int i = 0; i < n; i++) cout << abc[2];
            cout << "\n";
            return 0;
        }
    }

    return 0;
}