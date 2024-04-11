#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
const int maxm = 10000005;
int n, a[maxn];
int dv[maxm];
int ans[maxn][2];
void Erastoten() {
    for (int i = 2; i <= maxm; i++) {
        if (dv[i] == 0) {
            dv[i] = i;
            for (ll j = i * 1LL * i; j <= maxm; j += i) {
                if (dv[j] == 0) dv[j] = i;
            }
        }
    }
}
vi divs;
void Factorise(int x) {
    divs.clear();
    while (x > 1) {
        divs.pb(dv[x]);
        x /= dv[x];
    }
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
}
int main() {
    Erastoten();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        Factorise(a[i]);
        if (divs.size() == 1) {
            ans[i][0] = ans[i][1] = -1;
            continue;
        }
        ans[i][0] = divs[0];
        ans[i][1] = 1;
        for (int j = 1; j < divs.size(); j++) {
            ans[i][1] *= divs[j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[j][i]);
        }
        printf("\n");
    }
    return 0;
}