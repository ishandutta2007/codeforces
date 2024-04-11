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
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n + 2, vector<bool>(m + 2));
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            if(s[j - 1] == '.') a[i][j] = true;
        }
    }

    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 0));
    arr[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!a[i][j] || (i == 1 && j == 1)) continue;
            if(arr[i - 1][j] || arr[i][j -1]) arr[i][j]++;
        }
    }

    //for(int i = 1; i <= n; i++) printv(arr[i], cerr);

    if(!arr[n][m]){
        cout << "0\n";
        return 0;
    }

    arr[n][m] = 2;
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            if(!a[i][j] || (i == n && j == m)) continue;
            if(arr[i + 1][j] == 2 || arr[i][j + 1] == 2) arr[i][j]++;
        }
    }

    vector<int> cnt(n + m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == 2) cnt[i - 1 + j - 1]++;
        }
    }

    //for(int i = 1; i <= n; i++) printv(arr[i], cerr);

    for(int i = 1; i < n + m - 2; i++){
        if(cnt[i] == 1) return cout << "1\n", 0;
    }
    cout << "2\n";

    return 0;
}