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

        int n, x;
        cin >> n >> x;

        string s;
        cin >> s;

        int t = 0;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            if(i != 0) a[i] = a[i - 1];
            if(s[i] == '0'){
                t++;
                a[i]++;
            }
            else{
                t--;
                a[i]--;
            }
        }
        //printv(a, cerr);
        //cerr << t << "\n";

        if(t == 0){
            if(x == 0){
                cout << "-1\n";
                continue;
            }

            int ans = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == x) ans = -1;
            }
            cout << ans << "\n";
            continue;
        }

        int ans = 0;
        if(x == 0) ans++;
        for(int i = 0; i < n; i++){
            if((x - a[i]) % t == 0 && (x - a[i]) / t >= 0) ans++;
        }
        cout << ans << "\n";

    }

    return 0;
}