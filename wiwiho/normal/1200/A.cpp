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
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> r(10);
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == 'L'){
            for(int j = 0; j < n; j++){
                if(!r[j]){
                    r[j] = true;
                    break;
                }
            }
        }
        else if(c == 'R'){
            for(int j = 9; j >= 0; j--){
                if(!r[j]){
                    r[j] = true;
                    break;
                }
            }
        }
        else{
            int a = c - '0';
            r[a] = false;
        }

    }

    for(int i = 0; i < 10; i++) cout << r[i];
    cout << "\n";

    return 0;
}