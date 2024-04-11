#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> two;
    vector<int> one;

    int d = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a == 1){
            one.pb(i + 1);
        }
        else{
            if(two.empty()){
                d += a;
            }
            else{
                d += a - 2;
                two.back().S--;
                a--;
            }
            two.pb(mp(i + 1, a));
        }
    }

    if(d < one.size()){
        cout << "NO\n";
        return 0;
    }

    cout << "YES " << (two.size() - 1 + min((int)one.size(), 2)) << "\n";
    cout << (two.size() - 1 + one.size()) << "\n";

    for(int i = 0; i < two.size() - 1; i++){
        cout << two[i].F << " " << two[i + 1].F << "\n";
    }

    int now = 0;

    if(now < one.size()){
        cout << one[now] << " " << two.back().F << "\n";
        two.back().S--;
        now++;
    }

    auto it = two.begin();
    for(; now < one.size(); now++){
        while(it != two.end() && it->S == 0) it++;
        assert(it != two.end());
        cout << one[now] << " " << it->F << "\n";
        it->S--;
    }

    return 0;

}