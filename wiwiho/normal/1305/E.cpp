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
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    if(n == 1){
        if(m == 0) cout << "1\n";
        else cout << "-1\n";
        return 0;
    }

    vector<int> a(n);
    a[0] = 10000;
    a[1] = 20000;
    int now = 0;
    map<int, int> cnt;
    cnt[30000] = 1;


    int i;
    for(i = 2; i < n; i++){
        int t = i * 10000 + 10000;
        if(cnt[t] + now > m) break;
        a[i] = t;
        now += cnt[t];
        for(int j = 0; j < i ;j++) cnt[a[i] + a[j]]++;
    }

    if(i == n && now < m){
        cout << "-1\n";
        return 0;
    }
//    printv(a, cerr);

    bool tmp = false;
    if(now < m){
        for(pii j : cnt){
            if(j.F > a[i - 1] && j.S == m - now){
                a[i] = j.F;
                tmp = true;
                break;
            }
        }
        if(!tmp) return cout << "-1\n", 0;
        else i++;
    }


    int tt = a[i - 1] + 1;
    for(; i < n; i++){
        a[i] = tt++;
    }

    printv(a, cout);

    return 0;
}