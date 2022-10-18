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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

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

    vector<int> f(n + 1);
    set<int> r;
    for(int i = 1; i <= n; i++) r.insert(i);
    for(int i = 1; i <= n; i++){
        cin >> f[i];
        if(f[i] != 0) r.erase(f[i]);
    }

    vector<int> tmp;
    for(int i : r){
        if(f[i] == 0){
            tmp.eb(i);
        }
    }

    if(tmp.size() == 1){
        for(int i : r) if(i != tmp[0]) f[tmp[0]] = i;
        r.erase(f[tmp[0]]);
    }
    else if (!tmp.empty()){
        for(int i : tmp) r.erase(i);
        for(int i = 0; i < tmp.size(); i++){
            f[tmp[i]] = tmp[(i + 1) % (int)tmp.size()];
        }
    }
    //printv(r, cerr);

    //cerr << "test\n";

    for(int i = 1; i <= n; i++){
        //cerr << i << "\n";
        if(f[i] != 0) continue;
        //cerr << i << "\n";
        //printv(r, cerr);
        f[i] = *r.begin();
        r.erase(r.begin());
    }


    f.erase(f.begin());
    printv(f, cout);

    return 0;
}