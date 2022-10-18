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

    int k;
    cin >> k;

    while(k--){

        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        if(a == b){
            cout << "Yes\n1\n1 1\n";
            continue;
        }

        vector<int> cnt(26);
        for(int i = 0; i < n; i++){
            cnt[a[i] - 'a']++;
            cnt[b[i] - 'a']++;
        }

        bool f = true;
        for(int i = 0; i < 26; i++) if(cnt[i] % 2) f = false;
        if(!f){
            cout << "No\n";
            continue;
        }

        vector<pii> ans;
        for(int i = 0; i < n; i++){

            if(a[i] == b[i]) continue;

            for(int j = i + 1; j < n; j++){
                if(a[j] == a[i]){
                    swap(a[j], b[i]);
                    ans.eb(mp(j, i));
                    break;
                }
                else if(b[j] == a[i]){
                    swap(a[j], b[j]);
                    ans.eb(mp(j, j));
                    swap(a[j], b[i]);
                    ans.eb(mp(j, i));
                    break;
                }
            }

        }

        cout << "Yes\n";
        cout << ans.size() << "\n";
        for(pii p : ans){
            cout << p.F + 1 << " " << p.S + 1 << "\n";
        }

    }

    return 0;
}