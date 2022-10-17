#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);         
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> dis;
    queue<int> q;
    for(int i = 0; i < n; ++i) cin >> a[i], dis[a[i]] = 0, q.push(a[i]);
    vector<int> ans;
    ll tot = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(dis[cur]) {
            ans.push_back(cur);
            tot += dis[cur];
            --m;
        }
        if(!m) break;
        if(!dis.count(cur - 1)) dis[cur - 1] = dis[cur] + 1, q.push(cur - 1);
        if(!dis.count(cur + 1)) dis[cur + 1] = dis[cur] + 1, q.push(cur + 1);
    }
    cout << tot << endl;
    for(int i : ans) cout << i << " "; cout << endl;
}