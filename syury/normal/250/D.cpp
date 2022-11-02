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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct pt{
    ll x, y;
    dbl dist(const pt & p)const{
        return sqrt(dbl((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y)));
    }
};

const int N = (int)1e5 + 5;

int n, m, a, b;
pt A[N], B[N];
int l[N];
dbl d1[N];

dbl f(pt p, int i){
    ret d1[i] + p.dist(A[i]);
}

int solve(pt p){
    int l = 0, r = n - 1;
    while(r - l + 1 > 5){
        int m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
        if(f(p, m1) < f(p, m2))
            r = m2;
        else
            l = m1;
    }
    int out;
    dbl res = 1e18;
    E(i, l, r){
        dbl cu = f(p, i);
        if(cu < res){
            res = cu;
            out = i;
        }
    }
    ret out;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    F(i, 0, n){
        int y;
        cin >> y;
        A[i] = {a, y};
        d1[i] = pt{0, 0}.dist(A[i]);
    }
    F(i, 0, m){
        int y;
        cin >> y;
        B[i] = {b, y};
    }
    F(i, 0, m)
        cin >> l[i];
    dbl ans = 1e18;
    int a1, a2;
    F(i, 0, m){
        int j = solve(B[i]);
        dbl curr = l[i] + f(B[i], j);
        if(curr < ans){
            ans = curr;
            a1 = j + 1;
            a2 = i + 1;
        }
    }
    cout << a1 << ' ' << a2 << endl;
    return 0;
}