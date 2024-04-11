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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

int n;
int a[N], b[N];
int basis[100];
int sz = 0;

inline void add(int v){
    int i;
    for(i = 0; i < sz; i++){
        if(!v)
            break;
        int l = __builtin_clz(basis[i]), r = __builtin_clz(v);
        if(l > r){
            break;
        }
        if(l == r)
            v ^= basis[i];
    }
    if(v){
        for(int j = sz; j > i; j--){
            basis[j] = basis[j - 1];
        }
        basis[i] = v;
        ++sz;
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    int curr = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        b[i] = curr ^= a[i];
    }
    if(!b[n - 1]){
        printf("-1");
        return 0;
    }
    for(int i = n - 1; i >= 0; i--)
        add(b[i]);
    printf("%d", sz);
    return 0;
}