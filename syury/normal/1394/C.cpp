//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int inf = (int)1e9;
const int MAXN = (int)3e5 + 6;
const int MAXX = (int)1.2e6 + 6;

template<bool Max>
struct Queue{
    pii L[MAXN], R[MAXN];
    int sL = 0, sR = 0;
    void clear(){
        sL = sR = 0;
    }
    inline int upd(int was, int curr){
        if constexpr(Max) {
            return max(was, curr);
        }
        else {
            return min(was, curr);
        }
    }
    void push(int x){
        int m = sL ? upd(L[sL - 1].Y, x) : x;
        L[sL++] = {x, m};
    }
    void pop(){
        if(!sR){
            for(int i = sL - 1; i >= 0; i--){
                int x = L[i].X;
                int m = sR ? upd(R[sR - 1].Y, x) : x;
                R[sR++] = {x, m};
            }
            sL = 0;
        }
        --sR;
    }
    int get(){
        if(!sL && !sR){
            if constexpr(Max) {
                return -inf;
            } else {
                return inf;
            }
        }
        return !sL ? R[sR - 1].Y : (!sR ? L[sL - 1].Y : upd(R[sR - 1].Y, L[sL - 1].Y));
    }
};

int n;
string s[MAXN];
pii p[MAXN];
vector<int> has[MAXX];
pii last_can;
Queue<false> up, up_d;
Queue<true> down, down_d;

bool can(int d){
    up.clear();
    up_d.clear();
    down.clear();
    down_d.clear();
    int cnt = 0;
    for(int x = -MAXX+1; x < MAXX; x++){
        if(x + d >= 0 && x + d < MAXX && !has[x + d].empty()){
            for(int i: has[x + d]){
                ++cnt;
                down.push(p[i].Y - d);
                up_d.push(p[i].Y - x);
            }
        }
        if(x >= 0 && !has[x].empty()){
            for(int i: has[x]){
                down_d.push(p[i].Y - d - x);
                up.push(p[i].Y + d);
            }
        }
        int L = max(down.get(), down_d.get() + x);
        L = max(L, 0);
        int R = min(up.get(), up_d.get() + x);
        if(x >= 0 && cnt == n && L <= R && L > -inf/2 && R < inf/2){
            if(L < R || (L != 0 || x != 0)){
                last_can = {x, L};
                if(last_can == make_pair(0, 0))
                    ++last_can.Y;
                return true;
            }
        }
        if(x >= 0 && !has[x].empty()){
            for(int i: has[x]){
                down.pop();
                up_d.pop();
            }
        }
        if(x - d >= 0 && !has[x - d].empty()){
            for(int i: has[x - d]){
                --cnt;
                down_d.pop();
                up.pop();
            }
        }
    }
    return false;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int x = 0, y = 0;
        for(char c: s[i])
            if(c == 'B')++x;
            else ++y;
        p[i] = {x, y};
    }
    bool ez = 1;
    for(int i = 1; i < n; i++)
        if(p[i] != p[0])ez = 0;
    if(ez){
        cout << 0 << endl;
        cout << s[0] << endl;
        return;
    }
    for(int i = 0; i < n; i++)
        has[p[i].X].push_back(i);
    int L = 0, R = 2 * MAXN;
    while(R - L > 1){
        int mid = (L + R)/2;
        if(can(mid))
            R = mid;
        else
            L = mid;
    }
    can(R);
    cout << R << endl;
    for(int i = 0; i < last_can.X; i++)
        cout << 'B';
    for(int i = 0; i < last_can.Y; i++)
        cout << 'N';
    cout << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}