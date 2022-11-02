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

const int N = (int)1e5 + 55;

pii ss[N];
int a[N];
int bnd[N];
int closest[N];
int n;
set<int> pos;
int ans[N];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n)
        cin >> a[i];
    F(i, 0, n){
        ss[i] = mp(a[i], i);
        bnd[i] = a[i]/2;
        if(a[i]%2 == 0)--bnd[i];
    }
    sort(ss, ss + n);
    int ptr = 0;
    F(i, 0, n){
        while(ptr < n && ss[ptr].X <= bnd[ss[i].Y]){
            pos.insert(ss[ptr].Y);
            ++ptr;
        }
        auto it = pos.lower_bound(ss[i].Y);
        if(it != pos.end()){
            closest[ss[i].Y] = *it;
        }
        else{
            if(!pos.empty())
                closest[ss[i].Y] = *pos.begin();
            else closest[ss[i].Y] = -1;
        }
    }
    pos.clear();
    DF(i, n - 1, 0){
        int P = ss[i].Y;
        int big = -1;
        auto it = pos.lower_bound(P);
        if(it != pos.end())
            big = *it;
        else{
            if(!pos.empty())big = *pos.begin();
        }
        int fail = closest[P];
        int df = -1;
        if(fail != -1){df = fail >= P ? fail - P : (n - P + fail);}
        int dn = -1;
        if(big != -1){dn = big >= P ? big - P : (n - P + big);}
        if(fail != -1 && (big == -1 || df < dn)){
            ans[P] = df;
        }
        else{
            if(big == -1 || ans[big] == -1)ans[P] = -1;
            else ans[P] = dn + ans[big];
        }
        pos.insert(P);
    }
    F(i, 0, n)cout << ans[i] << ' ';
    return 0;
}