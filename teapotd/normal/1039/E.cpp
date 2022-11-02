#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
#include <immintrin.h>
#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

constexpr int MAX_N = 1e5;
constexpr int Q_BLOCK = 450;
constexpr int SEG_BLOCK = 450;

struct Query {
    alignas(32) array<int, 4> query;
    alignas(32) array<int, 4> answer{-1, -1, -1, -1};
    alignas(32) array<int, 4> left{-1, -1, -1, -1};
    alignas(32) array<int, 4> right{-1, -1, -1, -1};
};

int n, w;
int segs[MAX_N];
Query queries[Q_BLOCK];

void process(Query& data, int begin, int end) {
    auto query = _mm_load_si128((__m128i*)&data.query);
    auto answer = _mm_load_si128((__m128i*)&data.answer);
    auto left = _mm_load_si128((__m128i*)&data.left);
    auto right = _mm_load_si128((__m128i*)&data.right);

    rep(i, begin, end) {
        auto a = _mm_set1_epi32(segs[i]);
        auto b = _mm_add_epi32(a, query);

        left = _mm_max_epi32(left, a);
        right = _mm_min_epi32(right, b);

        auto mask = _mm_cmpgt_epi32(left, right);
        answer = _mm_sub_epi32(answer, mask); // mask parts are -1

        left = _mm_blendv_epi8(left, a, mask);
        right = _mm_blendv_epi8(right, b, mask);
    }

    _mm_store_si128((__m128i*)&data.query, query);
    _mm_store_si128((__m128i*)&data.answer, answer);
    _mm_store_si128((__m128i*)&data.left, left);
    _mm_store_si128((__m128i*)&data.right, right);
}

void processBlock(int block) {
    for (int i = 0; i < n; i += SEG_BLOCK) {
        int lim = min(i+SEG_BLOCK, n);

        rep(j, 0, block) {
            process(queries[j], i, lim);
        }
    }
}

void run() {
    int q; cin >> n >> w >> q;
    rep(i, 0, n) cin >> segs[i];

    for (int i = 0; i < q; i += Q_BLOCK) {
        int block = min(Q_BLOCK, q-i);
        each(x, queries) x = {};

        rep(j, 0, block) {
            int tmp; cin >> tmp;
            queries[j/4].query[j%4] = w - tmp;
        }

        processBlock((block+3) / 4);

        rep(j, 0, block) {
            cout << queries[j/4].answer[j%4] << '\n';
        }
    }
}