#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

#define ln cout << endl;

#define get(x) int x; cin >> x
#define getArr(arr, n) REP(i, n) {cin >> arr[i];}

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// end


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return (((half * half)) * num);
        }
        else {
            return (half * half);
        }
    }
}
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

ll find(ll k, vector<ll> &F) {
    return F[k] == k? k : F[k] = find(F[k], F);
}

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
 
void insert(ll num, set<ll>& room, priority_queue<ll>& pq, unordered_map<ll, ll>& exempt) {
    if (room.empty()) {
        room.emplace(num);
        return;
    }

    auto lower = room.lower_bound(num);
    if (lower == room.end()) {
        pq.emplace(num - *(--lower));
        room.emplace(num);
        return;
    }

    if (lower == room.begin()) {
        pq.emplace(*lower - num);
        room.emplace(num);
        return;
    }

    auto before = prev(lower);
    pq.emplace(*lower - num);
    pq.emplace(num - *before);
    exempt[*lower - *before]++;

    room.emplace(num);
}

void remove(ll num, set<ll>& room, priority_queue<ll>& pq, unordered_map<ll, ll>& exempt) {
    auto lower = room.lower_bound(num);
    if (lower == --room.end()) {
        exempt[num - *(--lower)]++;
        room.erase(num);
        return;
    }

    if (lower == room.begin()) {
        exempt[*(++lower) - num]++;
        room.erase(num);
        return;
    }

    auto before = prev(lower);
    exempt[*(++lower) - num]++;
    exempt[num - *before]++;
    pq.emplace(*lower - *before);    

    room.erase(num);
}

ll myTop(priority_queue<ll>& pq, unordered_map<ll, ll>& exempt) {
    while (exempt[pq.top()]) {
        exempt[pq.top()]--;
        pq.pop();
    }

    if (pq.empty()) return 0;

    return pq.top();
}

void query(priority_queue<ll>& pq, set<ll>& room, unordered_map<ll, ll>& exempt) {

    ll output = 0;
    dbg(myTop(pq, exempt));
    if (room.size() <= 2) {
        dbg(output);
        cout << output << endl;
        return;
    }
    output = *(--room.end()) - *(room.begin()) - myTop(pq, exempt);
    dbg(output);
    cout << output << endl;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 1e9+7;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q; cin >> n >> q;
        set<ll> room;
        priority_queue<ll> pq;
        unordered_map<ll, ll> exempt;
        REP(i, n) {
            ll temp; cin >> temp;
            insert(temp, room, pq, exempt);
        }

        query(pq, room, exempt);

        REP(i, q) {
            ll type, num; cin >> type >> num;
            if (type) {
                insert(num, room, pq, exempt);
            }
            else {
                remove(num, room, pq, exempt);
            }
            query(pq, room, exempt);
        }
    }
    return 0;
}