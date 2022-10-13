#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
const int N = 1000001;
using namespace std;
vector<int> adj[300001];
vector<int> in;
bool visited[300001];
void dfs(int i) {
    in.push_back(i);
    visited[i] = true;
    for(int next : adj[i]) {
        if(!visited[next]) dfs(next);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int numC = 0;
        int numM = 0;
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<n;i++) visited[i] = false;
        for(int i=0;i<n;i++) {
            if(s[i]=='-') ++numM;
            else if(s[i]=='>') ++numC;
        }
        if(numM+numC==n || numM+(n-numM-numC)==n) {
            cout << n << endl;
        }
        else {
            for(int i=0;i<n;i++) {
                if(s[i]=='-') adj[i].push_back((i+1)%n), adj[(i+1)%n].push_back(i);
            }
            int ans = 0;
            for(int i=0;i<n;i++) {
                if(!visited[i] && adj[i].size()>0) {
                    in.clear();
                    dfs(i);
                    ans+=in.size();
                }
            }
            cout << ans << endl;
        }
    }
}