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

vector<vector<int>> a;

vector<pii > dir = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};

void bfs(int x, int y, int cnt){
    queue<pii > q;
    q.push(mp(x, y));
    a[x][y] = cnt;

    while(!q.empty()){
        int x = q.front().F, y = q.front().S;
        q.pop();
        for(int i = 0; i < 4; i++)
            if(a[x + dir[i].F][y + dir[i].S] == 0){
                a[x + dir[i].F][y + dir[i].S] = cnt;
                q.push(mp(x + dir[i].F, y + dir[i].S));
            }
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    a.resize(n + 2, vector<int>(n + 2, 1));

    int r1, c1;
    cin >> r1 >> c1;

    int r2, c2;
    cin >> r2 >> c2;

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= n; j++) a[i][j] = str[j - 1] - '0';
    }

    bfs(r1, c1, 2);

    if(a[r2][c2] == 2){
        cout << "0\n";
        return 0;
    }

    bfs(r2, c2, 3);

    int ans = MAX;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){

                    if(a[i][j] == 2 && a[k][l] == 3) ans = min(ans, (i - k) * (i - k) + (j - l) * (j - l));

                }
            }

        }
    }

    cout << ans << "\n";

    return 0;
}