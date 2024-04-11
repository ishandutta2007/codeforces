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

const ll MOD = 998244353;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(n, vector<int>(n));
    vector<int> rowsum(n), columnsum(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == 'B'){
                a[i][j] = 1;
                rowsum[i]++;
                columnsum[j]++;
            }
        }
    }

    vector<vector<int>> rowclick(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        int t = 0;
        if(rowsum[i] == 0) continue;
        for(int j = n - 1; j >= 0; j--){
            t += a[i][j];
            if(j + k < n) t -= a[i][j + k];
            if(t == rowsum[i]) rowclick[i][j] = 1;
        }
    }

    vector<vector<int>> rowcnt(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = n - 1; j >= 0; j--){
            now += rowclick[j][i];
            if(j + k < n) now -= rowclick[j + k][i];
            rowcnt[j][i] = now;
        }
    }

    vector<vector<int>> columnclick(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        int t = 0;
        if(columnsum[i] == 0) continue;
        for(int j = n - 1; j >= 0; j--){
            t += a[j][i];
            if(j + k < n) t -= a[j + k][i];
            if(t == columnsum[i]) columnclick[j][i] = 1;
        }
    }

    vector<vector<int>> columncnt(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = n - 1; j >= 0; j--){
            now += columnclick[i][j];
            if(j + k < n) now -= columnclick[i][j + k];
            columncnt[i][j] = now;
        }
    }

    //for(int i = 0; i < n; i++) printv(rowcnt[i], cerr);
    //for(int i = 0; i < n; i++) printv(columncnt[i], cerr);

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(rowsum[i] == 0) ans++;
        if(columnsum[i] == 0) ans++;
    }

    int tans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tans = max(tans, rowcnt[i][j] + columncnt[i][j]);
        }
    }

    cout << ans + tans << "\n";

    return 0;
}