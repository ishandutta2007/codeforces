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

    int T;
    cin >> T;

    while(T--){

        int n, k;
        cin >> n >> k;

        vector<vector<int>> s(k);

        for(int i = 0; i < k; i++){
            int c;
            cin >> c;
            s[i].resize(c);
            for(int j = 0; j < c; j++) cin >> s[i][j];
        }

        cout << "? " << n << " ";
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n" << flush;
        int mx;
        cin >> mx;

        int l = 0, r = k - 1;
        while(l < r){
            int m = (l + r) / 2;

            vector<int> q;
            for(int i = 0; i <= m; i++){
                for(int j : s[i]) q.eb(j);
            }

            cout << "? " << q.size() << " ";
            printv(q, cout);
            cout << flush;

            int t;
            cin >> t;

            if(t == mx) r = m;
            else l = m + 1;
        }

        vector<int> ans(k, mx);
        set<int> q;
        for(int i = 1; i <= n; i++) q.insert(i);
        for(int i : s[l]) q.erase(i);
        cout << "? " << q.size() << " ";
        printv(q, cout);
        cout << flush;
        cin >> ans[l];

        cout << "! ";
        printv(ans, cout);
        cout << flush;

        string str;
        cin >> str;

        if(str == "Incorrect") break;

    }

    return 0;
}