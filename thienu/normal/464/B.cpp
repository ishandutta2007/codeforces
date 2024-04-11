#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int SIX_TO_POWER_EIGHT = 1679616;
ll INF = 2e18 + 4;

struct P{
    int x, y, z;
    P(){}
    P(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }

    bool operator == (const P &o){
        return o.x == x && o.y == y && o.z == z;
    }
    
    P operator + (const P &o){
        return P(x + o.x, y + o.y, z + o.z);
    }

    P operator - (const P &o){
        return P(x - o.x, y - o.y, z - o.z);
    }

    P operator - (){
        return P(-x, -y, -z);
    }

    P rotate(int a){
        switch(a){
            case 0:
                return P(x, y, z);
            case 1:
                return P(x, z, y);
            case 2:
                return P(y, x, z);
            case 3:
                return P(y, z, x);
            case 4:
                return P(z, x, y);
            case 5:
                return P(z, y, x);
        }
    }

    ll square_length(){
        return (ll) x * x + (ll) y * y + (ll) z * z;
    }

    ll operator * (const P &o){
        return (ll) x * o.x + (ll) y * o.y + (ll) z * o.z;
    }
};


void solve(){
    vector<P> points;
    for(int i = 0; i < 8; i++){
        int x, y, z;
        cin >> x >> y >> z;
        points.push_back(P(x, y, z));
    }

    for(int mask = 0; mask < SIX_TO_POWER_EIGHT; mask++){
        vector<P> np;
        int m = mask;
        for(int i = 0; i < 8; i++){
            np.push_back(points[i].rotate(m % 6));
            m /= 6;
        }
        for(int i = 0; i < 8; i++){
            ll md = INF;
            int mc = 0;
            vi min_idx;
            for(int j = 0; j < 8; j++){
                if(i == j) continue;
                ll sd = (np[i] - np[j]).square_length();
                if(sd == md){
                    mc++;
                    min_idx.push_back(j);
                }
                else if(sd < md){
                    md = sd;
                    mc = 1;
                    min_idx.clear();
                    min_idx.push_back(j);
                }
            }
            // debug(md, mc);
            if(mc != 3 || md == 0) goto next_mask;
            P a = np[i] - np[min_idx[1]];
            P b = np[i] - np[min_idx[0]];
            P c = np[i] - np[min_idx[2]];
            // debug(a.x, a.y, a.z);
            // debug(b.x, b.y, b.z);
            // debug(c.x, c.y, c.z);
            // debug(a * b, b * c, c * a);
            if(a * b != 0 || b * c != 0 || c * a != 0) goto next_mask;
        }
        cout << "YES" << endl;
        for(int i = 0; i < 8; i++){
            cout << np[i].x << " " << np[i].y << " " << np[i].z << endl;
        }
        return;
        next_mask:
        ;
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}