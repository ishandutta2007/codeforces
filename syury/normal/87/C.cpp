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

const int N = (int)1e5 + 5;
const int KEK = 400;

int ok[N];
int x[N];
int mm[N];
bitset<KEK> mv;

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ok[0] = ok[1] = 0;
    x[0] = x[1] = 0;
    F(i, 2, N){
        mv.reset();
        int m0 = -1;
        F(k, 2, KEK){
            if(2*i%k != 0)cont;
            int A = 2*i/k;
            A = A + 1 - k;
            if(A <= 0 || A&1)cont;
            A /= 2;
            int num = x[A + k - 1]^x[A - 1];
            mv[num] = 1;
            if(!num && m0 == -1)m0 = k;
        }
        mv = ~mv;
        mm[i] = m0;
        ok[i] = mv._Find_first();
        x[i] = x[i - 1]^ok[i];
    }
    int n;
    cin >> n;
    if(ok[n])cout << mm[n];
    else cout << -1;
    return 0;
}