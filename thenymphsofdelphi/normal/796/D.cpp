#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
 
#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 3e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, k, d;
queue <ii > q;
vii way[N];
int v[N], res[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++){
        int p;
        cin >> p;
        q.push(mp(p, 0));
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        way[u].pb(mp(v, i));
        way[v].pb(mp(u, i));
    }
    while (!q.empty()){
        int pos = q.front().fi, from = q.front().se;
        q.pop();
        if (v[pos]){
            continue;
        }
        v[pos] = 1;
        for (int i = 0; i < way[pos].size(); i++){
            if (way[pos][i].fi != from){
                if (v[way[pos][i].fi]){
                    res[way[pos][i].se] = 1;
                }
                else{
                    q.push(mp(way[pos][i].fi, pos));
                }
            }
        }
    }
    int rescnt = 0;
    for (int i = 1; i < n; i++){
        if (res[i]){
            rescnt++;
        }
    }
    cout << rescnt << endl;
    for (int i = 1; i < n; i++){
        if (res[i]){
            cout << i << ' ';
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |
6 3 2
1 5 6
1 2
1 3
1 4
1 5
5 6
------------------------------    |
6 2 4
1 6
1 2
2 3
3 4
4 5
5 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
4 5
------------------------------    |
1
5
------------------------------    |
==================================+
*/