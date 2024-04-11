//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

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

    vector<int> c;
    int start = 0;

    vector<bool> in(1000001);
    vector<int> lst(1000001, -1);
    int cnt = 0;
    bool ans = true;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a > 0){
            if(lst[a] >= start){
                ans = false;
                //cerr << "test1\n";
                break;
            }
            in[a] = true;
            cnt++;
            lst[a] = i;
        }
        else{
            if(!in[-a]){
                ans = false;
                break;
            }
            in[-a] = false;
            cnt--;
        }

        if(cnt == 0){
            c.eb(i - start + 1);
            //cerr << "test2\n";
            start = i + 1;
        }
    }
    if(cnt != 0){
        ans = false;
        //cerr << "test3\n";
    }

    if(!ans){
        cout << "-1\n";
        return 0;
    }

    cout << c.size() << "\n";
    printv(c, cout);

    return 0;
}