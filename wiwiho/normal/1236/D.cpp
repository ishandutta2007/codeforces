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

    ll n, m, k;
    cin >> n >> m >> k;

    map<int, set<int>> rowl, columnl;
    map<int, set<int, greater<>>> rowg, columng;
    for(int i = 0; i < k ;i++){
        int x, y;
        cin >> x >> y;
        rowl[x].insert(y);
        columnl[y].insert(x);
        rowg[x].insert(y);
        columng[y].insert(x);
    }

    int u = 1, d = n, l = 1, r = m;
    int dir = 0;
    ll cnt = 0;
    while(u <= d && l <= r){
        //cerr << u << " " << d << " " << l << " " << r << " " << cnt << " " << dir << "\n";
        if(dir == 0){
            auto it = rowl[u].lower_bound(l);
            int stop = it == rowl[u].end() ? r : *it - 1;
            //cerr << stop << "\n";
            stop = min(stop, r);
            cnt += stop - l + 1;
            r = stop;
            u++;
            if(rowg[u].find(r) != rowg[u].end()){
                break;
            }
        }
        else if(dir == 1){
            auto it = columnl[r].lower_bound(u);
            int stop = it == columnl[r].end() ? d : *it - 1;
            //cerr << stop << "\n";
            stop = min(stop, d);
            cnt += stop - u + 1;
            d = stop;
            r--;
            if(rowg[d].find(r) != rowg[d].end()){
                break;
            }
        }
        else if(dir == 2){
            auto it = rowg[d].lower_bound(r);
            int stop = it == rowg[d].end() ? l : *it + 1;
            //cerr << stop << "\n";
            stop = max(stop, l);
            cnt += r - stop + 1;
            l = stop;
            d--;
            if(rowg[d].find(l) != rowg[d].end()){
                break;
            }
        }
        else{
            auto it = columng[l].lower_bound(d);
            int stop = it == columng[l].end() ? u : *it + 1;
            //cerr << stop << "\n";
            stop = max(stop, u);
            cnt += d - stop + 1;
            u = stop;
            l++;
            if(rowg[u].find(l) != rowg[u].end()){
                break;
            }
        }
        dir = (dir + 1) % 4;
    }

    if(cnt == n * m - k) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}