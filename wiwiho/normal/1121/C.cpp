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

    int n, k;
    cin >> n >> k;

    queue<pii> a;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push(mp(t, i));
    }

    int done = 0;
    vector<pair<pii, int>> now(k, mp(mp(-1, 0), -1));

    vector<bool> ans(n);

    while(done < n){

        for(int i = 0; i < k; i++) if(now[i].S != -1){
            now[i].F.S++;
            if((int)floor((double)done * 100 / n + 0.5) == now[i].F.S){
                ans[now[i].S] = true;
            }
        }

        for(int i = 0; i < k; i++) if(now[i].S != -1){
            if(now[i].F.F == now[i].F.S){
                done++;
                now[i] = mp(mp(-1, 0), -1);
            }
        }

        for(int i = 0; i < k && !a.empty(); i++) if(now[i].S == -1){
            now[i] = mp(mp(a.front().F, 0), a.front().S);
            a.pop();
        }

    }

    int num = 0;
    for(int i = 0; i < n; i++) num += ans[i];
    cout << num << "\n";

    return 0;
}