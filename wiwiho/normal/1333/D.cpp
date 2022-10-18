//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    deque<deque<int>> q;
    ll cnt = 0;
    while(true){
        q.eb();
        for(int i = 0; i < n - 1; i++){
            if(s[i] == 'R' && s[i + 1] == 'L') q.back().eb(i + 1);
        }
        if(q.back().empty()){
            q.pob;
            break;
        }
        for(int i : q.back()){
            s[i - 1] = 'L'; s[i] = 'R';
        }
        cnt += q.back().size();
    }

    if(k < q.size() || k > cnt){
        cout << "-1\n";
        return 0;
    }

    while(k > q.size()){
        cout << "1 " << q.front().front() << "\n";
        q.front().pof;
        if(q.front().empty()) q.pof;
        k--;
    }

    while(!q.empty()){
        cout << q.front().size() << " ";
        printv(q.front(), cout);
        q.pof;
    }

    return 0;
}