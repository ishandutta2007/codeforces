#include <algorithm>
#include <stack>
#include <istream>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <ostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;

using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;



int N, M;

string G[1000];
vector<vector<bool>> vis;
void solve() {
    cin >> N >> M;
    vis.assign(N, vector<bool> (M));

    for(int i = 0; i < N; i++)
        cin >> G[i];


    auto check = [&](int x, int y) -> bool
    {
        return x-2>=0&&y-2>=0&&G[x][y]!='.'&&G[x-1][y]!='.'&&G[x-2][y]!='.'&&G[x-2][y-1]!='.'&&G[x][y-1]!='.'&&G[x][y-2]!='.'&&G[x-1][y-2]!='.'&&G[x-2][y-2]!='.';
    };
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j] && G[i][j] == '#') {
                if(check(i, j)) {
                    vis[i][j]=true;
                    vis[i-1][j]=true;
                    vis[i-2][j]=true;
                    vis[i-2][j-1]=true;
                    vis[i][j-1]=true;
                    vis[i][j-2]=true;
                    vis[i-1][j-2]=true;
                    vis[i-2][j-2]=true;
                }
            }
        }
    }


    bool works = true;


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j] && G[i][j] == '#') {
                works = false;
            }
            else if(vis[i][j] && G[i][j] == '.') {
                works = false;
            }
        }
    }

    cout << (works ? "YES\n" : "NO\n");
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T = 1;
    while(T--)
        solve();
}