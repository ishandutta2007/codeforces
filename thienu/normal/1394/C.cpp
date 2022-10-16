#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int INF = 1e9 + 5;

// d = y-x

bool outside(int cornerx, int cornery, int c, int minx, int maxx, int miny, int maxy, int mind, int maxd){
    return cornerx <= minx && cornery <= miny && cornery + c - cornerx >= maxd && cornery - c - cornerx <= mind
              && cornerx + 2 * c >= maxx && cornery + 2 * c >= maxy;
}

int binsearch(int x, int y, int xmul, int ymul, int minx, int maxx, int miny, int maxy, int mind, int maxd){
    int left = 0, right = 1e7;
    while(left < right){
        int mid = left + (right - left) / 2;
        // debug(left, right, mid);
        int cornerx = x + xmul * mid, cornery = y + ymul * mid;
        if(outside(cornerx, cornery, mid, minx, maxx, miny, maxy, mind, maxd)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if(left == 12){
        debug(x, y, xmul, ymul, x + xmul * left, y + ymul * left);
    }
    return left;
}

void solve(){
    int n;
    cin >> n;
    int minx = INF, maxx = -INF, miny = INF, maxy = -INF, mind = INF, maxd = -INF;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int b = 0, n = 0;
        for(char c : s){
            if(c == 'B') b++;
            else n++;
        }
        debug(b, n);
        minx = min(minx, b);
        maxx = max(maxx, b);
        miny = min(miny, n);
        maxy = max(maxy, n);
        mind = min(mind, n-b);
        maxd = max(maxd, n-b);
    }
    debug(minx, maxx, miny, maxy, mind, maxd);

    int ans = INF;
    int x, y;
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(minx, miny + i, 0, 0, minx, maxx, miny, maxy, mind, maxd);
        if(a < ans){
            ans = a;
            x = minx;
            y = miny + i;
        }
    }
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(minx + i, maxd + minx + i, 0, -1, minx, maxx, miny, maxy, mind, maxd);
        if(a < ans){
            ans = a;
            x = minx + i;
            y = maxd + minx + i - ans;
        }
    }
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(maxx + i, maxy, -1, -2, minx, maxx, miny, maxy, mind, maxd);
        ans = min(ans, a);
        if(a < ans){
            ans = a;
            x = maxx + i - ans;
            y = maxy - 2 * ans;
        }
    }
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(maxx, maxy + i, -2, -2, minx, maxx, miny, maxy, mind, maxd);
        if(a < ans){
            ans = a;
            x = maxx - 2 * ans;
            y = maxy + i - 2 * ans;
        }
    }
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(maxx + i, mind + maxx + i, -2, -1, minx, maxx, miny, maxy, mind, maxd);
        ans = min(ans, a);
        if(a < ans){
            ans = a;
            x = maxx + i - 2 * ans;
            y = mind + maxx + i - ans;
        }
    }
    for(int i = -2e5; i <= 2e5; i++){
        int a = binsearch(minx + i, miny, -1, 0, minx, maxx, miny, maxy, mind, maxd);
        if(a < ans){
            ans = a;
            x = minx + i - ans;
            y = miny;
        }
    }

    debug(ans, x, y);

    cout << ans << endl;

    string out = "";
    for(int i = 0; i < ans+x; i++) out += 'B';
    for(int i = 0; i < ans+y; i++) out += 'N';

    cout << out << endl;

    // int a = binsearch(minx, miny, 0, 0, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);
    // a = binsearch(minx, maxd + minx, 0, -1, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);
    //  a = binsearch(-maxd + maxy, maxy, -1, -2, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);
    //  a = binsearch(maxx, maxy, -2, -2, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);
    //  a = binsearch(maxx, mind + maxx, -2, -1, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);
    //  a = binsearch(-mind + miny, miny, -1, 0, minx, maxx, miny, maxy, mind, maxd);
    // debug(a);

    // int num_b = minb + (maxb-minb+1) / 2;
    // int num_n = minn + (maxn-minn+1) / 2;
    
    // debug(num_b, num_n);

    // cout << max((maxb-minb+1)/2, (maxn-minn+1)/2) << endl;

    // for(int i = 0; i < num_b; i++) cout << 'B';
    // for(int i = 0; i < num_n; i++) cout << 'N';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}