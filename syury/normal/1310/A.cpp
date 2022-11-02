//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
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

const int N = (int)2e5 + 5;

pii a[N];
int n;

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n){
        cin >> a[i].X;
    }
    F(i, 0, n)cin >> a[i].Y;
    sort(a, a + n);
    int ptr = 0;
    set<pii, greater<pii> > biggest;
    ll ans = 0;
    ll sum = 0;
    int curr = 0;
    F(i, 0, n){
        if(!biggest.empty()){
            ++curr;
        }
        else{
            curr = a[ptr].X;
            biggest.insert(mp(a[ptr].Y, ptr));
            sum = a[ptr].Y;
            ++ptr;
        }
        while(ptr < n && a[ptr].X == curr){
            sum += a[ptr].Y;
            biggest.insert(mp(a[ptr].Y, ptr));
            ++ptr;
        }
        ans += sum - biggest.begin()->X;
        sum -= biggest.begin()->X;
        biggest.erase(biggest.begin());
    }
    cout << ans << endl;
    return 0;
}