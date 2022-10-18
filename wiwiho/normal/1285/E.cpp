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
    cerr.tie(0);

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        map<pii, vector<int>> e;
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            e[mp(l, 0)].eb(i);
            e[mp(r, 1)].eb(i);
        }

        set<int> now;
        vector<int> ans(n);
        int lst = 0, cnt = 0;
        int mxcnt = 0;
        int o = 0;
        for(auto& i : e){
            vector<int> wait;
            for(auto j : i.S){
                if(i.F.S == 0) wait.eb(j);
                else now.erase(j);
            }
            if(wait.size() + now.size() != cnt){
                if(cnt == 1 && lst != 0 && wait.size() + now.size() != 0) ans[*now.begin()]++;
                if(cnt == 0) o++;
                lst = cnt;
                cnt = wait.size() + now.size();
                mxcnt = max(mxcnt, cnt);
                //cerr << cnt << "\n";
            }
            for(int j : wait) now.insert(j);
            //cerr << i.F.F << " " << i.F.S << "  ";
            //printv(now, cerr);
        }

        //cerr << o << "\n";
        //printv(ans, cerr);

        int mx = 0;
        for(int i = 0; i < n; i++) mx = max(mx, ans[i]);
        if(mx > 0) cout << o + mx << "\n";
        else if(mxcnt > 1) cout << o << "\n";
        else cout << o - 1 << "\n";
    }

    return 0;
}