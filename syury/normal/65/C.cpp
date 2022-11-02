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
    int x, y, z;
    int dist(const pt & p)const{
        return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y) + (z - p.z)*(z - p.z);
    }
};

const int N = (int)1e4 + 4;
const dbl eps = 1e-12;

pt p;
pt a[N];
int v1, v2;
int n;

dbl sqr(dbl x){ret x * x;}

dbl get(int dist, int v){
    ret sqrt((dbl)dist)/dbl(v);
}

dbl solve(dbl T, int i){
    dbl tot = get(a[i].dist(a[i - 1]), v2);
    dbl l = 0, r = tot;
    F(step, 0, 300){
        dbl mid = (l + r)/2;
        dbl t1 = T + mid;
        dbl t2 = sqr(p.x - a[i - 1].x - (a[i].x - a[i - 1].x)*(mid/tot)) + sqr(p.y - a[i - 1].y - (a[i].y - a[i - 1].y)*(mid/tot)) + sqr(p.z - a[i - 1].z - (a[i].z - a[i - 1].z)*(mid/tot));
        t2 = sqrt(t2)/v1;
        if(t2 < t1 + eps)
            r = mid;
        else
            l = mid;
    }
    ret T + (l + r)/2;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ++n;
    F(i, 0, n){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    cin >> v1 >> v2;
    cin >> p.x >> p.y >> p.z;
    dbl T = 0;
    F(i, 1, n){
        int kek = a[i].dist(a[i - 1]);
        dbl pass = get(kek, v2);
        dbl cT = T + pass;
        dbl fst = get(p.dist(a[i]), v1);
        if(fst > cT + eps){
            T = cT;
            cont;
        }
        dbl ans = solve(T, i);
        cout << "YES\n";
        cout.precision(16);
        cout << fixed << ans << endl;
        dbl extra = ans - T;
        cout << fixed << a[i - 1].x + (a[i].x - a[i - 1].x)*(extra/pass) << ' ';
        cout << fixed << a[i - 1].y + (a[i].y - a[i - 1].y)*(extra/pass) << ' ';
        cout << fixed << a[i - 1].z + (a[i].z - a[i - 1].z)*(extra/pass) << endl;
        ret 0;
    }
    cout << "NO";
    return 0;
}