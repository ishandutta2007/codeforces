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

#define tiii tuple<int ,int ,int>
#define mt make_tuple
#define gt(i, j) get<i>(j)

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        map<pii, int> e;
        map<pii, vector<int>> aa;
        vector<tiii> pc(n - 2);
        for(int i = 0; i < n - 2; i++){
            int a, b, c;
            cin >> a >> b >> c;

            pc[i] = mt(a, b, c);
            e[mp(a, b)]++;
            e[mp(b, a)]++;
            e[mp(a, c)]++;
            e[mp(c, a)]++;
            e[mp(b, c)]++;
            e[mp(c, b)]++;

            aa[mp(a, b)].eb(i);
            aa[mp(b, a)].eb(i);
            aa[mp(a, c)].eb(i);
            aa[mp(c, a)].eb(i);
            aa[mp(b, c)].eb(i);
            aa[mp(c, b)].eb(i);
        }

        vector<vector<int>> g(n + 1);
        for(auto it : e){
            if(it.S != 1) continue;
            g[it.F.F].eb(it.F.S);
        }

        vector<bool> vis(n + 1);
        int now = 1;
        vector<int> p;
        while(true){
            p.eb(now);
            vis[now] = true;
            for(int i : g[now]){
                if(!vis[i]){
                    now = i;
                    goto next;
                }
            }
            break;
            next:;
        }

        printv(p, cout);

        vis.clear();
        vis.resize(n - 2);

        queue<int> qu;
        vector<int> q;
        for(int i = 0; i < n - 2; i++){
            int cnt = 0;
            if(e[mp(gt(0, pc[i]), gt(1, pc[i]))] == 1) cnt++;
            if(e[mp(gt(0, pc[i]), gt(2, pc[i]))] == 1) cnt++;
            if(e[mp(gt(1, pc[i]), gt(2, pc[i]))] == 1) cnt++;
            if(cnt >= 2) qu.push(i), vis[i] = true;
        }

        while(!qu.empty()){
            int v = qu.front();
            qu.pop();
            q.eb(v + 1);

            int a = gt(0, pc[v]);
            int b = gt(1, pc[v]);
            int c = gt(2, pc[v]);

            e[mp(a, b)]--;
            e[mp(b, a)]--;
            e[mp(a, c)]--;
            e[mp(c, a)]--;
            e[mp(b, c)]--;
            e[mp(c, b)]--;

            for(int i : aa[mp(a, b)]) if(!vis[i]){
                int cnt = 0;
                if(e[mp(gt(0, pc[i]), gt(1, pc[i]))] == 1) cnt++;
                if(e[mp(gt(0, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(e[mp(gt(1, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(cnt >= 2) qu.push(i), vis[i] = true;
            }
            for(int i : aa[mp(a, c)]) if(!vis[i]){
                int cnt = 0;
                if(e[mp(gt(0, pc[i]), gt(1, pc[i]))] == 1) cnt++;
                if(e[mp(gt(0, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(e[mp(gt(1, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(cnt >= 2) qu.push(i), vis[i] = true;
            }
            for(int i : aa[mp(c, b)]) if(!vis[i]){
                int cnt = 0;
                if(e[mp(gt(0, pc[i]), gt(1, pc[i]))] == 1) cnt++;
                if(e[mp(gt(0, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(e[mp(gt(1, pc[i]), gt(2, pc[i]))] == 1) cnt++;
                if(cnt >= 2) qu.push(i), vis[i] = true;
            }

        }

        printv(q, cout);

    }

    return 0;
}