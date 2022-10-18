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
    string s;
    cin >> s;

    int b = 0, w = 0;
    for(int i = 0; i < n ;i++){
        if(s[i] == 'B') b++;
        else w ++;
    }

    if(b % 2 && w % 2){
        cout << "-1\n";
        return 0;
    }

    vector<int> ans;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'B'){
            ans.eb(i + 1);
            s[i] = 'W';
            if(s[i + 1] == 'B') s[i + 1] = 'W';
            else s[i + 1] = 'B';
        }
    }
    if(s[n - 1] == 'B'){
        for(int i = 0; i < n - 1; i++){
            if(s[i] == 'W'){
                ans.eb(i + 1);
                s[i] = 'B';
                if(s[i + 1] == 'B') s[i + 1] = 'W';
                else s[i + 1] = 'B';
            }
        }
    }

    cout << ans.size() << "\n";
    printv(ans, cout);

    return 0;
}