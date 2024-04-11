//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e7 + 6;

int n;
int lp[N];
int cnt[N];
int phi[N];
int pref[N];
int border = N - 1;
vector<int> primes;
int smallsum = 0;

void solve(){
    phi[1] = 1;
    for(int i = 2; i < N; i++){
        pref[i] = pref[i - 1];
        if(!lp[i]){
            lp[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
            ++pref[i];
        }
        for(size_t j = 0; j < primes.size() && i * primes[j] < N; j++){
            if(primes[j] <= lp[i])
                lp[i * primes[j]] = primes[j];
            phi[i * primes[j]] = 0==i%primes[j] ? phi[i] * primes[j] : phi[i] * (primes[j] - 1);
        }
    }
    cin >> n;
    ll ans = 0;
    int bnd = n/2 + 1;
    for(int i = 2; i <= n; i++){
        while(border > n/i){
            smallsum -= cnt[border--];
        }
        //cerr << ans << endl;
        //cerr << i << ' ' << lp[i] << ' ' << phi[i] << endl;
        ans += i - 1 - phi[i];
        if(lp[i] * 1ll * lp[i] <= n){
            int too_big = i >= bnd ? pref[i] - pref[bnd - 1] : 0;
            int l = n/lp[i];
            int r = min(i - 1, bnd - 1);
            int just_big = r >= l ? pref[r] - pref[l] : 0;
            int cop = phi[i] - 1;
            ans += (cop - too_big - just_big) * 2 + just_big * 3;
        }
        else{
            if(2*i > n)
                continue;
            int cop = phi[i] - 1;
            ans += 2 * cop + (cop - smallsum);
        }
        ++cnt[lp[i]];
        if(lp[i] <= border)
            ++smallsum;
    }
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}