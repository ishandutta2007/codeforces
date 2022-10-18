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
const ll MAX = 1000000000;

using namespace std;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<string> o(n), r(n);
    for(int i = 0; i < n; i++){
        cin >> o[i];
        for(int j = o[i].size() - 1; j >= 0; j--){
            r[i] += o[i][j];
        }
    }

    vector<ll> dpo(n), dpr(n);
    dpr[0] = c[0];
    for(int i = 1; i < n; i++){
        dpo[i] = -1;
        dpr[i] = -1;
        if(dpo[i - 1] != -1 && o[i] >= o[i - 1])
            if(dpo[i] == -1 || dpo[i - 1] < dpo[i])
                dpo[i] = dpo[i - 1];
        if(dpr[i - 1] != -1 && o[i] >= r[i - 1])
            if(dpo[i] == -1 || dpr[i - 1] < dpo[i])
                dpo[i] = dpr[i - 1];
        if(dpo[i - 1] != -1 && r[i] >= o[i - 1])
            if(dpr[i] == -1 || dpo[i - 1] + c[i] < dpr[i])
                dpr[i] = dpo[i - 1] + c[i];
        if(dpr[i - 1] != -1 && r[i] >= r[i - 1])
            if(dpr[i] == -1 || dpr[i - 1] + c[i] < dpr[i])
                dpr[i] = dpr[i - 1] + c[i];
    }

    if(dpo[n - 1] == -1 && dpr[n - 1] == -1){
        cout << "-1\n";
    }
    else if(dpo[n - 1] == -1){
        cout << dpr[n - 1] << "\n";
    }
    else if(dpr[n - 1] == -1){
        cout << dpo[n - 1] << "\n";
    }
    else{
        cout << min(dpr[n - 1], dpo[n - 1]) << "\n";
    }

    return 0;
}