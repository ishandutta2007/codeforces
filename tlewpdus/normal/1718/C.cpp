#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, Q;
ll A[200100];
vector<int> primes;
int sieve[200100];

struct DS {
    vector<ll> vals;
    priority_queue<pll> pq;
    void init(vector<ll> v) {
        vals = v;
        for (int i = 0; i < v.size(); i++) {
            pq.push({v[i], i});
        }
    }
    ll get_max() {
        while (!pq.empty()) {
            pll tmp = pq.top();
            if (vals[tmp.second] == tmp.first) return tmp.first;
            pq.pop();
        }
        return -1;
    }
    void upd(int idx, ll val) {
        vals[idx] += val;
        pq.emplace(vals[idx], idx);
    }
};

int main() {
    int ttt;

    for (int i = 2; i < 200100; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (ll j = (ll)i * i; j < 200100; j += i) {
            sieve[j] = true;
        }
    }
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d%d", &N, &Q);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }
        vector<DS> ds;
        vector<int> ps;
        for (int &p : primes) {
            if (p > N) break;
            if (N % p == 0) {
                DS d;
                vector<ll> sums(N / p, 0);
                for (int i = 0; i < N; i++) {
                    sums[i % (N / p)] += A[i] * (N / p);
                }
                d.init(sums);
                ds.push_back(d);
                ps.push_back(p);
            }
        }
        auto query = [&ds]() {
            ll ans = 0;
            for (DS &d : ds) {
                ans = max(ans, d.get_max());
            }
            return ans;
        };
        printf("%lld\n", query());
        for (int i = 0; i < Q; i++) {
            int a;
            ll b;
            scanf("%d%lld", &a, &b);
            --a;
            for (int j = 0; j < ps.size(); j++) {
                int p = ps[j];
                ds[j].upd(a % (N / p), (b - A[a]) * (N / p));
            }
            A[a] = b;
            printf("%lld\n", query());
        }
    }

    return 0;
}