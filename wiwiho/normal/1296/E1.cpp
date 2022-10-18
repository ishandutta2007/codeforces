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

    string s;
    cin >> s;

    string ans(n, '2');
    vector<vector<int>> pos(26);
    for(int i = 0; i < n; i++){
        pos[s[i] - 'a'].eb(i);
    }

    char lst1 = 'a' - 1, lst2 = 'a' - 1;
    for(int i = 0; i < n; i++){
        int cnt0 = 0, cnt1 = 0;
        for(int j = 0; j < s[i] - 'a'; j++){
            for(auto it = upper_bound(iter(pos[j]), i); it != pos[j].end(); it++){
                if(ans[*it] == '0') cnt0++;
                if(ans[*it] == '1') cnt1++;
            }
        }
        if(ans[i] == '2'){
            if(cnt1 > 0 && cnt0 > 0){
                cout << "NO\n";
                return 0;
            }
            else if(cnt0 > 0) ans[i] = '1';
            else ans[i] = '0';
        }
        for(int j = 0; j < s[i] - 'a'; j++){
            for(auto it = upper_bound(iter(pos[j]), i); it != pos[j].end(); it++){
                if(ans[*it] == '2') ans[*it] = ans[i] == '0' ? '1' : '0';
                else if(ans[*it] == ans[i]){
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n" << ans << "\n";

    return 0;
}