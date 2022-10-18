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
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000'000'007;
const ll MAX = 1000000001;

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        cnt[t]++;
    }

    int remain = 0;
    int drink = 0;
    for(auto it = cnt.begin(); it != cnt.end(); it++){
        drink += it->second / 2;
        if(it->second % 2){
            remain++;
        }
    }

    cerr << remain << " " << ceil((double)n / 2) << " " << drink << "\n";
    remain -= ceil((double)n / 2) - drink;
    cout << (n - remain) << "\n";

    return 0;
}