//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

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
        k++;
//        if(n < k * (k - 1) / 2){
//            cout << "-1\n";
//            continue;
//        }

        string ans(50, '9');
        bool pos = false;
        for(int s = 0; s < k; s++){
            for(int t = 1; t <= 49; t++){
                if(s == 0 && t != 1) continue;
                int tmp = n;
                tmp -= k * (k - 1) / 2;
                tmp -= s * (-9 * t);
                if(tmp % k || tmp < 0) continue;
//            cerr << s << " " << t << " " << tmp << "\n";

                string str(50, '0');
                for(int i = 1; i <= t; i++) str[50 - i] = '9';
                str[49] = '9' - (k - s) + 1;
                int now = tmp / k;
                for(char i : str) now -= i - '0';
                if(s == 0 && now < 0) str[49] = '0' + tmp / k, now = 0;
                else if(now < 0) continue;

                for(int i = t + 1; i <= 50 && now; i++){
                    int ttt = i == t + 1 && s != 0 ? min(8, now) : min(9, now);
                    str[50 - i] = '0' + ttt;
                    now -= ttt;
                }

                ans = min(ans, str);
                pos = true;
//            cerr << str << "\n";
            }
        }
        if(!pos){
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < 50; i++){
            if(ans[i] != '0' || i == 49){
                cout << ans.substr(i) << "\n";
                break;
            }
        }
    }

    return 0;
}