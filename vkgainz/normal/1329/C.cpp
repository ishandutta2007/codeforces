#include <bits/stdc++.h>
using namespace std;
 
vector<int> a, d, nxt;
int h, g;
 
void f(int i) {
    int left_node_id = 2 * i;
    int right_node_id = 2 * i + 1;
    if(a[left_node_id] == 0 && a[right_node_id] == 0) {
        a[i] = 0;
        nxt[i] = -1;
    }
    else {
        if(a[left_node_id] > a[right_node_id]) {
            a[i] = a[left_node_id];
            f(left_node_id);
        }
        else {
            a[i] = a[right_node_id];
            f(right_node_id);
        }
        if(nxt[left_node_id] == -1 && nxt[right_node_id] == -1)
            nxt[i] = i;
        else if(a[left_node_id] > a[right_node_id])
            nxt[i] = nxt[left_node_id];
        else
            nxt[i] = nxt[right_node_id];
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while(t--) {
        cin >> h >> g;
        a.clear();
        d.clear();
        nxt.clear();
        a.resize(1 << (h + 1));
        d.resize(1 << h);
        nxt.resize(1 << h);
        for(int i = 1; i < (1 << h); i++)
            cin >> a[i];
        for(int i = 1; i < (1 << h); i++) {
            d[i] = d[i / 2] + 1;
        }
        for(int i = (1 << h) - 1; i >= (1 << (h - 1)); i--)
            nxt[i] = i;
        for(int i = (1 << (h - 1)) - 1; i >= 1; i--) {
            if(a[2 * i] > a[2 * i + 1])
                nxt[i] = nxt[2 * i];
            else
                nxt[i] = nxt[2 * i + 1];
        }
        int take = 1;
        vector<int> ret;
        for(int i = 0; i < (1 << h) - (1 << g); i++) {
            if(d[nxt[take]] == g) {
                ++take;
                --i;
                continue;
            }
            ret.push_back(take);
            f(take);
        }
        long long ans = 0LL;
        for(int i = 0; i < (1 << h); i++)
            ans += a[i];
        cout << ans << "\n";
        for(int x : ret) {
            cout << x << " ";
        }
        cout << "\n";
    }
}