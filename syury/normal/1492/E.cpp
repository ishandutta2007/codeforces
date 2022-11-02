//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;

int n, m;
vector<vector<int> > a;
vector<int> pos;
vector<int> neq[N];
vector<pii> srt[N];
vector<int> seq[N];
vector<vector<int> > comp;
int ans[N];
int cnt[N];
int keq[N];

void out(){
    cout << "Yes\n";
    for(int i = 0; i < m; i++)
        cout << ans[i] << ' ';
    exit(0);
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    comp.resize(n);
    for(int i = 0; i < n; i++){
        a[i].resize(m);
        comp[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            srt[j].emplace_back(a[i][j], i);
        }
    }
    for(int j = 0; j < m; j++){
        sort(all(srt[j]));
        int ziga = 0;
        int i = 0;
        while(i < n){
            int k = i;
            while(k < n && srt[j][k].X == srt[j][i].X){
                comp[srt[j][k].Y][j] = ziga;
                ++k;
            }
            seq[j].push_back(srt[j][i].X);
            ++ziga;
            i = k;
        }
    }
    for(int j = 0; j < m; j++){
        ans[j] = a[0][j];
        bool ok = 0;
        for(int i = 1; i < n; i++){
            if(a[i][j] != a[0][j]){
                ok = 1;
                neq[j].push_back(i);
            }
        }
        if(ok)
            pos.push_back(j);
    }
    if(pos.size() > 2 * n){
        cout << "No\n";
        return;
    }
    if(pos.size() <= 2u){
        out();
    }
    for(size_t fst = 0; fst < pos.size(); fst++){
        for(size_t snd = fst + 1; snd < pos.size(); snd++){
            int x = pos[fst], y = pos[snd];
            memset(cnt, 0, n * sizeof(cnt[0]));
            memset(keq, 0, n * sizeof(keq[0]));
            bool fuck = 0;
            int two = -1;
            for(int i: pos){
                if(i != x && i != y)
                    for(int v: neq[i]){
                        ++cnt[v];
                        if(cnt[v] == 2){
                            two = v;
                        }
                        if(cnt[v] > 2){
                            fuck = 1;
                            break;
                        }
                    }
                if(fuck)
                    break;
            }
            if(fuck)
                continue;
            if(two != -1){
                ans[x] = a[two][x];
                ans[y] = a[two][y];
                for(int i = 1; i < n; i++){
                    if(ans[x] != a[i][x])++cnt[i];
                    if(ans[y] != a[i][y])++cnt[i];
                    if(cnt[i] > 2){fuck = 1; break;}
                }
                if(fuck){
                    ans[x] = a[0][x];
                    ans[y] = a[0][y];
                    continue;
                }
                out();
            }
            int ptr = 0;
            int tot = 0;
            for(int i = 0; i < n; i++){
                if(cnt[i]){
                    ++keq[comp[i][y]];
                    if(keq[comp[i][y]] == 1)++tot;
                }
            }
            while(ptr < n){
                int ptr2 = ptr;
                while(ptr2 < n && srt[x][ptr2].X == srt[x][ptr].X){
                    int v = srt[x][ptr2].Y;
                    if(cnt[v]){
                        --keq[comp[v][y]];
                        if(!keq[comp[v][y]])--tot;
                    }
                    ++ptr2;
                }
                if(tot <= 1){
                    ans[x] = srt[x][ptr].X;
                    int what = a[0][y];
                    for(int i = 0; i < n; i++){
                        if(keq[i])
                            what = seq[y][i];
                    }
                    ans[y] = what;
                    out();
                }
                for(int k = ptr; k < ptr2; k++){
                    int v = srt[x][k].Y;
                    if(cnt[v]){
                        ++keq[comp[v][y]];
                        if(1 == keq[comp[v][y]])++tot;
                    }
                }
                ptr = ptr2;
            }
        }
    }
    cout << "No\n";
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}