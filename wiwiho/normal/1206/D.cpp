//#define NDEBUG

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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<set<int>> g;
int n;

int bfs(int s, int e){

    vector<bool> inq(n);
    queue<pii> q;
    inq[s] = true;
    q.push(mp(s, 0));
    while(!q.empty()){
        if(q.front().F == e) return q.front().S;
        for(int i : g[q.front().F]){
            if(inq[i]) continue;
            inq[i] = true;
            q.push(mp(i, q.front().S + 1));
        }
        q.pop();
    }
    return -1;
}

int main(){
    StarBurstStream
    
    cin >> n;

    vector<vector<int>> b(65);

    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        for(int j = 0; (1LL << j) <= a; j++){
            if((1LL << j) & a){
                b[j].pb(i);
            }
        }
    }

    g.resize(n);
    set<pii> e;
    for(int i = 0; i < 65; i++){
        if(b[i].size() >= 3){
            cout << "3\n";
            return 0;
        }
        else if(b[i].size() == 2){
            g[b[i][0]].insert(b[i][1]);
            g[b[i][1]].insert(b[i][0]);
            e.insert(mp(min(b[i][0], b[i][1]), max(b[i][0], b[i][1])));
        }
    }

    int ans = -1;
    for(pii p : e){
        g[p.F].erase(p.S);
        g[p.S].erase(p.F);
        int t = bfs(p.F, p.S);
        if(t != -1){
            if(ans == -1 || t + 1 < ans) ans = t + 1;
        }
        g[p.F].insert(p.S);
        g[p.S].insert(p.F);
    }

    cout << ans << "\n";

    return 0;
}