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
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int real_num;
int n, k, block;
vector<int> primes, ex, ex1;
bool dead[N];
int qu[N];

void gen_primes(){
    vector<char> sieve(n + 1, false);
    for(int i = 2; i <= n; i++){
        if(sieve[i])continue;
        primes.push_back(i);
        int curr = 1;
        for(int j = 2*i; j <= n; j += i){
            curr += int(sieve[j])^1;
            sieve[j] = true;
        }
        ex.push_back(curr);
        ex1.push_back(curr);
    }
    int old=0;
    for(int i = ex.size()-1; i >= 0; i--){
        ex[i] += old;
        old = ex[i];
    }
    k = primes.size();
    block = max(1, int(sqrt(k)));
}

int qcnt = 0;

int query(int type, int x){
//    cerr << type << ' ' << x << endl;
    ++qcnt;
    assert(qcnt < 10000);
#ifdef LOCAL
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i%x == 0){
            ans += dead[i]^1;
            if(type && i != real_num)dead[i] = 1;
        }
    }
    return ans;
#else
    cout << char('A' + type) << ' ' << x << endl;
    int ans;
    cin >> ans;
    return ans;
#endif
}

void answer(int x){
#ifdef LOCAL
    assert(x == real_num);
#else
    cout << "C " << x << endl;
#endif
    exit(0);
}

void solve(){
#ifdef LOCAL
    n = 10; real_num = 4;
    //n = 100000;
    //real_num = 99991;
    //real_num = rand()%n + 1;
#else
    cin >> n;
#endif
    if(n == 1){
        cout << "C " << n << endl;
        return;
    }
    gen_primes();
    vector<int> b(k);
    int minp = -1;
    for(int i = 0; i < k; i++){
        b[i] = query(1, primes[i]);
        if((i+1)%block == 0 || i == k - 1){
            int A = query(0, 1);
            if(minp == -1 && (i == k - 1 || A != 1+ex[i + 1])){
                int j = max(0, i - block + 1);
                for(int t = j; t <= i; t++){
                    int q = query(0, primes[t]);
                    if(q > 0){
                        minp = t;
                        break;
                    }
                }
            }
        }
    }
    if(minp == -1)
        answer(1);
    vector<int> divs = {primes[minp]};
    for(int i = minp + 1; i < k; i++){
        if(ex1[i] != b[i])
            divs.push_back(primes[i]);
    }
    ll ans = 1;
    for(int p: divs){
        ll pw = p*1ll*p;
        while(pw <= n && query(0, pw) > 0){
            pw *= p;
        }
        pw /= p;
        ans *= pw;
    }
    answer(ans);
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}