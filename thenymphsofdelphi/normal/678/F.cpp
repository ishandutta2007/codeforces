#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 3e5 + 5, S = sqrt(N * 17) + 5;
const ll infll = (ld)1e18 + 1e9 + 7;

// array<T, 3> represents a line. (constant term, slope, auxiliary variable)
template<class T, bool GET_MAX = false>
struct sorted_line_container: deque<array<T, 3>>{
#define USE(x) using deque<array<T, 3>>::x;
    USE(size) USE(empty) USE(front) USE(back) USE(begin) USE(end) USE(rbegin) USE(rend) USE(pop_front) USE(pop_back) USE(erase) USE(push_back) USE(push_front)
#undef USE
    static constexpr T inf = numeric_limits<T>::max();
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    T div(T a, T b){ return a / b - ((a ^ b) < 0 && a % b); }
    bool isect_front(class deque<array<T, 3>>::iterator x, class deque<array<T, 3>>::iterator y){
        if(y == end()){ (*x)[2] = inf; return false; }
        else{ (*x)[2] = div((*y)[0] - (*x)[0], (*x)[1] - (*y)[1]); return (*x)[2] >= (*y)[2]; }
    }
    bool isect_back(class deque<array<T, 3>>::reverse_iterator x, class deque<array<T, 3>>::reverse_iterator y){
        if(x == rend()) return false;
        else{ (*x)[2] = div((*y)[0] - (*x)[0], (*x)[1] - (*y)[1]); return (*x)[2] >= (*y)[2]; }
    }
    T eval(array<T, 3> line, T x){
        return line[0] + line[1] * x;
    }
    // Slopes must increase monotonously
    template<bool FIRST_CALL = true>
    void inc_push(array<T, 3> L){
        if(FIRST_CALL && !GET_MAX){
            dec_push<false>({-L[0], -L[1]});
            return;
        }
        assert(empty() || back()[1] <= L[1]);
        if(empty() || back()[1] < L[1] || back()[0] < L[0]){
            if(!empty() && L[1] == back()[1]) erase(-- end());
            L[2] = inf, push_back(L); isect_back(++ rbegin(), rbegin());
            while((int)size() >= 2 && isect_back(++ ++ rbegin(), ++ rbegin())) erase(-- -- end()), isect_back(++ rbegin(), rbegin());
        }
    }
    // Slopes must decrease monotonously
    template<bool FIRST_CALL = true>
    void dec_push(array<T, 3> L){
        if(FIRST_CALL && !GET_MAX){
            inc_push<false>({-L[0], -L[1]});
            return;
        }
        assert(empty() || L[1] <= front()[1]);
        if(empty() || L[1] < front()[1] || front()[0] < L[0]){
            if(!empty() && L[1] == front()[1]) erase(begin());
            L[2] = 0, push_front(L), isect_front(begin(), ++ begin());
            while((int)size() >= 2 && isect_front(begin(), ++ begin())) erase(++ begin());
        }
    }
    // Other queries must not be called and x must be decreasing
    // O(1)
    T dec_query(T x){
        assert(!empty());
        while((int)size() >= 2 && eval(*rbegin(), x) <= eval(*++ rbegin(), x)) pop_back(); back()[2] = inf;
        return eval(*rbegin(), x) * (GET_MAX ? 1 : -1);
    }
    // Other queries must not be called and x must be increasing
    // O(1)
    T inc_query(T x){
        assert(!empty());
        while((int)size() >= 2 && eval(*begin(), x) <= eval(*++ begin(), x)) pop_front();
        return eval(*begin(), x) * (GET_MAX ? 1 : -1);
    }
    // Other queries must not be called
    // O(log n)
    T query(T x){
        assert(!empty());
        if((int)size() == 1) return eval(*begin(), x) * (GET_MAX ? 1 : -1);
        if(eval(*begin(), x) >= eval(*++ begin(), x)) return eval(*begin(), x) * (GET_MAX ? 1 : -1);
        int low = 0, high = (int)size() - 1;
        while(high - low >= 2){
            int mid = low + (high - low >> 1);
            (eval(*(begin() + mid), x) < eval(*(begin() + mid + 1), x) ? low : high) = mid;
        }
        return eval(*(begin() + low + 1), x) * (GET_MAX ? 1 : -1);
    }
};

sorted_line_container <ll, 1> cac;

struct Query{
    int type, a, b, i, q;

    int idrm = N;

    Query(){

    }

    Query(int type, int a, int b, int i, int q): type(type), a(a), b(b), i(i), q(q){

    }
};

struct Hash{
    ll operator()(const pii& lhs) const{
        return (ll)lhs.fi * 2000000002 + lhs.se;
    }
};

int n;

Query qu[N];
vi vidxquadd;

unordered_set <pii, Hash> sttlines;

void recal(int bl, int br){
    if (bl > br){
        return;
    }
    cac.clear();
    sttlines.clear();
    Fora(&idx, vidxquadd){
        if (idx >= bl){
            continue;
        }
        if (qu[idx].idrm > br){
            cac.inc_push({{qu[idx].b, qu[idx].a, 0}});
        }
        else if (qu[idx].idrm >= bl){
            sttlines.emplace(qu[idx].a, qu[idx].b);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> qu[i].type;
        if (qu[i].type == 1){
            cin >> qu[i].a >> qu[i].b;
            vidxquadd.emplace_back(i);
        }
        else if (qu[i].type == 2){
            cin >> qu[i].i;
            qu[qu[i].i].idrm = i;
        }
        else{
            cin >> qu[i].q;
        }
    }
    sort(bend(vidxquadd), [](int lhs, int rhs){
        return qu[lhs].a < qu[rhs].a;
    });
    ForE(i, 1, n){
        if (qu[i].type == 1){
            sttlines.emplace(qu[i].a, qu[i].b);
        }
        else if (qu[i].type == 2){
            sttlines.erase(make_pair(qu[qu[i].i].a, qu[qu[i].i].b));
        }
        else{
            ll ans = (cac.empty() ? -infll : cac.query(qu[i].q));
            Fora(&lines, sttlines){
                ans = max(ans, (ll)lines.fi * qu[i].q + lines.se);
            }
            if (ans == -infll){
                cout << "EMPTY SET" << endl;
            }
            else{
                cout << ans << endl;
            }
        }
        if (i % S == 0){
            recal(i + 1, min(i + S, n));
        }
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/