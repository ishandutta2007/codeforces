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

const ll MOD = 998244353;
const ll MAX = 2000000001;

int main(){
    StarBurstStream

    int n;
    cin >> n;
    string s;
    cin >> s;

    int now = 0;
    vector<pair<char, int>> adj(1);
    adj.reserve(100005);

    int g = 0;
    for(int i = 0; i < s.size(); i++){
        if(i > 0 && s[i] == s[i - 1]){
            adj.back().S++;
        }
        else{
            adj.pb(mp(s[i], 1));
        }
        if(s[i] == 'G'){
            g++;
        }
    }
    adj.pb(mp(0, 0));

    int ans = 0;
    for(int i = 1; i < adj.size() - 1; i++){

        if(adj[i].F == 'G'){

            if(g > adj[i].S){
                ans = max(ans, adj[i].S + 1);
            }
            else{
                ans = max(ans, adj[i].S);
            }

        }
        else if(adj[i].S == 1){

            if(g > adj[i - 1].S + adj[i + 1].S){
                ans = max(ans, adj[i - 1].S + adj[i + 1].S + 1);
            }
            else{
                ans = max(ans, adj[i - 1].S + adj[i + 1].S);
            }

        }

    }

    cout << ans << "\n";

    return 0;

}