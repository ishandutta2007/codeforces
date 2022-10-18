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

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> cnt(8);
    for(int i = 0; i < n; i++){
        int px, py;
        cin >> px >> py;
        if(px == x && py > y) cnt[0]++;
        else if(px == x && py < y) cnt[1]++;
        else if(px > x && py == y) cnt[2]++;
        else if(px < x && py == y) cnt[3]++;
        else if(px > x && py > y) cnt[4]++;
        else if(px < x && py > y) cnt[5]++;
        else if(px < x && py < y) cnt[6]++;
        else cnt[7]++;
    }

    int a = cnt[4] + cnt[0] + cnt[5];
    int b = cnt[4] + cnt[2] + cnt[7];
    int c = cnt[7] + cnt[1] + cnt[6];
    int d = cnt[6] + cnt[3] + cnt[5];
    int t = max({a, b, c, d});
    if(t == a && y < 1000000000) cout << t << "\n" << x << " " << y + 1 << "\n";
    else if(t == b && x < 1000000000) cout << t << "\n" << x + 1 << " " << y << "\n";
    else if(t == c && y > 0) cout << t << "\n" << x << " " << y - 1 << "\n";
    else cout << t << "\n" << x - 1 << " " << y << "\n";

    return 0;
}