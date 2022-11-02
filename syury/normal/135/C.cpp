//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

string s;
int n;

bool can(int a, int b, int c, int diff){
    int delta = abs(a - b);
    c -= delta;
    if(c < 0 || c&1)ret 0;
    ret 1;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int cnt[3] = {0, 0, 0};
    F(i, 0, n){
        if(s[i] == '?')++cnt[2];
        else ++cnt[s[i] - '0'];
    }
    bool ok[4] = {0, 0, 0, 0};
    if(n&1){
        if(cnt[2] + cnt[1] > cnt[0] + 1)ok[3] = 1;
        if(cnt[2] + cnt[0] > cnt[1])ok[0] = 1;
        if(s.back() == '?'){
            if(can(cnt[0] + 1, cnt[1] + 1, cnt[2] - 1, 0))ok[1] = 1;
            if(can(cnt[0] + 2, cnt[1], cnt[2] - 1, 0))ok[2] = 1;
        }
        else{
            if(s.back() == '1'){
                if(can(cnt[0] + 1, cnt[1], cnt[2], 0))ok[1] = 1;
            }
            else
                if(can(cnt[0] + 1, cnt[1], cnt[2], 0))ok[2] = 1;
        }
    }
    else{
        if(cnt[2] + cnt[1] > cnt[0])ok[3] = 1;
        if(cnt[2] + cnt[0] > cnt[1])ok[0] = 1;
        if(s.back() == '?'){
            if(can(cnt[0], cnt[1] + 1, cnt[2] - 1, 0))ok[1] = 1;
            if(can(cnt[0] + 1, cnt[1], cnt[2] - 1, 0))ok[2] = 1;
        }
        else{
            if(s.back() == '1'){
                if(can(cnt[0], cnt[1], cnt[2], 0))ok[1] = 1;
            }
            else
                if(can(cnt[0], cnt[1], cnt[2], 0))ok[2] = 1;
        }
    }
    F(i, 0, 4)
        if(ok[i])cout << i/2 << i%2 << endl;
    return 0;
}