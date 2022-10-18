#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 3e2 + 5;

int query(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int ans; cin >> ans;
    if (ans < 0){
        exit(0);
    }
    return ans;
}

int cur;

int n, all;
int p[N], ans[N];

int which_flip(int l, int r){
    assert(r % 2 != (n - l + 1) % 2);
    int tcur = query(l, r);
    if (abs(tcur - cur) % 2 == r % 2){
        cur = tcur;
        return 0;
    }
    else{
        cur = tcur;
        return 1;
    }
}

void until_flip(int l, int r, int side = 0){
    assert(r % 2 != (n - l + 1) % 2);
    int cnt[2] = {0, 0};
    while (cnt[side] != 1 or cnt[side ^ 1] != 0){
        cnt[which_flip(l, r)] ^= 1;
    }
}

void answer(){
    cout << "! ";
    ForE(i, 1, n){
        cout << ans[i];
    }
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> cur; all = cur;
    if (n == 1){
        ans[1] = cur;
        answer();
    }
    if (n % 2 == 1){
        ForE(i, 2, n){
            until_flip(i - 1, i);
            p[i] = (i - cur + all) / 2;
            until_flip(i - 1, i);
        }
        until_flip(2, n, 0);
        until_flip(2, n, 1);
        p[1] = (1 - cur + all) / 2;
        ForE(i, 1, n){
            ans[i] = p[i] - p[i - 1];
        }
    }
    else{
        ForE(i, 1, n){
            until_flip(i, i);
            p[i] = (i - cur + all) / 2;
            until_flip(i, i);
        }
        ForE(i, 1, n){
            ans[i] = p[i] - p[i - 1];
        }
    }
    answer();
}