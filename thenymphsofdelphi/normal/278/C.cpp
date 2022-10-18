#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

const int N = 100 + 5;

int n, m, edge = 0, cc = 0;
vector <int> a[N], b[N];
bool cka[N], ckb[N];

void dfs(int u, int s){
    if (s == 0){
        if (cka[u]){
            return;
        }
        cka[u] = 1;
        for (int i = 0; i < a[u].size(); i++){
            if (!ckb[a[u][i]]){
                dfs(a[u][i], 1);
            }
        }
        return;
    }
    else{
        if (ckb[u]){
            return;
        }
        ckb[u] = 1;
        for (int i = 0; i < b[u].size(); i++){
            if (!cka[b[u][i]]){
                dfs(b[u][i], 0);
            }
        }
        return;
    }
}

int main(){
    cin >> n >> m;
    int l, x;
    for (int i = 0; i < n; i++){
        cin >> l;
        edge += l;
        for (int j = 0; j < l; j++){
            cin >> x;
            x--;
            a[i].pb(x);
            b[x].pb(i);
        }
    }
    if (edge == 0){
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (!cka[i]){
            dfs(i, 0);
            cc++;
        }
    }
    cout << cc - 1;
}