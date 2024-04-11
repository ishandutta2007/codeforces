#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 300005 * 25;
int tr[maxn][2], sz[maxn], vis[maxn], tot = 0;
void insert(int x) {
    if(vis[x]) return;
    vis[x]=1;
    int p=0;
    for(int i=25;i>=0;--i) {
        if(!tr[p][x>>i&1]) tr[p][x>>i&1]=++tot;
        p=tr[p][x>>i&1];
        sz[p]++;
    }
}
int query(int x) {
    int ans=0,y=1<<25,p=0;
    for(int i=25;i>=0;--i) {
        if(sz[tr[p][x>>i&1]] == y) {
            p = tr[p][(x>>i&1)^1];
            ans |= 1<<i;
        } else {
            p = tr[p][x>>i&1];
        }
        if(!p) break;
        y>>=1;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insert(x);
    }
    int x = 0;
    while(m--) {
        int tmp;
        cin >> tmp;
        x ^= tmp;
        cout << query(x) << endl;
    }
}