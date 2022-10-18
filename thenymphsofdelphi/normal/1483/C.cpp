#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 3e5 + 5, M = 19;

int n;
int a[N], b[N];

stack <pair <int, ll>> st;
multiset <ll> mtsdp;
ll dp[M][N];

ll caldp(int l, int r){
    int z = __builtin_clz(r - l + 1) ^ 31;
    return max(dp[z][l + (1 << z) - 1], dp[z][r]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    
    st.push(make_pair(0, 0ll));
    ForE(i, 1, n){
        while (a[st.top().fi] >= a[i]){
            mtsdp.erase(mtsdp.find(st.top().se));
            st.pop();
        }
        ll tmp = b[i] + caldp(st.top().fi, i - 1);
        mtsdp.insert(tmp);
        st.push(make_pair(i, tmp));
        dp[0][i] = (*(--mtsdp.end()));
        For(j, 1, M){
            if (i >= (1 << j) - 1){
                dp[j][i] = max(dp[j - 1][i - (1 << (j - 1))], dp[j - 1][i]);
            }
            else{
                break;
            }
        }
    }
    cout << dp[0][n] << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/