#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
vector<int> adj[MX], rev[MX];
int mnIn[MX];
int mnOut[MX];
bool visited[MX], recStack[MX];
bool cyclic(int v) {
    if(!visited[v]) {
        visited[v] = 1, recStack[v] = 1;
        for(int next : adj[v]) {
            if(!visited[next] && cyclic(next)) return 1;
            else if(recStack[next]) return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}
bool cycle(int n) {
    for(int i=0;i<n;i++)
        if(cyclic(i)) return 1;
    return 0;
}
int main() {
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        mnIn[i] = 1000000000;
        mnOut[i] = 1000000000;
    }
    for(int i=0;i<n;i++) {
        if(mnIn[i]==1000000000) {
            queue<int> q;
            q.push(i);
            mnIn[i] = i;
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(int next : adj[x]) {
                    if(mnIn[x]<mnIn[next]) {
                        mnIn[next] = mnIn[x];
                        q.push(next);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(mnOut[i]==1000000000) {
            queue<int> q;
            q.push(i);
            mnOut[i] = i;
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(int next : rev[x]) {
                    if(mnOut[x]<mnOut[next]) {
                        mnOut[next] = mnOut[x];
                        q.push(next);
                    }
                }
            }
        }
    }
    bool work = cycle(n);
    if(work) cout << -1 << endl;
    else {
        int cnt = 0;
        string ans = "";
        for(int i=0;i<n;i++) {
            if(i==mnIn[i] && i==mnOut[i]) {
                ans+='A';
                ++cnt;
            }
            else ans+='E';
        }
        cout << cnt << endl;
        cout << ans << endl;
    }
}