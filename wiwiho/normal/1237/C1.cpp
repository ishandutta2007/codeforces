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
    map<int, map<int, map<int, int>>> a;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y][z] = i + 1;
    }

    map<int, map<int, int>> b;
    for(auto& i : a){
        for(auto& j : i.S){
            for(auto it = j.S.begin(); it != j.S.end(); it++){
                if(next(it) == j.S.end()){
                    b[i.F][j.F] = it->S;
                    break;
                }
                cout << it->S << " " << next(it)->S << "\n";
                it++;
            }
        }
    }

    map<int, int> c;
    for(auto& i : b){
        for(auto it = i.S.begin(); it != i.S.end(); it++){
            if(next(it) == i.S.end()){
                c[i.F] = it->S;
                break;
            }
            cout << it->S << " " << next(it)->S << "\n";
            it++;
        }
    }

    for(auto it = c.begin(); it != c.end(); it++){
        cout << it->S << " " << next(it)->S << "\n";
        it++;
    }

    return 0;
}