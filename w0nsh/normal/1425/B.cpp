#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define f first
#define s second
#define FOR(i, s) for(int i = 0; i < s; i++)

typedef long long ll;

const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const ll BIG_INF = 1e18;
const int T = (1<<19);

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >

template<class T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return abs(a); }

struct plecak_zawsze_biore{
    vi ile;

    plecak_zawsze_biore(){
        ile = vi(4010);
        ile[0] = 1;
    }

    void add(int val){
        for(int i = sz(ile) - 1; i >= val; i--)
            ile[i] = (ile[i] + ile[i - val]) % INF;
    } 

    int val(int poz){
        return ile[poz];
    }
};

struct plecak_zawsze_biore2{
    vi ile;
    int shift = 4010;

    plecak_zawsze_biore2(){
        ile = vi(8040);
        ile[shift] = 1;
    }

    void add(int val){
        vi nowy_ile(8040);

        for(int i = 0; i < sz(ile) - val; i++)
            nowy_ile[i] = (nowy_ile[i] + ile[i + val]) % INF;
        for(int i = val; i < sz(ile); i++)             
            nowy_ile[i] = (nowy_ile[i] + ile[i - val]) % INF;
        ile = nowy_ile;
    }

    int val(int poz){
        return ile[poz + shift];
    }
};  


struct plecak_moge_nie_wziac{
    vi ile;
    int shift = 4010;

    plecak_moge_nie_wziac(){
        ile = vi(8040);
        ile[shift] = 1;
    }

    void add(int val){
        vi nowy_ile = ile;
        for(int i = 0; i < sz(ile) - val; i++)
            nowy_ile[i] = (nowy_ile[i] + ile[i + val]) % INF;
        for(int i = val; i < sz(ile); i++)             
            nowy_ile[i] = (nowy_ile[i] + ile[i - val]) % INF;
        ile = nowy_ile;
    }

    int val(int poz){
        return ile[poz + shift];
    }
};  

vi cykle;
int odw[N];

vvi G(N);

int dfs(int start){
    int ret = 1;
    odw[start] = 1;

    for(auto & u : G[start])
        if(!odw[u])
            ret += dfs(u);
    
    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        G[a].pb(b);
        G[b].pb(a);
    }

    odw[1] = 1;
    for(auto & u : G[1])
        if(!odw[u])
            cykle.pb(dfs(u) + 1);

    plecak_zawsze_biore p1;
    for(auto & u : cykle)
        p1.add(u);
    ll ret = 0;

    plecak_moge_nie_wziac pref;
    vector<plecak_moge_nie_wziac> dp_pref;

    plecak_zawsze_biore2 pref2;
    vector<plecak_zawsze_biore2> dp_pref2;
    
    dp_pref.pb(pref); 
    dp_pref2.pb(pref2);

    for(int i = 0; i < sz(cykle); i++){
        pref.add(cykle[i]);
        dp_pref.pb(pref);

        pref2.add(cykle[i]);
        dp_pref2.pb(pref2);
    }

    plecak_moge_nie_wziac suf;
    plecak_zawsze_biore2 suf2;
    // exit(0);
    
    for(int i = sz(cykle) - 1; i >= 0; i--){
        for(int a = 1; a < cykle[i]; a++){
            int b = cykle[i] - a;
            // wzialem a - b
            int diff = a - b;

            for(int ile_z_suf = -2000; ile_z_suf <= 2000; ile_z_suf++){
                // diff = -(pref + suf) -> diff + duf = -pref
                int ile_z_pref = - diff - ile_z_suf;
                if(ile_z_pref >= -2000 and ile_z_pref <= 2000)
                    ret = (ret + 1ll * dp_pref[i].val(ile_z_pref) * suf.val(ile_z_suf)) % INF;
            }
        }
        for(int a = 1; a < cykle[i] - 1; a++){
            int b = cykle[i] - a - 1;
            int diff = a - b;

            for(int ile_z_suf = -2000; ile_z_suf <= 2000; ile_z_suf++){
                // diff = -(pref + suf) -> diff + duf = -pref
                int ile_z_pref = - diff - ile_z_suf;
                if(ile_z_pref >= -2000 and ile_z_pref <= 2000)
                    ret = (ret + 1ll * dp_pref[i].val(ile_z_pref) * suf.val(ile_z_suf)) % INF;
            }
        }

        int a = 0;
        int b = cykle[i] - 1;
        int diff = a - b;

        for(int ile_z_suf = -2000; ile_z_suf <= 2000; ile_z_suf++){
            // diff = -(pref + suf) -> diff + duf = -pref
            int ile_z_pref = -diff - ile_z_suf;
            if(ile_z_pref >= -2000 and ile_z_pref <= 2000)
                ret = (ret + 1ll * dp_pref2[i].val(ile_z_pref) * suf2.val(ile_z_suf)) % INF;
        }

        a = cykle[i] - 1;
        b = 0;
        diff = a - b;

        for(int ile_z_suf = -2000; ile_z_suf <= 2000; ile_z_suf++){
            // diff = -(pref + suf) -> diff + duf = -pref
            int ile_z_pref = -diff - ile_z_suf;
            if(ile_z_pref >= -2000 and ile_z_pref <= 2000)
                ret = (ret + 1ll * dp_pref2[i].val(ile_z_pref) * suf2.val(ile_z_suf)) % INF;
        }

        suf.add(cykle[i]);
        suf2.add(cykle[i]);
    }

    cout << (ret * 2 + (m % 2 == 0) * p1.val(m / 2)) % INF << '\n';
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
}