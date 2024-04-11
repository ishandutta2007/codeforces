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

string check(string a, string b){
    string t(a.size(), ' ');
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]) t[i] = a[i];
        else{
            if(a[i] != 'S' && b[i] != 'S') t[i] = 'S';
            else if(a[i] != 'E' && b[i] != 'E') t[i] = 'E';
            else if(a[i] != 'T' && b[i] != 'T') t[i] = 'T';
        }
    }
    return t;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    set<string> a;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        a.insert(t);
    }

    ll ans = 0;
    for(auto i = a.begin(); i != a.end(); i++){
        for(auto j = next(i); j != a.end(); j++){
            auto it = a.find(check(*i, *j));
            //cerr << *i << " " << *j << " " << check(*i, *j) << "\n";
            if(it != a.end() && *it > *j) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}