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

const ll HASH2 = 1000004119;
const ll HASH = 2000001551;

int main(){
    StarBurstStream

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;

        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R' && b > 0){
                s[i] = 'P';
                b--;
                cnt++;
            }
            else if(s[i] == 'P' && c > 0){
                s[i] = 'S';
                c--;
                cnt++;
            }
            else if(s[i] == 'S' && a > 0){
                s[i] = 'R';
                a--;
                cnt++;
            }
            else{
                s[i] = '.';
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '.') continue;
            if(a > 0) s[i] = 'R', a--;
            else if(b > 0) s[i] = 'P', b--;
            else if(c > 0) s[i] = 'S', c--;
        }
        if(cnt >= ceil((double)n / 2.0)) cout << "YES\n" << s << "\n";
        else cout << "No\n";
    }

    return 0;
}