#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <complex>
#include <bitset>

#define rep(i, n, s) for (int i = (s); i < int(n); i++)
#define per(i, n, s) for (int i = (n - 1); i >= int(s); i--)
#define MM << " " <<
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T>;

using ll = long long;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Pdd = std::pair<double, double>;

template <class T>
bool chmin(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool chmax(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
void vdeb(const std::vector<T> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) {
        if (i == n - 1)
            std::cout << da[i] << std::endl;
        else
            std::cout << da[i] << " ";
    }
}
template<class T>
void vdeb(const std::vector<std::vector<T>> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) {
        std::cout << i << " : ";
        vdeb(da[i]);
    }
}

template <>
void vdeb(const std::vector<std::string> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) { std::cout << da[i] << std::endl; }
}

using namespace std;

const int M = 500;
// const int M = 250;
constexpr int N = 100000;
constexpr ll MOD = 1000000007;

struct is_primes {
    bool is_p[N+1];
    constexpr is_primes() : is_p() {
        rep(i,N,1) is_p[i] = true;
        rep(i,N,2) {
            if(is_p[i]) {
                int now = i*2;
                while(now <= N) {
                    is_p[now] = false;
                    now += i;
                }
            }
        }
   }
   bool operator()(int t) {
       return is_p[t];
   }
} is_prime;


ll gcd_convolution1(vector<ll> &da) {
    int n = da.size();
    rep(i,n,2) {
        if(is_prime(i)) {
            for(int j = (n-1)/i; 0 < j; j--) {
                da[j] += da[j * i];
                da[j] >= MOD ? da[j] -= MOD : da[j];
                
            }
        }
    }
    rep(i,n,0) da[i] = da[i] * da[i] % MOD;
    rep(i,n,2) {
        if(is_prime(i)) {
            for(int j = 1; j * i < n; j++) {
                da[j] -= da[j * i];
                da[j] < 0 ? da[j] += MOD : da[j];
            }
        }
    }
    ll ret = 0;
    rep(i,n,0) {
        ret += da[i] * i;
    }
    return ret % MOD;
}

ll gcd_convolution2(const vector<int> &da) {
    ll ret = 0;
    int n = da.size();
    rep(i,n,0) {
        rep(j,n,0) {
            ret += gcd(da[i], da[j]);
            ret >= MOD ? ret -= MOD : ret;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; cin >> n;
    vector<int> da(n);
    rep(i,n,0) cin >> da[i];
    vector<ll> ans(N+1);
    {
    vector<ll> me(N+1);
    rep(i,M,1) {
        rep(i,N+1,0) me[i] = 0;
        for(int j = i; j <= n; j += i) {
            me[da[j-1]]++;
        }
        ans[i] = gcd_convolution1(me);
    }
    }
    vector<int> mo;
    mo.reserve(n/M);
    rep(i,N+1,M) {
        for(int j = i; j <= n; j += i) {
            mo.push_back(da[j-1]);
        }
        ans[i] = gcd_convolution2(mo);
        mo.clear();
    }
    per(i,N+1,1) {
        for(int j = i*2; j <= N; j += i) {
            ans[i] -= ans[j];
        }
        ans[i] %= MOD;
        (ans[i] < 0 ? ans[i] += MOD : ans[i]);
    }
    ll ret = 0;
    rep(i,N+1,0) {
        ret += ans[i] * i;
    }
    cout << ret % MOD << endl;
}