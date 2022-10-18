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

vector<string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int subset(string& a, string& b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '1' && b[i] == '0') return -1;
        if(a[i] == '0' && b[i] == '1') cnt++;
    }
    return cnt;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
    dp[n][0] = true;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l < 10; l++){
                if(j - subset(a[i], num[l]) < 0 || subset(a[i], num[l]) == -1) continue;
                if(dp[i + 1][j - subset(a[i], num[l])]) dp[i][j] = true;
            }
        }
    }

    if(!dp[0][k]){
        cout << "-1\n";
        return 0;
    }

    int now = k;
    string ans(n, ' ');
    for(int i = 0; i < n; i++){
        for(int j = 9; j >= 0; j--){
            if(now - subset(a[i], num[j]) < 0 || subset(a[i], num[j]) == -1) continue;
            if(dp[i + 1][now - subset(a[i], num[j])]){
                ans[i] = '0' + j;
                now -= subset(a[i], num[j]);
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}