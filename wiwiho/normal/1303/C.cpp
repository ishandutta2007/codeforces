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

vector<set<int>> g;
vector<int> ans;
vector<bool> vst;
bool flag = true;

void dfs(int now){
    ans.eb(now);
    vst[now] = true;
    if(g[now].size() > 2){
        flag = false;
        return;
    }

    for(int i : g[now]){
        if(vst[i]) continue;
        dfs(i);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        string s;
        cin >> s;

        g.clear();
        g.resize(26);

        for(int i = 0; i < s.size() - 1; i++){
            g[s[i] - 'a'].insert(s[i + 1] - 'a');
            g[s[i + 1] - 'a'].insert(s[i] - 'a');
        }

        ans.clear();
        vst.clear();
        vst.resize(26);
        flag = true;
        for(int i = 0; i < 26; i++){
            if(!vst[i] && g[i].size() <= 1) dfs(i);
        }
        if(!flag || ans.size() != 26){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i : ans){
            cout << (char)('a' + i);
        }
        cout << "\n";

    }

    return 0;
}