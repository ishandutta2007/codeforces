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
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream
    
    int s, b;
    cin >> s >> b;

    map<int, int> gold;
    vector<int> a(s);
    for(int i = 0; i < s; i++){
        cin >> a[i];
    }

    for(int i = 0; i < b; i++){
        int d, g;
        cin >> d >> g;
        gold[d] += g;
    }

    for(auto it = next(gold.begin()); it != gold.end(); it++){
        it->second += prev(it)->second;
    }

    vector<int> ans(s);
    for(int i = 0; i < s; i++){
        auto it = gold.lower_bound(a[i]);
        if(it == gold.end() || it->first > a[i]){
            if(it == gold.begin()){
                continue;
            }
            it--;
        }

        ans[i] = it->second;
    }
    printv(ans, cout);

    return 0;
}