//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
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
typedef double dbl;
typedef pair<int, int> pii;

const int N = 2222;

int d[N][4];
int a[N][N];
int n;
int ans = 0;

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n){
        string s;
        cin >> s;
        F(j, 0, n)
            a[i][j] = s[j] - '0';
    }
    DF(i, n - 1, 0){
        F(j, 0, i){
            int pixel = d[i][3]^d[j][2];
            if(pixel != a[i][j]){
                ++ans;
                d[i][3] ^= 1;
                d[j][2] ^= 1;
            }
        }
    }
    F(i, 0, n){
        DF(j, n - 1, i + 1){
            int pixel = d[i][1]^d[j][0];
            if(pixel != a[i][j]){
                ++ans;
                d[i][1] ^= 1;
                d[j][0] ^= 1;
            }
        }
    }
    F(i, 0, n){
        int pixel = d[i][1]^d[i][3]^d[i][0]^d[i][2];
        if(pixel != a[i][i])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}