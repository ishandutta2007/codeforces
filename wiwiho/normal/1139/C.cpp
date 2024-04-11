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

const ll MOD = 1'000'000'007;
const ll MAX = 1000000001;

#define SIZE 100005
vector<int> p(SIZE);

int getS(int now){
    if(p[now] == now){
        return now;
    }
    p[now] = getS(p[now]);
    return p[now];
}

void unionS(int a, int b){
    int t = getS(a);
    int t2 = getS(b);
    p[t] = t2;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        p[i] = i;
    }

    for(int i = 0; i < n - 1; i++){
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        if(x == 0) unionS(u, v);
    }

    ll ans = 0;

    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        cnt[getS(i)]++;
    }

    for(pii pa : cnt){
        ll base = pa.S;
        ll temp = 1;
        for(int i = 0; (1 << i) <= k; i++){
            if((1 << i) & k){
                temp = modtimes(temp, base);
            }
            base = modtimes(base, base);
        }
        ans = modadd(ans, temp);
    }

    ll base = n;
    ll temp = 1;
    for(int i = 0; (1 << i) <= k; i++){
        if((1 << i) & k){
            temp = modtimes(temp, base);
        }
        base = modtimes(base, base);
    }

    ans = temp - ans;
    if(ans < 0){
        ans = ans + MOD;
    }
    cout << ans << "\n";

}