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

vector<ll> a;
int n, s;

int check(int p){
    int cnt = 0;
    ll t = 0;
    for(int i = 0; i < n; i++){
        if(i == p) continue;
        if(t + a[i] > s) break;
        t += a[i];
        cnt++;
    }
    return cnt;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> n >> s;

        a.clear();
        a.resize(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int mx = 0;
        ll sum = 0;
        int i;
        for(i = 0; i < n; i++){
            if(sum + a[i] > s) break;
            if(a[i] > a[mx]) mx = i;
            sum += a[i];
        }

        int t1 = check(-1);
        int t2 = check(mx);
        int t3 = i < n ? check(i) : 0;

        if(t1 >= t2 && t1 >= t3) cout << "0\n";
        else if(t2 >= t3) cout << mx + 1 << "\n";
        else cout << i + 1 << "\n";
    }

    return 0;
}