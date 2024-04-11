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
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    vector<vector<bool>> s(3, vector<bool>(n + 2));
    int cnt = 0;
    for(int i = 0; i < q; i++){

        int r, c;
        cin >> r >> c;

        if(s[r][c]){
            if(s[r][c] && s[r == 1 ? 2 : 1][c]) cnt--;
            if(s[r][c] && s[r == 1 ? 2 : 1][c + 1]) cnt--;
            if(s[r][c] && s[r == 1 ? 2 : 1][c - 1]) cnt--;
            s[r][c] = false;
        }
        else{
            s[r][c] = true;
            if(s[r][c] && s[r == 1 ? 2 : 1][c]) cnt++;
            if(s[r][c] && s[r == 1 ? 2 : 1][c + 1]) cnt++;
            if(s[r][c] && s[r == 1 ? 2 : 1][c - 1]) cnt++;
        }

        if(cnt) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}