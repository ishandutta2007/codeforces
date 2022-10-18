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

        int n, d;
        cin >> n >> d;

        if(n > 700){
            cout << "NO\n";
            continue;
        }

        vector<int> r(700), now(700);
        r[0] = 1;
        int sum = 0;
        for(int i =0; i < n; i++){
            r[i]--;
            now[i]++;
            sum += i;
            r[i + 1] += 2;
        }

        if(sum < d){
            cout << "NO\n";
            continue;
        }

        bool ans = true;
        for(int i = n - 1; i > 0 && sum > d; i--){
            int lst = i;
            for(int j = i - 1; j > 0; j--){
                if(!r[j]) continue;
                lst = j;
                if(sum - i + j == d) break;
            }
            if(lst == i){
                cout << "NO\n";
                ans = false;
                break;
            }
            sum = sum - i + lst;
            r[lst]--;
            now[i]--;
            now[lst]++;
            r[lst + 1] += 2;
        }
        if(!ans) continue;

        vector<int> p;
        deque<int> up = {1};
        int cnt = 2;

        for(int i = 1; now[i]; i++){
            deque<int> tmp;
            for(int j = 0; j < now[i]; j++){
                p.eb(up.front());
                tmp.eb(cnt++);
                if(j % 2) up.pof;
            }
            up = tmp;
        }

//        printv(now, cerr);
        cout << "YES\n";
        printv(p, cout);

    }

    return 0;
}