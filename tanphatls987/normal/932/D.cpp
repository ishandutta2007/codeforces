#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4e5 + 10;
const ll linf = 1e17;


int n;


int pa[N][20];


ll maxW[N][20];
ll w[N];
ll tr[N][20];
ll wr[N][20];

void addNode(int x, ll wei) {
    //cout << "add" << x << " " << wei << '\n';
    ++n;
    w[n] = wei;
    //ll bar = w[n] * (1000000) + n;
    

    //cout << n << "u" << bar << '\n'; 

    pa[n][0] = x;
    for(int i = 1; i < 20; i++) 
        pa[n][i] = pa[pa[n][i - 1]][i - 1];
    maxW[n][0] = w[n];
    for(int i = 1; i < 20; i++) 
        maxW[n][i] = max(maxW[n][i - 1], maxW[pa[n][i - 1]][i - 1]);

    
    int trZero = n;
    for(int i = 19; i >= 0; i--) {
        if (maxW[pa[trZero][0]][i] < w[n])
            trZero = pa[trZero][i];
    }
    tr[n][0] = pa[trZero][0];
    wr[n][0] = w[n];
    //cout << n << "->" << tr[n][0] << '\n';
    assert(tr[n][0] == 0 || w[tr[n][0]] >= w[n]);
    for(int i = 1; i < 20; i++) {
        tr[n][i] = tr[tr[n][i - 1]][i - 1];
        wr[n][i] = min(wr[n][i - 1] + wr[tr[n][i - 1]][i - 1], linf);
    }
}
ll solve(ll x, ll cap) {
    ll ans = 0;
    for(int i = 19; i >= 0; i--) {
        if (wr[x][i] <= cap) {
            ans += 1LL << i;
            cap -= wr[x][i];
            x = tr[x][i];
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(maxW[0], maxW[0] + 20, linf);
    fill(wr[0], wr[0] + 20, linf);
    n = 0;
    addNode(0, 0);


    int test;
    cin >> test;



    ll res = 0;
    while (test--) {
        ll type, p, q;
        cin >> type >> p >> q; 
        if (type == 1) {
            addNode(p ^ res, q ^ res);
        } else cout << (res = solve(p ^ res, q ^ res)) << '\n';

    }
}