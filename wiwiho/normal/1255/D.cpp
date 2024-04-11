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

char toChar(int n){
    if(n < 10) return '0' + n;
    else if(n < 36) return 'a' + n - 10;
    else return 'A' + n - 36;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int r, c, k;
        cin >> r >> c >> k;

        int rice = 0;
        vector<string> a(r);
        for(int i = 0; i < r; i++){
            cin >> a[i];
            for(int j = 0; j < c; j++) if(a[i][j] == 'R') rice++;
        }

        int cnt = rice / k;
        int tcnt = rice % k;

        int now = 0;
        int nowc = 0;
        for(int i = 0; i < r; i++){
            for(int j = i % 2 ? c - 1 : 0; j >= 0 && j < c; i % 2 ? j-- : j++){
                if(a[i][j] == '.'){
                    a[i][j] = toChar(now);
                    continue;
                }
                if(nowc >= cnt + (tcnt != 0)){
                    now++;
                    nowc = 0;
                    if(tcnt > 0) tcnt--;
                }
                a[i][j] = toChar(now);
                nowc++;
            }
        }

        for(int i = 0; i < r; i++) cout << a[i] << "\n";

    }

    return 0;
}