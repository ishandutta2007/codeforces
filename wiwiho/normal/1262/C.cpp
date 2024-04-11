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

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        k--;

        vector<pii> ans;
        for(int i = 0; i < 2 * k; i++){
            if(i % 2 == 0 && s[i] != '('){
                int j;
                for(j = i + 1; j < n && s[j] != '('; j++);
                ans.eb(mp(i, j));
                reverse(s.begin() + i, s.begin() + j + 1);
            }
            else if(i % 2 == 1 && s[i] != ')'){
                int j;
                for(j = i + 1; j < n && s[j] != ')'; j++);
                ans.eb(mp(i, j));
                reverse(s.begin() + i, s.begin() + j + 1);
            }
        }
        for(int i = 2 * k; i < 2 * k + (n - 2 * k) / 2; i++){
            if(s[i] != '('){
                int j;
                for(j = i + 1; j < n && s[j] != '('; j++);
                ans.eb(mp(i, j));
                reverse(s.begin() + i, s.begin() + j + 1);
            }
        }
        for(int i = 2 * k + (n - 2 * k); i < n; i++){
            if(s[i] != ')'){
                int j;
                for(j = i + 1; j < n && s[j] != ')'; j++);
                ans.eb(mp(i, j));
                reverse(s.begin() + i, s.begin() + j + 1);
            }
        }
        //cerr << s << "\n";

        cout << ans.size() << "\n";
        for(pii p : ans){
            cout << p.F + 1 << " " << p.S + 1 << "\n";
        }

    }

    return 0;
}