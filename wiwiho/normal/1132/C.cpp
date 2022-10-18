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

vector<int> cnt;
vector<int> p;
vector<pii> painter;
vector<bool> c;
int n, q;

void updateP(){
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 1) p[i] = p[i - 1] + 1;
        else p[i] = p[i - 1];
    }
}

int getMin(){
    int mn = -1;
    int mnc = MAX;
    for(int i = 0; i < q; i++){
        int t = p[painter[i].S] - p[painter[i].F - 1];
        if(t < mnc && !c[i]){
            mnc = t;
            mn = i;
        }
    }
    return mn;
}

void rcnt(int f){
    for(int i = painter[f].F; i <= painter[f].S; i++){
        cnt[i]--;
    }
}

void acnt(int f){
    for(int i = painter[f].F; i <= painter[f].S; i++){
        cnt[i]++;
    }
}

int solve(int f){

    rcnt(f);
    updateP();
    c[f] = true;

    int f2 = getMin();
    rcnt(f2);

    int ans = 0;
    for(int i = 1; i <= n; i++) if(cnt[i]) ans++;

    acnt(f);
    acnt(f2);
    c[f] = false;

    return ans;
}

int main(){
    StarBurstStream

    cin >> n >> q;

    cnt.resize(n + 1);
    c.resize(q);
    painter.resize(q);
    p.resize(n + 1);
    for(int i = 0; i < q; i++){
        cin >> painter[i].F >> painter[i].S;
        acnt(i);
    }

    int ans = 0;
    for(int i = 0; i < q; i++) ans = max(ans, solve(i));
    cout << ans << "\n";

    return 0;
}