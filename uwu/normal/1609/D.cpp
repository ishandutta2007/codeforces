#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e3 + 1;

int p[MN], sz[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
int Union(int a, int b){
    a = Find(a); b = Find(b);
    if (a == b) return 0;
    if (sz[b] > sz[a]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, D; cin >> N >> D;
    for (int i = 1; i <= N; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    int k = 1;
    for (int i = 1; i <= D; ++i){
        int a, b; cin >> a >> b;
        if (!Union(a, b)) k++;
        vector<int> v;
        for (int j = 1; j <= N; ++j){
            if (p[j] == j) v.push_back(sz[j]); 
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int j = 0; j < min(k, (int)v.size()); ++j){
            ans += v[j];
        }
        cout << ans - 1 << '\n';
    }
}