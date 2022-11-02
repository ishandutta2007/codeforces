#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n;
vector<ll> ans;

ll gao(ll x) {
    ll y = n / x;
    ll ret = x;
    ret = ret + (x - 1) * x / 2 * y;
    return ret;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    int i = 1;
    for (; i * i < n; i++) 
        if (n % i == 0){
            ans.push_back(gao(i));
            ans.push_back(gao(n / i));
        }
    if (i * i == n) 
        ans.push_back(gao(i));
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (int i = 0; i < ans.size(); i++)
        printf("%lld%c", ans[i], " \n"[i + 1 == ans.size()]);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}