#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 10;

set<long long> rem[2][40];
vector<long long> imp[2][40];

typedef pair<int,int> ii;

#define X first
#define Y second

struct addr{
    int sign;
    long long val;
    int lv;
    addr(){};
    addr(int sign, long long val, int lv)
        :sign(sign), val(val), lv(lv){};
};
addr strip(string s){
    int sign = (s[0] == '-') ? 1 : 0;
    int layer = 32;
    int en = 0;
    while (en < s.length() && s[en] != '/') en++;
    if (en != s.length()){
        layer = 0;
        for(int i = en + 1; i < s.length(); i++){
            layer = 10 * layer + s[i] - '0';
        }
    }
    long long ans = 0;
    for(int i = 3, pos = 1; i >= 0; i--, pos++){
        long long cur = 0;
        while (s[pos] >= '0' && s[pos] <= '9') {
            cur = cur * 10 + s[pos] - '0';
            pos++;
        }
        ans += cur << (i * 8);
    }
    return addr(sign, ans, layer);
}
string to_string(addr s){
    int a = (s.val >> 24) & ((1LL << 8) - 1); 
    int b = (s.val >> 16) & ((1LL << 8) - 1); 
    int c = (s.val >> 8) & ((1LL << 8) - 1); 
    int d = (s.val >> 0) & ((1LL << 8) - 1); 
    return to_string(a) + '.' + to_string(b) + '.' + to_string(c) + '.' + 
        to_string(d) + '/' + to_string(s.lv);
}
int n;

addr a[N];
ii ra[35][N];

int f[N], psum[N];
ii tr[N];
bool pushin(int type, int lv, long long val){
    long long lastbit = (val >> (32 - lv)) & 1;
    for(int i = lv; i >= 0; i--){
        long long mask = ((1LL << 32) - 1) ^ ((1LL << (32 - i)) - 1);
        long long parval = val & mask;
        if (rem[type ^ 1][i].count(parval)) return 0;    
        if (rem[type][i].count(parval)) return 1;    
    }
    if (lv > 0) {
        long long othval = val ^ (1LL << (32 - lv));
        if (rem[type][lv].count(othval)){
            rem[type][lv].erase(othval);
            long long nval = val & othval;
            return pushin(type, lv - 1, nval);
        }
    }
    rem[type][lv].insert(val);
    return 1;
}

void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[i] = strip(s);
    }
    for(int i = 1; i <= n; i++)
        imp[a[i].sign][a[i].lv].push_back(a[i].val);
    for(int i = 0; i <= 32; i++){
        for(int j = 0; j <= 1; j++)
            for(auto k : imp[j][i])
                if (!pushin(j, i, k)){
                    cout << "-1";
                    exit(0);
                }
    }
    n = 0;
    for(int i = 0; i <= 32; i++)
        for(int j = 0; j <= 1; j++){
            for(auto k: rem[j][i]) a[++n] = addr(j, k, i);
        }
    //cout << n << '\n';
    //for(int i = 1; i <= n; i++) cout << to_string(a[i]) << '\n';
    sort(a + 1, a + n + 1, [](addr a, addr b) {return a.val < b.val;});
}
bool minimize(int &x, int y){
    if (x > y) x = y; else return 0;
    return 1;
}
void solve(){
    for(int i = 1; i <= n; i++) 
        psum[i] = psum[i - 1] + (a[i].sign == 0);
    for(int lv = 32; lv >= 0; lv--){
        ra[lv][0] = ii(1, 0);
        for(int i = 1; i <= n; i++){
            long long mask = ((1LL << 32) - 1) ^ ((1LL << (32 - lv)) - 1);
            long long parL = a[i].val & mask;
            long long parR = parL + (1LL << (32 - lv));
            ra[lv][i] = ra[lv][i - 1];
            while (a[ra[lv][i].X].val < parL) ra[lv][i].X++;
            while (ra[lv][i].Y < n && a[ra[lv][i].Y + 1].val < parR) ra[lv][i].Y++;
        }
    }
    fill(f + 1, f + n + 1, n + 1);
    for(int i = 1; i <= n; i++){
        if (a[i].sign == 0){
            f[i] = f[i - 1];
            tr[i] = ii(i - 1, -1);
            continue;
        }
        for(int j = a[i].lv; j >= 0; j--){
            if (psum[ra[j][i].Y] - psum[ra[j][i].X - 1]) continue;
            if (minimize(f[i], f[ra[j][i].X - 1] + 1)){
                tr[i] = ii(ra[j][i].X - 1, j);
            }
        }
    }
    cout << f[n] << '\n';
    for(int i = 1, cur = n; i <= f[n]; i++){
        if (a[cur].sign == 0){
            cur--;
            i--;
            continue;
        }
        long long mask = ((1LL << 32) - 1) ^ ((1LL << (32 - tr[cur].Y)) - 1);
        cout << to_string(addr(0,a[cur].val & mask, tr[cur].Y)) << '\n';
        cur = tr[cur].X;
    }
}
int main() {
    prepare();
    solve();
}