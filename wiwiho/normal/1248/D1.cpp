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
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    //cerr.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    pii ansp = mp(0, 0);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){

            swap(s[i], s[j]);

            int now = MAX;
            int cnt = 0;
            int t = 0;
            for(int k = 0; k < n; k++){
                if(s[k] == '(') t++;
                else t--;
                if(t < now){
                    now = t;
                    cnt = 0;
                }
                if(t == now) cnt++;
                //cerr << t << " ";
            }
            //cerr << "\n";

            if(t == 0 && cnt > ans){
                ans = cnt;
                ansp = mp(i, j);
            }

            swap(s[i], s[j]);

        }
    }

    cout << ans << "\n" << ansp.F + 1 << " " << ansp.S + 1 << "\n";

    return 0;
}