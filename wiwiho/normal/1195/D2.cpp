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
#define fr front()
#define po pop()
#define ba back()
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
const ll MAX = 1000000001;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> dig(n);
    vector<ll> cnt(11);
    vector<ll> presum(11); //<=
    vector<ll> sufsum(11); //>=
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll t = a[i];
        while(t > 0){
            dig[i]++;
            t /= 10;
        }
        cnt[dig[i]]++;
    }

    presum[1] = cnt[1];
    for(int i = 2; i < 11; i++){
        presum[i] = presum[i - 1] + cnt[i];
    }
    sufsum[10] = cnt[10];
    for(int i = 9; i >= 1; i--){
        sufsum[i] = sufsum[i + 1] + cnt[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){

        ll t = a[i];
        ll ten1 = 1;
        for(int j = 1; t > 0; j++){
            //cerr << ans << "\n";
            ans += (t % 10) * ten1 * sufsum[j];
            //cerr << i << " " << j << " " << ((t % 10) * ten1) << " " << sufsum[j] << "\n";
            ans %= MOD;
            ans += ((t % 10) * ten1 % MOD) * 10 * sufsum[j];
            ans %= MOD;
            ten1 *= 100;
            ten1 %= MOD;
            t /= 10;
        }


        for(int j = 1; j < dig[i]; j++){
            ll ten2 = 1;
            ll t2 = a[i];
            for(int k = 0; k < j; k++){
                ten2 *= 100;
                ten2 %= MOD;
                t2 /= 10;
            }
            //cerr << ans << "\n";
            //cerr << i << " " << j << " " << k << " " << (t2 % 10 * ten2) << " " << cnt[j] << "\n";
            ans += t2 % MOD * ten2 % MOD * cnt[j] % MOD * 2 % MOD;
            ans %= MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}