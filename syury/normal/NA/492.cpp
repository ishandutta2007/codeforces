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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> id;
    vector<int> a(n);
    F(i, 0, n){
        int x;
        cin >> x;
        id[x] = i;
    }
    F(i, 0, n){
        int x;
        cin >> x;
        a[i] = id[x];
    }
    int ans = 0;
    int mi = (int)1e9;
    DF(i, n - 1, 0){
        if(mi < a[i])++ans;
        mi = min(mi, a[i]);
    }
    cout << ans << endl;
    return 0;
}