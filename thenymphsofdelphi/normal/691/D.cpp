#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m;
int a[N], par[N], idx[N];
vector <int> ck[N];

int find(int x){
    return (par[x] < 0 ? x : (par[x] = find(par[x])));
}

void merge(int x, int y){
    if ((x = find(x)) == (y = find(y))) return;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        par[i] = -1;
    }
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= n; i++){
        ck[find(i)].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++){
        sort(ck[i].rbegin(), ck[i].rend());
    }
    for (int i = 1; i <= n; i++){
        cout << ck[find(i)][idx[find(i)]] << ' ';
        idx[find(i)]++;
    }
}