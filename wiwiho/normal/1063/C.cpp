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

    int n;
    cin >> n;

    cout << "0 0\n" << flush;
    int lst = 0;
    string s;
    cin >> s;
    if(s == "white") lst = 1;

    int y = 1000000000;
    n--;

    if(n >= 15){
        int tmp = 15;
        int l = 0, r = 1000000000;
        while(tmp--){
            int mid = (l + r) / 2;
            cout << "0 " << mid << "\n" << flush;
            int t = 0;
            cin >> s;
            if(s == "white") t = 1;
            if(t != lst){
                //cerr << mid << "\n";
                y = mid - 1;
                r = mid;
            }
            else{
                l = mid;
            }
        }
        n -= 15;
    }

    int x = 1000000000;
    int l = 0, r = 1000000000;
    while(n--){
        int mid = (l + r) / 2;
        cout << mid << " 0\n" << flush;
        int t = 0;
        cin >> s;
        if(s == "white") t = 1;
        if(t != lst){
            //cerr << mid << "\n";
            x = mid - 1;
            r = mid;

        }
        else{
            l = mid;
        }
    }

   cout << "0 " << y << " " << x << " 0\n" << flush << "\n";


    return 0;
}