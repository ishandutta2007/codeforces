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

const ll mod = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    F(i, 0, n)cin >> p[i];
    ll sum = 0;
    F(i, 0, k){
        sum += n - i;
    }
    cout << sum << ' ';
    ll cnt = 1;
    int prv_pos = -1;
    F(i, 0, n){
        if(p[i] < n - k + 1)cont;
        if(prv_pos != -1)cnt = cnt * (i - prv_pos) % mod;
        prv_pos = i;
    }
    cout << cnt << endl;
    return 0;
}