//https://codeforces.com/problemset/problem/1045/D?csrf_token=65eb1b202d9f7d46b7a1ce68b2e086e5
/*
* Author : MaxSally
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
const int N = 100005;
double sumEdge[N], node[N], iniNode[N];
unordered_set<int> edge[N], toUpdate;
double res = 0.0;
int n;
 
void input_prepare(){
    cin >> n;
    rep(i, 0, n - 1){
        double x; cin >> x;
        node[i] = 1.0 - x;
        res += node[i];
        iniNode[i] = node[i];
    }
    //debuga1(node, 0, n - 1);
    rep(i, 1, n - 1){
        int x, y; cin >> x >> y;
        edge[x].insert(y);
        edge[y].insert(x);
        sumEdge[x] += node[y];
        sumEdge[y] += node[x];
    }
    rep(i, 0, n - 1){
        res -= (sumEdge[i] * node[i])/2;
    }
}
 
int main(){
    io;
    //freopen("input.txt", "r", stdin);
    unordered_set<int>::iterator it;
    input_prepare();
    int q; cin >> q;
    while(q--){
        int v; double val; cin >> v >> val;
        val = 1.0 - val;
        double delta = val - node[v];
        node[v] = val;
        toUpdate.insert(v);
        if((int)toUpdate.size() >= 90){
            for(auto a: toUpdate){
                for(auto b: edge[a]){
                    sumEdge[b] = sumEdge[b] - iniNode[a] + node[a];
                }
                iniNode[a] = node[a];
            }
            toUpdate.clear();
        }
        double temp = sumEdge[v];
        //debug(temp);
        for(int a : toUpdate){
            if(edge[v].find(a) != edge[v].end()){
                //debug(a);
                temp = temp + (- iniNode[a] + node[a]);
            }
        }
        //debug(temp);
        res = res + delta - temp * delta;
        cout << fixed << setprecision(9) << res << '\n';
    }
    return 0;
}