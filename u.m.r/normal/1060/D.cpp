#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
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

struct Pt{
    int x, y;
};

int a[MAXN], b[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    int n;
    scanf("%d", &n);
    ll ans = n;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        ans += max(a[i], b[i]);
    /*
    set<PII> X, Y;
    map<int, Pt> mp;
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a[i].x, &a[i].y);
        mp[i] = a[i];
        X.insert(PII(-a[i].x, i));
        Y.insert(PII(-a[i].y, i));
    }
    int m = n;
    ll ans = n;
    for (int i = 1; i < n; i++){
        if (-X.begin()->first >= -Y.begin()->first){
            auto u = X.begin();
            int pos = u->second;
            int x = -u->first;
            int y = mp[pos].y;
            X.erase(u);
            Y.erase(PII(y, pos));
            auto v = Y.begin();
            int p2 = v->second;
            int y2 = -v->first;
            int x2 = mp[p2].x;
            X.erase(PII(x2, p2));
            Y.erase(v);
            ans += max(x, y2);
            m++;
            mp[m] = (Pt){x2, y};
            X.insert(PII(-x2, m));
            Y.insert(PII(-y, m));
        }
        else{
            auto v = Y.begin();
            int pos = v->second;
            int y = -v->first;
            int x = mp[pos].x;
            Y.erase(v);
            X.erase(PII(x, pos));
            auto u = X.begin();
            int p2 = u->second;
            int x2 = -u->first;
            int y2 = mp[p2].y;
            Y.erase(PII(y2, p2));
            X.erase(u);
            ans += max(y, x2);
            m++;
            mp[m] = (Pt){x, y2};
            X.insert(PII(-x, m));
            Y.insert(PII(-y2, m));
        }
    }*/
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}