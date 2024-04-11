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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b = a;
    gsort(b);

    int m;
    cin >> m;
    while(m--){

        int k, pos;
        cin >> k >> pos;

        map<int, int> cnt;
        for(int i = 0; i < k; i++) cnt[b[i]]++;

        vector<bool> c(n);
        vector<pii> ans;
        for(int i = 0; i < n; i++){
            if(cnt[a[i]] > 0){
                ans.eb(mp(a[i], i));
                c[i] = true;
                cnt[a[i]]--;
            }
        }

        for(int i = 0; i < k - 1; i++){
            for(int j = i + 1; j < k - 1; j++){
                if(ans[j].F <= ans[j + 1].F) continue;
                int p = -1;
                for(int l = ans[j + 1].S + 1; l < n; l++){
                    if(a[l] == ans[j].F && !c[l]){
                        p = l;
                        break;
                    }
                }
                if(p == -1) continue;
                c[ans[j].S] = false;
                c[p] = true;
                ans[j].S = p;
                swap(ans[j], ans[j + 1]);
            }
        }

        cout << ans[pos - 1].F << "\n";

    }

    return 0;
}